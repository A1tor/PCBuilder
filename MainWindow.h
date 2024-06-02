#pragma once
#include "PComponent.h"
#include "PComponentFactory.h"

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
	/// ������ ��� MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ componentTypeView;
	private: System::Windows::Forms::ImageList^ componentIconList;
	private: System::Net::WebClient^ webClient = gcnew System::Net::WebClient();
	protected:


	private: System::Windows::Forms::ListView^ componentList;
	private: System::Windows::Forms::ImageList^ componentImageList;




	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ListViewItem^ listViewItem9 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"���������" },
				1, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem10 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"����������� �����" },
				5, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem11 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"����������" },
				3, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem12 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"����������� ������" },
				7, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem13 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"������������ ����������" },
				4, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem14 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"������������ ������" },
				2, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem15 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"������" },
				0, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::Windows::Forms::ListViewItem^ listViewItem16 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) { L"���� �������" },
				6, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr));
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->componentTypeView = (gcnew System::Windows::Forms::ListView());
			this->componentIconList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->componentList = (gcnew System::Windows::Forms::ListView());
			this->componentImageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->SuspendLayout();
			// 
			// componentTypeView
			// 
			this->componentTypeView->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->componentTypeView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->componentTypeView->HideSelection = false;
			listViewItem9->Tag = L"cpu";
			listViewItem10->Tag = L"mb";
			listViewItem11->Tag = L"gpu";
			listViewItem12->Tag = L"ram";
			listViewItem13->Tag = L"hdd";
			listViewItem14->Tag = L"fan";
			listViewItem15->Tag = L"cha";
			listViewItem16->Tag = L"ps";
			this->componentTypeView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(8) {
				listViewItem9, listViewItem10,
					listViewItem11, listViewItem12, listViewItem13, listViewItem14, listViewItem15, listViewItem16
			});
			this->componentTypeView->LargeImageList = this->componentIconList;
			this->componentTypeView->Location = System::Drawing::Point(20, 20);
			this->componentTypeView->Margin = System::Windows::Forms::Padding(0);
			this->componentTypeView->MultiSelect = false;
			this->componentTypeView->Name = L"componentTypeView";
			this->componentTypeView->Size = System::Drawing::Size(700, 600);
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
			this->componentList->Location = System::Drawing::Point(740, 20);
			this->componentList->Margin = System::Windows::Forms::Padding(0);
			this->componentList->Name = L"componentList";
			this->componentList->Size = System::Drawing::Size(700, 600);
			this->componentList->SmallImageList = this->componentImageList;
			this->componentList->TabIndex = 1;
			this->componentList->UseCompatibleStateImageBehavior = false;
			this->componentList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::componentList_SelectedIndexChanged);
			// 
			// componentImageList
			// 
			this->componentImageList->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->componentImageList->ImageSize = System::Drawing::Size(100, 100);
			this->componentImageList->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1458, 824);
			this->Controls->Add(this->componentList);
			this->Controls->Add(this->componentTypeView);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"-";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void componentTypeView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		this->componentImageList->Images->Clear();
		this->componentList->Items->Clear();

		ListViewItem^ selectedItem;
		for each (ListViewItem ^ selectedItemFromList in this->componentTypeView->SelectedItems) {
			selectedItem = selectedItemFromList;
		}
		if (selectedItem == nullptr)
			return;

		PComponentFactory^ components = gcnew PComponentFactory(".\\resources\\" + selectedItem->Tag->ToString() + "\\", webClient);

		for each (PComponent ^ component in components->getComponentList())
		{

			this->componentImageList->Images->Add(component->getImage());
			ListViewItem^ listViewItem = gcnew ListViewItem(gcnew cli::array< System::String^  >(1) { component->getModelName() },
				this->componentImageList->Images->Count - 1, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr);
			this->componentList->Items->Add(listViewItem);
		}
	}

	private: System::Void componentList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		ListViewItem^ selectedItem;
		for each (ListViewItem ^ selectedItemFromList in this->componentTypeView->SelectedItems) {
			selectedItem = selectedItemFromList;
		}
		if (selectedItem == nullptr)
			return;
	}
};
}
