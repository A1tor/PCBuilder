#pragma once
#include "PComponent.h"

using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class PComponentFactory
{
private:
    static const Char delimiter = Char('^');
    static String^ JPEG = ".jpeg";
    String^ generalFilePath;
	List<PComponent^>^ componentList = gcnew List<PComponent^>();
public:
	PComponentFactory(String^ dataFilePath, System::Net::WebClient^ webClient)
	{
        this->generalFilePath = dataFilePath;
        try
        {
            StreamReader^ reader = File::OpenText(String::Concat(dataFilePath, "data.txt"));
            String^ line;
            while ((line = reader->ReadLine()) != nullptr)
            {
                addFileToComponentList(line);
            }
            reader->Close();
        }
        catch (Exception^ e)
        {
            throw e;
        }
	}

    PComponentFactory(String^ dataFilePath)
    {
        this->generalFilePath = dataFilePath;
        try
        {
            StreamReader^ reader = File::OpenText(String::Concat(dataFilePath, "data.txt"));
            String^ line;
            while ((line = reader->ReadLine()) != nullptr)
            {
                addFileToComponentList(line);
            }
            reader->Close();
        }
        catch (Exception^ e)
        {
            throw e;
        }
    }

    List<PComponent^>^ getComponentList(){
        return this->componentList;
    }
private:
    void inline addFileToComponentList(String^ dataString) {
        bool isParameterValue = false;
        int nameEndIndex = dataString->IndexOf(delimiter);
        String^ componentName = dataString->Substring(0, nameEndIndex);
        String^ parameterName;
        Dictionary<String^, String^>^ componentParameters = gcnew Dictionary<String^, String^>;

        for each (String ^ data in dataString->Substring(nameEndIndex + 1)->Split(delimiter)) {
            if (isParameterValue == true)
                componentParameters->Add(parameterName, data);
            else
                parameterName = data;
            isParameterValue = !isParameterValue;
        }

        Image^ componentImage;
        try {
            componentImage = Image::FromFile(String::Concat(generalFilePath, componentName, JPEG));
        }
        catch (Exception^ e) {}
        PComponent^ newComp = gcnew PComponent(componentName,
            componentImage,
            componentParameters);

        componentList->Add(newComp);
    }
};

