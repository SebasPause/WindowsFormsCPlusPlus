#include "Alumnos.h"
#pragma once

namespace ExamenCPlusPlus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Resumen de Contenido
	/// </summary>
	public ref class Contenido : public System::Windows::Forms::Form
	{
	public:
		Contenido(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Contenido()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Edad;

	protected:



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
			this->Nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Edad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Nombre,
					this->Edad
			});
			this->dataGridView1->Location = System::Drawing::Point(115, 91);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(645, 260);
			this->dataGridView1->TabIndex = 0;
			// 
			// Nombre
			// 
			this->Nombre->HeaderText = L"Nombre";
			this->Nombre->Name = L"Nombre";
			this->Nombre->ReadOnly = true;
			this->Nombre->Width = 500;
			// 
			// Edad
			// 
			this->Edad->HeaderText = L"Edad";
			this->Edad->Name = L"Edad";
			this->Edad->ReadOnly = true;
			// 
			// Contenido
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 505);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Contenido";
			this->Text = L"Contenido";
			this->Load += gcnew System::EventHandler(this, &Contenido::Contenido_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	//Funcion que carga datos en el grid view al cargar la ventana
	private: System::Void Contenido_Load(System::Object^ sender, System::EventArgs^ e) {

		//Array del objeto Alumnos que se inicializa con tres datos
		array<Alumnos^>^ alumnosArray = gcnew array<Alumnos^>
		{
			gcnew Alumnos{ "Juan", 25 },
			gcnew Alumnos{ "María", 30 },
			gcnew Alumnos{ "Carlos", 40 }
		};

		//Funcion for each para establecer cada objeto de Alumnos en una fila del gridView
		int i = 0;
		for each (Alumnos ^ alumno in alumnosArray) {
			dataGridView1->Rows->Add(); //Se añade la fila

			dataGridView1->Rows[i]->Cells[0]->Value = alumno->Nombre; //En la columna nombre se le agrega el valor del objeto
			dataGridView1->Rows[i]->Cells[1]->Value = alumno->Edad; //En la columna edad se le agrega el valor del objeto
			i++;
		}

	}
};
}
