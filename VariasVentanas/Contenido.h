#pragma once

namespace VariasVentanas {

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
		String^ usuario;
	private: System::Windows::Forms::Label^ label1;
	public:
		String^ contrasenia;
		Contenido(String^ usuarioRecibido, String^ contraseniaRecibida)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			usuario = usuarioRecibido;
			contrasenia = contraseniaRecibida;
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
			this->label1->Location = System::Drawing::Point(82, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 0;
			// 
			// Contenido
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(371, 275);
			this->Controls->Add(this->label1);
			this->Name = L"Contenido";
			this->Text = L"Contenido";
			this->Load += gcnew System::EventHandler(this, &Contenido::Contenido_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Contenido_Load(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "Bienvenid@ " + usuario + " con contraseña: " + contrasenia;
	}
	};
}
