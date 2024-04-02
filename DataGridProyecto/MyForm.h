#include "Persona.h"

#pragma once

namespace DataGridProyecto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	public:
		ref class Data
		{
		public:
			int edad;
			String^ nombre;
			String^ email;
			String^ curso;

			Data(int edad, String^ nombre, String^ email, String^ curso) {
				this->edad = edad;
				this->nombre = nombre;
				this->email = email;
				this->curso = curso;
			}

		};

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ email;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ edad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ curso;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->curso = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->nombre,
					this->email, this->edad, this->curso
			});
			this->dataGridView1->Location = System::Drawing::Point(40, 48);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(560, 218);
			this->dataGridView1->TabIndex = 0;
			// 
			// nombre
			// 
			this->nombre->HeaderText = L"Nombre";
			this->nombre->Name = L"nombre";
			// 
			// email
			// 
			this->email->HeaderText = L"Email";
			this->email->Name = L"email";
			// 
			// edad
			// 
			this->edad->HeaderText = L"Edad";
			this->edad->Name = L"edad";
			// 
			// curso
			// 
			this->curso->HeaderText = L"Curso";
			this->curso->Name = L"curso";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(292, 327);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 385);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		array<Persona^>^ datos = gcnew array<Persona^>{
			gcnew Persona(27, "Sebastian", "primercorreo@gmail.com", "C++"),
				gcnew Persona(27, "Melissa", "segundocorreo@gmail.com", "Java"),
				gcnew Persona(23, "Oxel", "tercercorreo@gmail.com", "C#"),
				gcnew Persona(24, "Diana", "cuartocorreo@gmail.com", "Python"),
		};

		int i = 0;
		for each (Persona ^ dato in datos) {
			dataGridView1->Rows->Add();

			dataGridView1->Rows[i]->Cells[0]->Value = dato->Nombre;
			dataGridView1->Rows[i]->Cells[1]->Value = dato->Email;
			dataGridView1->Rows[i]->Cells[2]->Value = dato->Edad;
			dataGridView1->Rows[i]->Cells[3]->Value = dato->Curso;
			i++;
		}
	}
};
}
