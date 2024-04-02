#pragma once
#include "msclr/marshal_cppstd.h"
#include "Contenido.h"
#include "Alumno.h"

namespace Prueba1 {

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
	private: System::Windows::Forms::TextBox^ notaJava;
	protected:
	private: System::Windows::Forms::TextBox^ notaCSharp;
	private: System::Windows::Forms::TextBox^ notaCPlusPlus;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ labelTitulo;
	private: System::Windows::Forms::TextBox^ entradaCorreo;
	private: System::Windows::Forms::TextBox^ entradaUsuario;
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::TextBox^ entradaEdad;

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
			this->notaJava = (gcnew System::Windows::Forms::TextBox());
			this->notaCSharp = (gcnew System::Windows::Forms::TextBox());
			this->notaCPlusPlus = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->entradaCorreo = (gcnew System::Windows::Forms::TextBox());
			this->entradaUsuario = (gcnew System::Windows::Forms::TextBox());
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->entradaEdad = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// notaJava
			// 
			this->notaJava->Enabled = false;
			this->notaJava->Location = System::Drawing::Point(588, 181);
			this->notaJava->Name = L"notaJava";
			this->notaJava->Size = System::Drawing::Size(100, 20);
			this->notaJava->TabIndex = 29;
			// 
			// notaCSharp
			// 
			this->notaCSharp->Enabled = false;
			this->notaCSharp->Location = System::Drawing::Point(588, 157);
			this->notaCSharp->Name = L"notaCSharp";
			this->notaCSharp->Size = System::Drawing::Size(100, 20);
			this->notaCSharp->TabIndex = 28;
			// 
			// notaCPlusPlus
			// 
			this->notaCPlusPlus->Enabled = false;
			this->notaCPlusPlus->Location = System::Drawing::Point(588, 132);
			this->notaCPlusPlus->Name = L"notaCPlusPlus";
			this->notaCPlusPlus->Size = System::Drawing::Size(100, 20);
			this->notaCPlusPlus->TabIndex = 27;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(482, 181);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 26;
			this->checkBox3->Text = L"Java";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->Click += gcnew System::EventHandler(this, &MyForm::activarNotaJava);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(481, 95);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"¿Qué cursos has estudiado\?";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(482, 158);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(40, 17);
			this->checkBox2->TabIndex = 24;
			this->checkBox2->Text = L"C#";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Click += gcnew System::EventHandler(this, &MyForm::activarNotaCSharp);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(482, 135);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(45, 17);
			this->checkBox1->TabIndex = 23;
			this->checkBox1->Text = L"C++";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &MyForm::activarNotaCPlusPlus);
			// 
			// labelTitulo
			// 
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitulo->Location = System::Drawing::Point(174, 24);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(546, 31);
			this->labelTitulo->TabIndex = 22;
			this->labelTitulo->Text = L"Aplicación WINDOWS FORMS CON C++";
			// 
			// entradaCorreo
			// 
			this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
			this->entradaCorreo->Location = System::Drawing::Point(180, 177);
			this->entradaCorreo->Name = L"entradaCorreo";
			this->entradaCorreo->Size = System::Drawing::Size(228, 20);
			this->entradaCorreo->TabIndex = 21;
			this->entradaCorreo->Text = L"Introduce tu correo: ";
			this->entradaCorreo->Enter += gcnew System::EventHandler(this, &MyForm::entradaCorreo_Enter);
			// 
			// entradaUsuario
			// 
			this->entradaUsuario->ForeColor = System::Drawing::Color::Silver;
			this->entradaUsuario->Location = System::Drawing::Point(180, 139);
			this->entradaUsuario->Name = L"entradaUsuario";
			this->entradaUsuario->Size = System::Drawing::Size(228, 20);
			this->entradaUsuario->TabIndex = 20;
			this->entradaUsuario->Text = L"Introduce tu nombre: ";
			this->entradaUsuario->Enter += gcnew System::EventHandler(this, &MyForm::entradaUsuario_Enter);
			// 
			// btnEnviar
			// 
			this->btnEnviar->Location = System::Drawing::Point(381, 387);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(117, 49);
			this->btnEnviar->TabIndex = 19;
			this->btnEnviar->Tag = L"btnEnviar";
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &MyForm::btnEnviar_Click);
			// 
			// entradaEdad
			// 
			this->entradaEdad->ForeColor = System::Drawing::Color::Silver;
			this->entradaEdad->Location = System::Drawing::Point(180, 214);
			this->entradaEdad->Name = L"entradaEdad";
			this->entradaEdad->Size = System::Drawing::Size(228, 20);
			this->entradaEdad->TabIndex = 22;
			this->entradaEdad->Text = L"Introduce tu edad: ";
			this->entradaEdad->Enter += gcnew System::EventHandler(this, &MyForm::entradaEdad_Enter);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(894, 461);
			this->Controls->Add(this->entradaEdad);
			this->Controls->Add(this->notaJava);
			this->Controls->Add(this->notaCSharp);
			this->Controls->Add(this->notaCPlusPlus);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->entradaCorreo);
			this->Controls->Add(this->entradaUsuario);
			this->Controls->Add(this->btnEnviar);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void reiniciarFormulario() {
		this->entradaUsuario->Text = "Introduce tu nombre: ";
		this->entradaUsuario->ForeColor = System::Drawing::Color::Silver;
		this->entradaCorreo->Text = "Introduce tu correo: ";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
		this->entradaEdad->Text = "Introduce tu edad: ";
		this->entradaEdad->ForeColor = System::Drawing::Color::Silver;
		this->checkBox1->Checked = false;
		this->checkBox2->Checked = false;
		this->checkBox3->Checked = false;
		this->notaCPlusPlus->Enabled = false;
		this->notaCPlusPlus->Text = "";
		this->notaCSharp->Enabled = false;
		this->notaCSharp->Text = "";
		this->notaJava->Enabled = false;
		this->notaJava->Text = "";
	}

	private: System::Void entradaUsuario_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaUsuario->Text = "";
		this->entradaUsuario->ForeColor = System::Drawing::Color::Black;
	}

	private: System::Void entradaCorreo_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaCorreo->Text = "";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Black;
	}
	
	private: System::Void entradaEdad_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaEdad->Text = "";
		this->entradaEdad->ForeColor = System::Drawing::Color::Black;
	}

	private: System::Void activarNotaCPlusPlus(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox1->Checked) {
			this->notaCPlusPlus->Enabled = true;
		}
		else {
			this->notaCPlusPlus->Enabled = false;
			this->notaCPlusPlus->Text = "";
		}
	}
	private: System::Void activarNotaCSharp(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox2->Checked) {
			this->notaCSharp->Enabled = true;
		}
		else {
			this->notaCSharp->Enabled = false;
			this->notaCSharp->Text = "";
		}
	}
	private: System::Void activarNotaJava(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox3->Checked) {
			this->notaJava->Enabled = true;
		}
		else {
			this->notaJava->Enabled = false;
			this->notaJava->Text = "";
		}
	}
	
		   
	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ cursos = "";
		
		

		float sumaNotas = 0;
		float notas = 0;
		float media = 0;
		int edad = atoi(msclr::interop::marshal_as<std::string>(entradaEdad->Text).c_str());

		if (this->checkBox1->Checked) {
			cursos = this->checkBox1->Text->ToString();
			notas += 1;
			if (!this->notaCPlusPlus->Text->Equals("")) {
				sumaNotas += Single::Parse(this->notaCPlusPlus->Text);
			}
		}
		if (this->checkBox2->Checked) {
			if (cursos->Equals("")) {
				cursos = this->checkBox2->Text->ToString();
			}
			else {
				cursos += "," + this->checkBox2->Text->ToString();
			}

			if (!this->notaCSharp->Text->Equals("")) {
				sumaNotas += Single::Parse(this->notaCSharp->Text);
			}
			notas += 1;
		}

		if (this->checkBox3->Checked) {
			if (cursos->Equals("")) {
				cursos = this->checkBox3->Text->ToString();
			}
			else {
				cursos += "," + this->checkBox3->Text->ToString();
			}

			if (!this->notaJava->Text->Equals("")) {
				sumaNotas += Single::Parse(this->notaJava->Text);
			}
			notas += 1;
		}

		if (notas == 0) {
			MessageBox::Show("Introduce al menos una nota");
			return;
		}

		media = sumaNotas / notas;

		if (edad < 18) {
			MessageBox::Show("Error. Eres menor de edad!");
			return;
		}

		if (this->entradaUsuario->Text->Equals("") || this->entradaUsuario->Text->Equals("Introduce tu nombre: ")) {
			MessageBox::Show("Error. Introduce nombre!");
			return;
		}

		if (this->entradaCorreo->Text->Equals("") || this->entradaCorreo->Text->Equals("Introduce tu correo: ")) {
			MessageBox::Show("Error. Introduce correo!");
			return;
		}

		if (this->entradaEdad->Text->Equals("") || this->entradaEdad->Text->Equals("Introduce tu edad: ")) {
			MessageBox::Show("Error. Introduce edad!");
			return;
		}

		Alumno^ alumno = gcnew Alumno(this->entradaUsuario->Text, this->entradaCorreo->Text,media, edad, cursos);
		Contenido^ Inicio = gcnew Contenido(alumno);
		this->Visible = false;
		Inicio->ShowDialog();
		this->Visible = true;
		

		reiniciarFormulario();
	}
	};
}
