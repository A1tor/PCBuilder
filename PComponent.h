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
	PComponent(String^ modelName, Image^ image, Dictionary<String^, String^>^& parameters)
		: modelName(modelName), image(image), parameters(parameters)
	{	}

	String^ getModelName() {
		return this->modelName;
	}

	String^ getComponentType() {
		return this->componentType;
	}

	Image^ getImage() {
		return this->image;
	}
};

