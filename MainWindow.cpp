#include "pch.h"
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	PCBuilder::MainWindow mainWindow;
	Application::Run(% mainWindow);
}