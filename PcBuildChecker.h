#pragma once

#include "PComponent.h"
#include "BuildForm.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ref class PcBuildChecker
{
private:
    static String^ CPU = "cpu";
    static String^ GPU = "gpu";
    static String^ MB = "mb";
    static String^ PS = "ps";
    static String^ RAM = "ram";
    static String^ FAN = "fan";
    static String^ CHA = "cha";
    static String^ HDD = "hdd";   
    String^ username;
    List<String^>^ typeArray = gcnew List<String^>();
    Dictionary<String^, PComponent^>^ components = gcnew Dictionary<String^, PComponent^>();
public:

    PcBuildChecker() {
        typeArray->Add(CPU);
        typeArray->Add(GPU);
        typeArray->Add(MB);
        typeArray->Add(PS);
        typeArray->Add(FAN);
        typeArray->Add(CHA);
        typeArray->Add(RAM);
        typeArray->Add(HDD);
    }

    void saveBuild() {
        if (username == nullptr)
            return;
        try
        {
            StreamWriter^ writer = gcnew StreamWriter(String::Concat(".\\resources\\profileConfigs\\", username, ".txt"));
            writer->WriteLine(parse());
            writer->Close();
        }
        catch (Exception^ e) {
            throw e;
        }
    }

    String^ parse() {
        String^ returnString = "";
        for each (auto name in components)
            returnString = String::Concat(returnString, name.Key, "^", name.Value->getModelName(), "^");
        return returnString->Substring(0, returnString->Length-1);
    }

    void setUsername(String^ username) {
        this->username = username;
    }

    void setComponent(String^ componentType, PComponent^ componentName) {
        if (components->ContainsKey(componentType))
            components->Remove(componentType);
        components->Add(componentType, componentName);
    }

    void tryOpenBuild() {
        bool isParameterValue;
        try
        {
            StreamReader^ reader = File::OpenText(String::Concat(".\\resources\\profileConfigs\\", username, ".txt"));
            String^ line;
            String^ parameterName;
            List<String^>^ list = gcnew List<String^>();
            PCBuilder::BuildForm^ buildForm = gcnew PCBuilder::BuildForm();
            buildForm->Show();
            while ((line = reader->ReadLine()) != nullptr)
            {
                isParameterValue = false;
                for each (auto data in line->Split('^'))
                {
                    if (isParameterValue == true)
                        list->Add(parameterName + " " + data);
                    else
                        parameterName = data;
                    isParameterValue = !isParameterValue;
                }
            }
            buildForm->setList(list);
            reader->Close();
        }
        catch (Exception^ e){}
    }

    List<String^>^ checkConfiguration() {
        List<String^>^ errorList = gcnew List<String^>();
        String^ paramVal;
        for each (auto type in typeArray)
            if (!components->ContainsKey(type))
                errorList->Add(String::Concat("No component ", type));
        for each (auto component in components) {
            if (component.Key->Equals(CPU))
            {
                auto model = component.Value;
                getError(errorList, model, MB, "socket", "Bad CPU socket {0}");
                getError(errorList, model, RAM, "memoryType", "Bad RAM type {0}");
                getError(errorList, model, RAM, "maxMemoryFrequency", "Bad RAM frequency with CPU {0} and RAM {1}");
                getCompareError(errorList, model, FAN, "tpd", "Bad TPD CPU {0} and FAN {1}");
            }
            else if (component.Key->Equals(CHA)) {
                auto model = component.Value;
                getCompareError(errorList, model, GPU, "mbForm", "Bad tpd with CPU {0} and FAN {1}");
                getCompareError(errorList, model, GPU, "gpuLength", "Bad gpulength with CHA {0} and GPU {1}");
            }
        }
        return errorList;
    }
private:
    void getError(List<String^>^ errorList, PComponent^ model, String^ comparingType, String^ comparingParam, String^ errorMessage) {
        try {
            String^ paramVal = model->getParameterValue(comparingParam);
            String^ compareVal = getPComponent(comparingType)->getParameterValue(comparingParam);
            if (!paramVal->Equals(compareVal))
                errorList->Add(String::Format(errorMessage, paramVal, compareVal));
        }
        catch (Exception^ e) {}
    }
    void getCompareError(List<String^>^ errorList, PComponent^ model, String^ comparingType, String^ comparingParam, String^ errorMessage) {
        try {
            String^ paramVal = model->getParameterValue(comparingParam);
            String^ compareVal = getPComponent(comparingType)->getParameterValue(comparingParam);
            if (String::Compare(paramVal, compareVal) < 0)
                errorList->Add(String::Format(errorMessage, paramVal, compareVal));
        }
        catch (Exception^ e) {}
    }
    PComponent^ getPComponent(String^ type) {
        for each (auto component in components)
            if (component.Key->Equals(type))
                return component.Value;
        throw gcnew Exception("No such component");
    }
};

