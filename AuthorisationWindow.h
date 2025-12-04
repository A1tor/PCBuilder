#pragma once

#include "PcbUser.h"

namespace PCBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AuthorisationWindow
	/// </summary>
	public ref class AuthorisationWindow : public System::Windows::Forms::Form
	{
	public: PcbUser^ currentUser;
	public:
		AuthorisationWindow(List<PcbUser^>^ userArray, PcbUser^ currentUser)
		{
			this->userArray = userArray;
			this->currentUser = currentUser;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AuthorisationWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: List<PcbUser^>^ userArray;

	private: System::Windows::Forms::Button^ loginButton;
	private: System::Windows::Forms::TextBox^ usernameTextBox;
	private: System::Windows::Forms::TextBox^ passwordTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ errorMessageTextBox;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->errorMessageTextBox = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// loginButton
			// 
			this->loginButton->Location = System::Drawing::Point(106, 300);
			this->loginButton->Margin = System::Windows::Forms::Padding(0);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(300, 50);
			this->loginButton->TabIndex = 0;
			this->loginButton->Text = L"Войти";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &AuthorisationWindow::loginButton_Click);
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->Location = System::Drawing::Point(106, 112);
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(300, 20);
			this->usernameTextBox->TabIndex = 1;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(106, 169);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(300, 20);
			this->passwordTextBox->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(106, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Имя пользователя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(106, 153);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Пароль";
			// 
			// errorMessageTextBox
			// 
			this->errorMessageTextBox->AutoSize = true;
			this->errorMessageTextBox->Location = System::Drawing::Point(106, 196);
			this->errorMessageTextBox->Name = L"errorMessageTextBox";
			this->errorMessageTextBox->Size = System::Drawing::Size(0, 13);
			this->errorMessageTextBox->TabIndex = 5;
			// 
			// AuthorisationWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 456);
			this->Controls->Add(this->errorMessageTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->loginButton);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(512, 512);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(512, 512);
			this->Name = L"AuthorisationWindow";
			this->Text = L"AuthorisationWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (usernameTextBox->Text->Length == 0 || passwordTextBox->Text->Length == 0)
			errorMessageTextBox->Text = "Пароль или имя пользователя пусты";
		else {
			int userIndex = PcbUser::getUserWithCredentials(userArray, usernameTextBox->Text, 
				passwordTextBox->Text->GetHashCode().ToString());
			if (userIndex == -1)
				errorMessageTextBox->Text = "Введены неправильный пароль или имя пользователя";
			else {
				currentUser->copyUser(userArray[userIndex]);
				this->Close();
			}
		}
	}
	};
}
