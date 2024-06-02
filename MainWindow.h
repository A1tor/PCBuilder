#pragma once
#include "PComponent.h"

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
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
			this->SuspendLayout();
			// 
			// componentTypeView
			// 
			this->componentTypeView->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->componentTypeView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
			this->componentTypeView->HideSelection = false;
			this->componentTypeView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(8) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8
			});
			this->componentTypeView->LargeImageList = this->componentIconList;
			this->componentTypeView->Location = System::Drawing::Point(12, 12);
			this->componentTypeView->MultiSelect = false;
			this->componentTypeView->Name = L"componentTypeView";
			this->componentTypeView->Size = System::Drawing::Size(526, 480);
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
			this->componentList->Location = System::Drawing::Point(544, 12);
			this->componentList->Name = L"componentList";
			this->componentList->Size = System::Drawing::Size(526, 480);
			this->componentList->SmallImageList = this->componentImageList;
			this->componentList->TabIndex = 1;
			this->componentList->UseCompatibleStateImageBehavior = false;
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
			this->ClientSize = System::Drawing::Size(1081, 504);
			this->Controls->Add(this->componentList);
			this->Controls->Add(this->componentTypeView);
			this->Name = L"MainWindow";
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
		selectedItem->Text;

		Dictionary<String^, String^>^ parameters = gcnew Dictionary<String^, String^>();
		PComponent^ cpu = gcnew PComponent("Ryzen rx3600", "Процессор", Image::FromStream(gcnew System::IO::MemoryStream(webClient->DownloadData("https://content.onliner.by/catalog/device/main/c65a08f386c4dbc9d402f629db0a9ff1.jpeg"))), parameters);
		
		List<PComponent^>^ componentList = gcnew List<PComponent^> ();
		componentList->Add(cpu);

		for each (PComponent ^ component in componentList)
		{
			this->componentImageList->Images->Add(component->getImage());
			ListViewItem^ listViewItem = gcnew ListViewItem(gcnew cli::array< System::String^  >(1) { component->getModelName() },
				this->componentImageList->Images->Count - 1, System::Drawing::Color::Black, System::Drawing::Color::Empty, nullptr);
			this->componentList->Items->Add(listViewItem);
		}
	}
};
}
