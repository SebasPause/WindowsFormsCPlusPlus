#pragma once
#include "Contenido.h"
#include <iostream>
#include <fstream>
#include "msclr/marshal_cppstd.h"

namespace VariasVentanas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ entradaContrasenia;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^ entradaUsuario;
	private: System::Windows::Forms::Label^ labelTitulo;
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::TextBox^ entradaCorreo;


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
			this->entradaContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->entradaUsuario = (gcnew System::Windows::Forms::TextBox());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->entradaCorreo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// entradaContrasenia
			// 
			this->entradaContrasenia->ForeColor = System::Drawing::Color::Silver;
			this->entradaContrasenia->Location = System::Drawing::Point(229, 196);
			this->entradaContrasenia->Name = L"entradaContrasenia";
			this->entradaContrasenia->Size = System::Drawing::Size(228, 20);
			this->entradaContrasenia->TabIndex = 5;
			this->entradaContrasenia->Text = L"Introduce tu contraseña: ";
			this->entradaContrasenia->Enter += gcnew System::EventHandler(this, &Login::entradaContrasenia_Enter);
			// 
			// entradaUsuario
			// 
			this->entradaUsuario->ForeColor = System::Drawing::Color::Silver;
			this->entradaUsuario->Location = System::Drawing::Point(229, 121);
			this->entradaUsuario->Name = L"entradaUsuario";
			this->entradaUsuario->Size = System::Drawing::Size(228, 20);
			this->entradaUsuario->TabIndex = 3;
			this->entradaUsuario->Text = L"Introduce tu usuario: ";
			this->entradaUsuario->Enter += gcnew System::EventHandler(this, &Login::entradaUsuario_Enter);
			// 
			// labelTitulo
			// 
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitulo->Location = System::Drawing::Point(288, 31);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(104, 31);
			this->labelTitulo->TabIndex = 2;
			this->labelTitulo->Text = L"LOGIN";
			// 
			// btnEnviar
			// 
			this->btnEnviar->Location = System::Drawing::Point(284, 289);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(117, 49);
			this->btnEnviar->TabIndex = 0;
			this->btnEnviar->Tag = L"btnEnviar";
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &Login::btnEnviar_Click);
			// 
			// entradaCorreo
			// 
			this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
			this->entradaCorreo->Location = System::Drawing::Point(229, 158);
			this->entradaCorreo->Name = L"entradaCorreo";
			this->entradaCorreo->Size = System::Drawing::Size(228, 20);
			this->entradaCorreo->TabIndex = 4;
			this->entradaCorreo->Text = L"Introduce tu correo: ";
			this->entradaCorreo->Enter += gcnew System::EventHandler(this, &Login::entradaCorreo_Enter);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 386);
			this->Controls->Add(this->entradaCorreo);
			this->Controls->Add(this->btnEnviar);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->entradaContrasenia);
			this->Controls->Add(this->entradaUsuario);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		comprobarFormulario();
		string texto;
		String^ password;
		ifstream MyReadFile("password.txt");
		if (getline(MyReadFile, texto)) {
			password = msclr::interop::marshal_as<System::String^>(texto);
		}

		if (password->Equals(entradaContrasenia->Text)) {
			ofstream Archivo("usuario.txt", ios_base::app); //ios_base::app para agregar en vez de sobreescribir

			string usuario = "Usuario:"+msclr::interop::marshal_as<std::string>(entradaUsuario->Text);
			string password = "Password:" + msclr::interop::marshal_as<std::string>(entradaContrasenia->Text);
			string correo = "Correo:" + msclr::interop::marshal_as<std::string>(entradaCorreo->Text);

			// Write to the file
			Archivo << usuario << "\n";
			Archivo << password << "\n";
			Archivo << correo << "\n";

			// Close the file
			Archivo.close();


			Contenido^ Inicio = gcnew Contenido(this->entradaUsuario->Text, this->entradaContrasenia->Text);
			this->Visible = false;
			Inicio->ShowDialog();
			this->Visible = true;
		}
		else {
			MessageBox::Show("Contraseña incorrecta");
		}
		
		reiniciarFormulario();
	}

	private: System::Void comprobarFormulario() {
		if (this->entradaUsuario->Text->Equals("Introduce tu usuario: ")) {
			this->entradaUsuario->Text = "";
		}
		if (this->entradaContrasenia->Text->Equals("Introduce tu contraseña: ")) {
			this->entradaContrasenia->Text = "";
		}if (this->entradaCorreo->Text->Equals("Introduce tu correo: ")) {
			this->entradaCorreo->Text = "";
		}
	}

	private: System::Void reiniciarFormulario() {
		this->entradaUsuario->Text = "Introduce tu usuario: ";
		this->entradaUsuario->ForeColor = System::Drawing::Color::Silver;
		this->entradaContrasenia->Text = "Introduce tu contraseña: ";
		this->entradaContrasenia->ForeColor = System::Drawing::Color::Silver;
		this->entradaContrasenia->UseSystemPasswordChar = false;
		this->entradaCorreo->Text = "Introduce tu correo: ";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
	}

	private: System::Void entradaUsuario_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaUsuario->Text = "";
		this->entradaUsuario->ForeColor = System::Drawing::Color::Black;
	}

	private: System::Void entradaContrasenia_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaContrasenia->Text = "";
		this->entradaContrasenia->ForeColor = System::Drawing::Color::Black;
		this->entradaContrasenia->UseSystemPasswordChar = true;
	}

	private: System::Void entradaCorreo_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaCorreo->Text = "";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Black;
	}
};
}
