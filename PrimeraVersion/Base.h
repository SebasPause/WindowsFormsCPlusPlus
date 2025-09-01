#pragma once

#include <windows.h>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <string>
#include <vector>
#include "PrimeraVersionLib.h"

namespace PrimeraVersion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Resumen de Base
	/// </summary>
	public ref class Base : public System::Windows::Forms::Form
	{
	public:
		Base(void)
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
		~Base()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Label^ lblStatus;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(391, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Comprimir";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Base::comprimir_Click);
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Location = System::Drawing::Point(391, 188);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(68, 13);
			this->lblStatus->TabIndex = 1;
			this->lblStatus->Text = L"Estado: Listo";
			// 
			// Base
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(874, 385);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->button1);
			this->Name = L"Base";
			this->Text = L"Base";
			this->Load += gcnew System::EventHandler(this, &Base::Base_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void comprimir_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Title = "Seleccionar archivos para comprimir";
		openFileDialog->Multiselect = true; // Permitir la selección múltiple

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			array<String^>^ fileNames = openFileDialog->FileNames;

			for each (String ^ fileName in fileNames) {
				String^ compressedFileName = quitarExtension(fileName) + ".rar";

				// Aquí es donde añadirás la lógica para comprimir el archivo.
				// Puedes utilizar una función como `CompressFile` que definimos antes,
				// o implementar la lógica directamente aquí.
				bool success = PrimeraVersionLib::CompressFile(marshal_as<std::string>(fileName).c_str(), marshal_as<std::string>(compressedFileName).c_str());

				if (success) {
					MessageBox::Show("Archivo comprimido exitosamente: " + compressedFileName, "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Error al comprimir el archivo: " + fileName, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}	

	String^ quitarExtension(String^ nombreArchivo) {
		// Convertir String^ a std::string
		std::string cppString = msclr::interop::marshal_as<std::string>(nombreArchivo);

		// Buscar la última aparición de un punto
		size_t punto = cppString.find_last_of('.');

		// Si no hay punto, retornar el nombre completo (sin cambiar nada)
		if (punto == std::string::npos) {
			return nombreArchivo;  // Retorna el String^ original si no hay punto
		}

		// Retornar la subcadena desde el inicio hasta justo antes del punto
		std::string sinExtension = cppString.substr(0, punto);

		// Convertir de std::string de vuelta a String^
		return msclr::interop::marshal_as<String^>(sinExtension);
	}

	private: System::Void Base_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
