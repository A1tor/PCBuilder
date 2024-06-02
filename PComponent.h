#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class PComponent
{
private:
	String^ modelName;
	String^ componentType;
	Image^ image;
	Dictionary<String^, String^>^ parameters;

public:
	PComponent(String^ modelName, String^ componentType, Image^ image, Dictionary<String^, String^>^& parameters)
		: modelName(modelName), componentType(componentType), image(image), parameters(parameters)
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

