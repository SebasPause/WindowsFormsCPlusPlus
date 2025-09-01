#pragma once
#include "msclr/marshal_cppstd.h"
#include "Contenido.h"

namespace ExamenCPlusPlus {

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

	private: System::Windows::Forms::Label^ labelTitulo;
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::TextBox^ entradaCorreo;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->entradaContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->entradaCorreo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// entradaContrasenia
			// 
			this->entradaContrasenia->ForeColor = System::Drawing::Color::Silver;
			this->entradaContrasenia->Location = System::Drawing::Point(232, 176);
			this->entradaContrasenia->Name = L"entradaContrasenia";
			this->entradaContrasenia->Size = System::Drawing::Size(228, 20);
			this->entradaContrasenia->TabIndex = 5;
			this->entradaContrasenia->Text = L"Introduce tu contraseña: ";
			this->entradaContrasenia->Enter += gcnew System::EventHandler(this, &Login::entradaContrasenia_Enter);
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
			this->entradaCorreo->Location = System::Drawing::Point(232, 138);
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
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	//Evento del boton "Enviar" para realizar el login
	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		//Los dos campos están definidos con un hint, por lo tanto, antes de obtener el valor, si el valor sigue siendo el hint,
		//se pondrá a vacío
		comprobarFormulario();

		//lectura de los campos de la ventana, se pasa de String^ a string con el #include "msclr/marshal_cppstd.h"
		string password = msclr::interop::marshal_as<std::string>(entradaContrasenia->Text);
		string correo = msclr::interop::marshal_as<std::string>(entradaCorreo->Text);
		
		//Se comprueba el login, si es correcto, se abrirá la segunda ventana
		//En caso contrario, muestra un mensaje de error
		if (comprobarLogin(correo, password)) {
			//Pasar a la segunda ventana
			Contenido^ Inicio = gcnew Contenido();//Crear el objeto de la ventana. Necesario #include "Contenido.h"
			this->Visible = false; // Ocultar la ventana actual
			Inicio->ShowDialog(); // Mostrar la segunda ventana pero sigue oculta
			this->Visible = true; // Mostrar la segunda ventana
		}
		else {
			MessageBox::Show("Credenciales incorrectas"); // Mensaje de error
		}

		//Se reinician los campos a sus valores por defecto
		reiniciarFormulario();
	}

	//Funcion para establecer los campos del login a vacío si no se modifican
	private: System::Void comprobarFormulario() {
		if (this->entradaContrasenia->Text->Equals("Introduce tu contraseña: ")) {
			this->entradaContrasenia->Text = "";
		}if (this->entradaCorreo->Text->Equals("Introduce tu correo: ")) {
			this->entradaCorreo->Text = "";
		}
	}

	//Funcion que retorna true o false según si los datos introducidos coinciden con los 
	private: System::Boolean comprobarLogin(string correo, string password) {
		if (correo == "email@email.com" && password == "password123") {
			return true;
		} return false;
	}

	//Funcion que establece por defecto el hint del formulario
	private: System::Void reiniciarFormulario() {
		this->entradaContrasenia->Text = "Introduce tu contraseña: ";
		this->entradaContrasenia->ForeColor = System::Drawing::Color::Silver;
		this->entradaContrasenia->UseSystemPasswordChar = false;
		this->entradaCorreo->Text = "Introduce tu correo: ";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
	}

	//Evento del campo de Password para quitar las propiedades del hint al entrar en el
	private: System::Void entradaContrasenia_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaContrasenia->Text = "";
		this->entradaContrasenia->ForeColor = System::Drawing::Color::Black;
		this->entradaContrasenia->UseSystemPasswordChar = true;
	}

	//Evento del campo de Correo para quitar las propiedades del hint al entrar en el
	private: System::Void entradaCorreo_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->entradaCorreo->Text = "";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Black;
	}
	};
}
