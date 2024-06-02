#pragma once
#include "PComponent.h"

using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class PComponentFactory
{
private:
    Char delimiter = Char('^');
    String^ generalFilePath;
    System::Net::WebClient^ webClient;
	List<PComponent^>^ componentList = gcnew List<PComponent^>();
public:

	PComponentFactory(String^ dataFilePath, System::Net::WebClient^ webClient)
	{
        this->generalFilePath = dataFilePath;
        this->webClient = webClient;
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

    void addFileToComponentList(String^ dataString) {
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
        //Image::FromStream(gcnew System::IO::MemoryStream(webClient->
        //DownloadData("https://content.onliner.by/catalog/device/main/c65a08f386c4dbc9d402f629db0a9ff1.jpeg")))
        PComponent^ a = gcnew PComponent(componentName,
            Image::FromFile(String::Concat(generalFilePath, componentName, ".jpeg")),
            componentParameters);
        componentList->Add(a);
    }

    List<PComponent^>^ getComponentList(){
        return this->componentList;
    }
};

