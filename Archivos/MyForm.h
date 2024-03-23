#pragma once
#include <iostream>
#include <fstream>
#include "msclr/marshal_cppstd.h"

namespace Archivos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

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
	private: System::Windows::Forms::TextBox^ entradaTexto;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnEnviar;

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
			this->entradaTexto = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// entradaTexto
			// 
			this->entradaTexto->Location = System::Drawing::Point(119, 93);
			this->entradaTexto->Name = L"entradaTexto";
			this->entradaTexto->Size = System::Drawing::Size(241, 20);
			this->entradaTexto->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(116, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Introduce un texto";
			// 
			// btnEnviar
			// 
			this->btnEnviar->Location = System::Drawing::Point(203, 149);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(75, 23);
			this->btnEnviar->TabIndex = 2;
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &MyForm::btnEnviar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(519, 335);
			this->Controls->Add(this->btnEnviar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->entradaTexto);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		ofstream Archivo("archivo.txt", ios_base::app); //ios_base::app para agregar en vez de sobreescribir

		string paraEscribir = msclr::interop::marshal_as<std::string>(entradaTexto->Text);

		// Write to the file
		Archivo << paraEscribir << "\n";

		// Close the file
		Archivo.close();
	}
	};
}
