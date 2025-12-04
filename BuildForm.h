#pragma once

namespace PCBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ BuildForm
	/// </summary>
	public ref class BuildForm : public System::Windows::Forms::Form
	{
	public:
		BuildForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~BuildForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ elementNameListBox;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->elementNameListBox = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// elementNameListBox
			// 
			this->elementNameListBox->FormattingEnabled = true;
			this->elementNameListBox->Location = System::Drawing::Point(8, 7);
			this->elementNameListBox->Name = L"elementNameListBox";
			this->elementNameListBox->Size = System::Drawing::Size(265, 225);
			this->elementNameListBox->TabIndex = 0;
			this->elementNameListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &BuildForm::elementNameListBox_SelectedIndexChanged);
			// 
			// BuildForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(278, 244);
			this->Controls->Add(this->elementNameListBox);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(300, 300);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"BuildForm";
			this->Text = L"BuildForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void setList(List<String^>^ list) {
		elementNameListBox->Items->Clear();
		for each (auto str in list)
			elementNameListBox->Items->Add(str);
	}
	private: System::Void elementNameListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
