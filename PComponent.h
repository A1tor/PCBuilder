#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class PComponent
{
private:
	String^ modelName;
	String^ componentType;
	Image^ image;
	Dictionary<String^, String^>^ parameters;

public:
	PComponent(String^ modelName, Image^ image, Dictionary<String^, String^>^ parameters)
		: modelName(modelName), image(image), parameters(parameters)
	{	}

	String^ getModelName() {
		return this->modelName;
	}

	String^ getComponentType() {
		return this->componentType;
	}

	List<String^>^ getParametersString() {
		List<String^>^ parameterStringArray = gcnew List<String^>();
		for each (auto parameter in parameters)
			parameterStringArray->Add(String::Concat(parameter.Key, " ", parameter.Value));
		return parameterStringArray;
	}

	String^ getParameterValue(String^ key) {
		for each (auto parameter in parameters)
			if (parameter.Key->Equals(key))
				return parameter.Value;
	}

	String^ getParameterValue(int index) {
		for each (auto parameter in parameters)
		{
			if (index == 0)
				return parameter.Value;
			index--;
		}
	}

	Image^ getImage() {
		return this->image;
	}
};

