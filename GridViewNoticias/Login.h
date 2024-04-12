#pragma once
#include "MyForm.h"
#include <iostream>
#include <fstream>
#include "ConexionBBDD.h"
#include "Usuario.h"

namespace GridViewNoticias {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		ConexionBBDD^ conexion = nullptr;
		Usuario^ usuario = nullptr;

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
	private: System::Windows::Forms::TextBox^ entradaCorreo;
	protected:
	private: System::Windows::Forms::Label^ labelTitulo;
	private: System::Windows::Forms::TextBox^ entradaContrasenia;
	private: System::Windows::Forms::Button^ btnEntrar;

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
			this->entradaCorreo = (gcnew System::Windows::Forms::TextBox());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->entradaContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->btnEntrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// entradaCorreo
			// 
			this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
			this->entradaCorreo->Location = System::Drawing::Point(282, 178);
			this->entradaCorreo->Name = L"entradaCorreo";
			this->entradaCorreo->Size = System::Drawing::Size(228, 20);
			this->entradaCorreo->TabIndex = 7;
			this->entradaCorreo->Text = L"Introduce tu correo: ";
			this->entradaCorreo->Enter += gcnew System::EventHandler(this, &Login::entradaCorreo_Enter);
			// 
			// labelTitulo
			// 
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitulo->Location = System::Drawing::Point(341, 51);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(104, 31);
			this->labelTitulo->TabIndex = 5;
			this->labelTitulo->Text = L"LOGIN";
			this->labelTitulo->Enter += gcnew System::EventHandler(this, &Login::entradaCorreo_Enter);
			// 
			// entradaContrasenia
			// 
			this->entradaContrasenia->ForeColor = System::Drawing::Color::Silver;
			this->entradaContrasenia->Location = System::Drawing::Point(282, 216);
			this->entradaContrasenia->Name = L"entradaContrasenia";
			this->entradaContrasenia->Size = System::Drawing::Size(228, 20);
			this->entradaContrasenia->TabIndex = 8;
			this->entradaContrasenia->Text = L"Introduce tu contraseña: ";
			this->entradaContrasenia->Enter += gcnew System::EventHandler(this, &Login::entradaContrasenia_Enter);
			// 
			// btnEntrar
			// 
			this->btnEntrar->Location = System::Drawing::Point(335, 295);
			this->btnEntrar->Name = L"btnEntrar";
			this->btnEntrar->Size = System::Drawing::Size(120, 46);
			this->btnEntrar->TabIndex = 4;
			this->btnEntrar->Text = L"Entrar";
			this->btnEntrar->UseVisualStyleBackColor = true;
			this->btnEntrar->Click += gcnew System::EventHandler(this, &Login::btnEntrar_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 478);
			this->Controls->Add(this->btnEntrar);
			this->Controls->Add(this->entradaCorreo);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->entradaContrasenia);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void comprobarFormulario() {
		if (this->entradaContrasenia->Text->Equals("Introduce tu contraseña: ")) {
			this->entradaContrasenia->Text = "";
		}if (this->entradaCorreo->Text->Equals("Introduce tu correo: ")) {
			this->entradaCorreo->Text = "";
		}
	}

	private: System::Void reiniciarFormulario() {
		this->entradaContrasenia->Text = "Introduce tu contraseña: ";
		this->entradaContrasenia->ForeColor = System::Drawing::Color::Silver;
		this->entradaContrasenia->UseSystemPasswordChar = false;
		this->entradaCorreo->Text = "Introduce tu correo: ";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
	}

	private: System::Void entradaCorreo_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaCorreo->Text = "";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Black;
	}
	private: System::Void entradaContrasenia_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaContrasenia->Text = "";
		this->entradaContrasenia->ForeColor = System::Drawing::Color::Black;
		this->entradaContrasenia->UseSystemPasswordChar = true;
	}
	private: System::Void btnEntrar_Click(System::Object^ sender, System::EventArgs^ e) {
		comprobarFormulario();
		String^ correo = entradaCorreo->Text;
		String^ password = entradaContrasenia->Text;


		int idUsuario = comprobarLogin(correo, password);
		if (idUsuario > 0) {
			MyForm^ Inicio = gcnew MyForm(usuario);
			this->Visible = false;
			Inicio->ShowDialog();
			this->Visible = true;
		}
		else {
			MessageBox::Show("Credenciales incorrectas");
		}

		reiniciarFormulario();
	}
	
	private: int comprobarLogin(String^ correo, String^ password) {
		conexion = gcnew ConexionBBDD();
		conexion->setConexion(conexion->CrearConexion());
		MySqlDataReader^ reader = nullptr;
		
		usuario = conexion->ObtenerUsuario(correo,password);

		if (usuario != nullptr) {
			return 1;
		};
		
		return 0;
	}
};
}
