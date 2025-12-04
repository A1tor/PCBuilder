#pragma once
#include "PComponent.h"
#include "PComponentFactory.h"
#include "AuthorisationWindow.h"
#include "AdministratorForm.h"
#include "PcbUser.h"
#include "PcBuildChecker.h"

namespace PCBuilder {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private: // Константы для ликвидации магических чисел
		static const Char DELIMITER = Char('\\');
		static String^ PNG = ".png";
		static String^ LOG_IN = "Войти"; 
		static String^ LOG_OUT = "Выйти";
		static String^ UPDATE = "Обновить";
		static String^ RESOURCES = ".\\resources\\";
		static String^ COMPONENTS = "componentIcons\\";
		static String^ USER_NOT_FOUND = "Пользователь не определён";
		static String^ ADMIN_STATUS = "a";
	private: System::Windows::Forms::ComboBox^ sortComboBox;
	private: System::Windows::Forms::ListBox^ errorListBox;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::ListBox^ parameterListBox;



	public:
		MainWindow(void)
		{
			InitializeComponent();
			this->loginButton->Text = LOG_IN;
			this->userArray = PcbUser::getUserArray();
			setErrors();
		}

	protected:
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}


	private: 
		AuthorisationWindow^ authorisationWindow;
		PcbUser^ currentUser;
		PcBuildChecker^ currentBuilder = gcnew PcBuildChecker();
		List<PcbUser^>^ userArray = gcnew List<PcbUser^>();
		List<PComponent^>^ sortComponentList;

	private: System::Windows::Forms::ListView^ componentTypeView;
	private: System::Windows::Forms::ImageList^ componentIconList;
	private: System::Windows::Forms::ListView^ componentList;
	private: System::Windows::Forms::ImageList^ componentImageList;
	private: System::Windows::Forms::Button^ loginButton;
	private: System::Windows::Forms::Label^ userLabel;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) 
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Процессор" },
				1, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Материнская плата" },
				5, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Видеокарта" },
				3, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Оперативная память" },
				7, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Запоминающее устройство" },
				4, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem6 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Процессорный куллер" },
				2, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem7 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Корпус" },
				0, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem8 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"Блок питания" },
				6, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->componentTypeView = (gcnew System::Windows::Forms::ListView());
			this->componentIconList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->componentList = (gcnew System::Windows::Forms::ListView());
			this->componentImageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->userLabel = (gcnew System::Windows::Forms::Label());
			this->sortComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->parameterListBox = (gcnew System::Windows::Forms::ListBox());
			this->errorListBox = (gcnew System::Windows::Forms::ListBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// componentTypeView
			// 
			this->componentTypeView->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->componentTypeView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->componentTypeView->HideSelection = false;
			listViewItem1->Tag = L"cpu";
			listViewItem2->Tag = L"mb";
			listViewItem3->Tag = L"gpu";
			listViewItem4->Tag = L"ram";
			listViewItem5->Tag = L"hdd";
			listViewItem6->Tag = L"fan";
			listViewItem7->Tag = L"cha";
			listViewItem8->Tag = L"ps";
			this->componentTypeView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(8) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8
			});
			this->componentTypeView->LargeImageList = this->componentIconList;
			this->componentTypeView->Location = System::Drawing::Point(13, 64);
			this->componentTypeView->Margin = System::Windows::Forms::Padding(0);
			this->componentTypeView->MultiSelect = false;
			this->componentTypeView->Name = L"componentTypeView";
			this->componentTypeView->Size = System::Drawing::Size(468, 391);
			this->componentTypeView->SmallImageList = this->componentIconList;
			this->componentTypeView->TabIndex = 0;
			this->componentTypeView->UseCompatibleStateImageBehavior = false;
			this->componentTypeView->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::componentTypeView_SelectedIndexChanged);
			// 
			// componentIconList
			// 
			this->componentIconList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"componentIconList.ImageStream")));
			this->componentIconList->TransparentColor = System::Drawing::Color::Transparent;
			this->componentIconList->Images->SetKeyName(0, L"chassis.png");
			this->componentIconList->Images->SetKeyName(1, L"cpu.png");
			this->componentIconList->Images->SetKeyName(2, L"cpuFan.png");
			this->componentIconList->Images->SetKeyName(3, L"gpu.png");
			this->componentIconList->Images->SetKeyName(4, L"hdd.png");
			this->componentIconList->Images->SetKeyName(5, L"motherboard.png");
			this->componentIconList->Images->SetKeyName(6, L"powerSupply.png");
			this->componentIconList->Images->SetKeyName(7, L"ram.png");
			// 
			// componentList
			// 
			this->componentList->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->componentList->HideSelection = false;
			this->componentList->LargeImageList = this->componentImageList;
			this->componentList->Location = System::Drawing::Point(493, 64);
			this->componentList->Margin = System::Windows::Forms::Padding(0);
			this->componentList->Name = L"componentList";
			this->componentList->Size = System::Drawing::Size(468, 391);
			this->componentList->SmallImageList = this->componentImageList;
			this->componentList->TabIndex = 1;
			this->componentList->UseCompatibleStateImageBehavior = false;
			this->componentList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::componentList_SelectedIndexChanged);
			// 
			// componentImageList
			// 
			this->componentImageList->ColorDepth = System::Windows::Forms::ColorDepth::Depth16Bit;
			this->componentImageList->ImageSize = System::Drawing::Size(100, 100);
			this->componentImageList->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// loginButton
			// 
			this->loginButton->Location = System::Drawing::Point(870, 12);
			this->loginButton->Margin = System::Windows::Forms::Padding(0);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(90, 40);
			this->loginButton->TabIndex = 2;
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &MainWindow::loginButton_Click);
			// 
			// userLabel
			// 
			this->userLabel->AutoSize = true;
			this->userLabel->Location = System::Drawing::Point(707, 26);
			this->userLabel->Margin = System::Windows::Forms::Padding(0);
			this->userLabel->Name = L"userLabel";
			this->userLabel->Size = System::Drawing::Size(0, 13);
			this->userLabel->TabIndex = 3;
			// 
			// sortComboBox
			// 
			this->sortComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->sortComboBox->FormattingEnabled = true;
			this->sortComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"По алфавиту", L"По первому параметру", L"По второму параметру" });
			this->sortComboBox->Location = System::Drawing::Point(13, 26);
			this->sortComboBox->Name = L"sortComboBox";
			this->sortComboBox->Size = System::Drawing::Size(200, 21);
			this->sortComboBox->TabIndex = 4;
			this->sortComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::sortComboBox_SelectedIndexChanged);
			// 
			// parameterListBox
			// 
			this->parameterListBox->FormattingEnabled = true;
			this->parameterListBox->Location = System::Drawing::Point(493, 459);
			this->parameterListBox->Name = L"parameterListBox";
			this->parameterListBox->Size = System::Drawing::Size(467, 56);
			this->parameterListBox->TabIndex = 5;
			// 
			// errorListBox
			// 
			this->errorListBox->FormattingEnabled = true;
			this->errorListBox->Location = System::Drawing::Point(12, 459);
			this->errorListBox->Name = L"errorListBox";
			this->errorListBox->Size = System::Drawing::Size(468, 56);
			this->errorListBox->TabIndex = 6;
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(227, 15);
			this->saveButton->Margin = System::Windows::Forms::Padding(0);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(90, 40);
			this->saveButton->TabIndex = 7;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MainWindow::saveButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(972, 536);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->errorListBox);
			this->Controls->Add(this->parameterListBox);
			this->Controls->Add(this->sortComboBox);
			this->Controls->Add(this->userLabel);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->componentList);
			this->Controls->Add(this->componentTypeView);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(994, 592);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(994, 592);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"-";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void componentTypeView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { //Нажатие на кнопку
		fillComponentList();
	}
	private: System::Void fillComponentList() {
		this->componentImageList->Images->Clear();
		this->componentList->Items->Clear();

		ListViewItem^ selectedItem;
		for each (ListViewItem ^ selectedItemFromList in this->componentTypeView->SelectedItems) {
			selectedItem = selectedItemFromList;
		}
		if (selectedItem == nullptr)
			return;

		sortComponentList = (gcnew PComponentFactory(String::Concat(RESOURCES,
			selectedItem->Tag->ToString(), DELIMITER)))->getComponentList();
		sortList(sortComponentList);
		for each (PComponent ^ component in sortComponentList)
		{
			auto img = component->getImage();
			if (img == nullptr)
				img = Image::FromFile(String::Concat(RESOURCES, COMPONENTS, selectedItem->Tag->ToString(), PNG));
			this->componentImageList->Images->Add(img);
			ListViewItem^ listViewItem = gcnew ListViewItem(gcnew cli::array<System::String^>(1) { component->getModelName() },
				this->componentImageList->Images->Count - 1, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr);
			listViewItem->Tag = selectedItem->Tag;
			this->componentList->Items->Add(listViewItem);
		}
	}
	private: System::Void sortList(List<PComponent^>^ sortComponentList) { //Выполнение сортировки
		PComponent^ temp;
		switch (sortComboBox->SelectedIndex)
		{
		case 0: //Сортировка пузырьком
			for (int i = 0; i < sortComponentList->Count - 1; i++)
				for (int j = 0; j < sortComponentList->Count - i - 1; j++)
					if (String::Compare(sortComponentList[j]->getModelName(),
							sortComponentList[j + 1]->getModelName()) < 0) {
						temp = sortComponentList[j];
						sortComponentList[j] = sortComponentList[j + 1];
						sortComponentList[j + 1] = temp;
					}
			break;
		case 1: //Сортировка выбором
			int minIndex;
			for (int i = 0; i < sortComponentList->Count - 1; i++) {
				minIndex = i;
				for (int j = i + 1; j < sortComponentList->Count; j++)
					if (String::Compare(sortComponentList[j]->getParameterValue(0), 
							sortComponentList[minIndex]->getParameterValue(0)) < 0)
						minIndex = j;
				temp = sortComponentList[minIndex];
				sortComponentList[minIndex] = sortComponentList[i];
				sortComponentList[i] = temp;
			}
			break;
		case 2: //Сортировка вставкой
			int index;
			for (int i = 1; i < sortComponentList->Count; i++) {
				temp = sortComponentList[i];
				index = i - 1;
				while (index >= 0 && String::Compare(sortComponentList[index]->getParameterValue(1), 
						temp->getParameterValue(1)) > 0) {
					sortComponentList[index + 1] = sortComponentList[index];
					index--;
				}
				sortComponentList[index + 1] = temp;
			}
			break;
		default:
			break;
		}
	}
	private: System::Void componentList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { //Нажатие на кнопку
		ListViewItem^ selectedItem;
		for each (ListViewItem ^ selectedItemFromList in this->componentList->SelectedItems)
			selectedItem = selectedItemFromList;
		if (selectedItem == nullptr)
			return;
		parameterListBox->Items->Clear();
		for each (auto parameterString in sortComponentList[selectedItem->Index]->getParametersString())
			parameterListBox->Items->Add(parameterString);
		currentBuilder->setComponent(selectedItem->Tag->ToString(), sortComponentList[selectedItem->Index]);
		setErrors();
	}
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) { //Нажатие на кнопку
		if (authorisationWindow == nullptr) {
			currentUser = gcnew PcbUser();
			authorisationWindow = gcnew AuthorisationWindow(userArray, currentUser);
			authorisationWindow->Show();
			loginButton->Text = UPDATE;
			userLabel->Text = USER_NOT_FOUND;
		} else {
			authorisationWindow->~AuthorisationWindow();
			authorisationWindow = nullptr;
			if (currentUser->getName() == nullptr) {
				loginButton->Text = LOG_IN;
				userLabel->Text = USER_NOT_FOUND;
			} else {
				userLabel->Text = currentUser->getName();
				currentBuilder->setUsername(currentUser->getName());
				currentBuilder->tryOpenBuild();
				loginButton->Text = LOG_OUT;
				if (currentUser->getStatus()->Equals(ADMIN_STATUS))
				{
					AdministratorForm^ administratorForm = gcnew AdministratorForm();
					administratorForm->Show();
				}
			}
		}
	}
private: System::Void sortComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	fillComponentList();
}
private: System::Void setErrors() { //Вывод ошибок
	errorListBox->Items->Clear();
	for each (auto error in currentBuilder->checkConfiguration())
		errorListBox->Items->Add(error);
}
private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) { //Нажатие на кнопку
	currentBuilder->saveBuild();
}
};
}
