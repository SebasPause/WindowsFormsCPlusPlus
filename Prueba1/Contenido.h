#pragma once

namespace Prueba1 {

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
		String^ nombreCompleto;
		String^ correo;
		String^ cursos;
		int edad;
		float notaMedia;
	public:
		Contenido(String^ nombreCompleto, String^ correo, String^ cursos, int edad, float notaMedia)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->nombreCompleto = nombreCompleto;
			this->correo = correo;
			this->cursos = cursos;
			this->edad = edad;
			this->notaMedia = notaMedia;
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
	private: System::Windows::Forms::Label^ label1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(61, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 0;
			// 
			// Contenido
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 337);
			this->Controls->Add(this->label1);
			this->Name = L"Contenido";
			this->Text = L"Contenido";
			this->Load += gcnew System::EventHandler(this, &Contenido::Contenido_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Contenido_Load(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "Datos\n" + "Nombre: " + nombreCompleto + 
			"\nCorreo: " + correo +
			"\nEdad: "+edad +
			"\nCursos: " + cursos +
			"\nNota media: "+ notaMedia;
	}
	};
}
