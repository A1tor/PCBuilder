#pragma once

#include "PcbUser.h"
#include "PComponent.h"

namespace PCBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AdministratorForm
	/// </summary>
	public ref class AdministratorForm : public System::Windows::Forms::Form
	{
	public:
		AdministratorForm(void)
		{
			InitializeComponent();
			updateUserList();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AdministratorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ usersListBox;

	private: System::Windows::Forms::Label^ elementTypeLabel;
	private: System::Windows::Forms::Label^ elementNameLabel;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::TextBox^ specsTextBox;
	private: System::Windows::Forms::TextBox^ nameTextBox;

	private: 
		List<PComponent^>^ componentList;
		List<PcbUser^>^ userList;
	private: System::Windows::Forms::Button^ saveButton;

	private: System::Windows::Forms::Button^ deleteButton;

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
			this->usersListBox = (gcnew System::Windows::Forms::ListBox());
			this->elementTypeLabel = (gcnew System::Windows::Forms::Label());
			this->elementNameLabel = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->specsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// usersListBox
			// 
			this->usersListBox->FormattingEnabled = true;
			this->usersListBox->Location = System::Drawing::Point(13, 13);
			this->usersListBox->Margin = System::Windows::Forms::Padding(0);
			this->usersListBox->Name = L"usersListBox";
			this->usersListBox->Size = System::Drawing::Size(500, 381);
			this->usersListBox->TabIndex = 0;
			this->usersListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AdministratorForm::usersListBox_SelectedIndexChanged);
			// 
			// elementTypeLabel
			// 
			this->elementTypeLabel->AutoSize = true;
			this->elementTypeLabel->Location = System::Drawing::Point(12, 409);
			this->elementTypeLabel->Name = L"elementTypeLabel";
			this->elementTypeLabel->Size = System::Drawing::Size(29, 13);
			this->elementTypeLabel->TabIndex = 2;
			this->elementTypeLabel->Text = L"Имя";
			// 
			// elementNameLabel
			// 
			this->elementNameLabel->AutoSize = true;
			this->elementNameLabel->Location = System::Drawing::Point(12, 448);
			this->elementNameLabel->Name = L"elementNameLabel";
			this->elementNameLabel->Size = System::Drawing::Size(65, 13);
			this->elementNameLabel->TabIndex = 3;
			this->elementNameLabel->Text = L"Код записи";
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(12, 490);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(100, 30);
			this->addButton->TabIndex = 4;
			this->addButton->Text = L"Добавить";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &AdministratorForm::addButton_Click);
			// 
			// specsTextBox
			// 
			this->specsTextBox->Location = System::Drawing::Point(12, 464);
			this->specsTextBox->Name = L"specsTextBox";
			this->specsTextBox->Size = System::Drawing::Size(500, 20);
			this->specsTextBox->TabIndex = 5;
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(12, 425);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(500, 20);
			this->nameTextBox->TabIndex = 6;
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(118, 490);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(100, 30);
			this->deleteButton->TabIndex = 7;
			this->deleteButton->Text = L"Удалить";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &AdministratorForm::deleteButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(224, 490);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(100, 30);
			this->saveButton->TabIndex = 8;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &AdministratorForm::saveButton_Click);
			// 
			// AdministratorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 544);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->specsTextBox);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->elementNameLabel);
			this->Controls->Add(this->elementTypeLabel);
			this->Controls->Add(this->usersListBox);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"AdministratorForm";
			this->Text = L"AdministratorForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: System::Void updateUserList() {
	userList = PcbUser::getUserArray();
	usersListBox->Items->Clear();
	for each (auto user in userList)
		usersListBox->Items->Add(user);
}
private: System::Void usersListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	auto selectedItem = usersListBox->SelectedItem;
	if (selectedItem == nullptr)
		return;
	PcbUser^ user = dynamic_cast<PcbUser^>(selectedItem);
	nameTextBox->Text = user->getName();
	specsTextBox->Text = user->getCredentials();
}
private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (specsTextBox->Text == nullptr)
		return;
	try {
		PcbUser::addToList(userList, gcnew PcbUser(specsTextBox->Text));
	}
	catch (Exception^ e) {
		nameTextBox->Text = "Запись уже существует";
	}
}
private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	userList->RemoveAt(PcbUser::getUserWithCredentials(userList, nameTextBox->Text, nullptr));
}
private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	PcbUser::updateUserListFile(userList);
	updateUserList();
}
};
}
