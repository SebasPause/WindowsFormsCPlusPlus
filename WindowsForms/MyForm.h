#pragma once

namespace WindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// Resumen de MyForm
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
		/// Limpiar los recursos que se estén usando.
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::Label^ salida;
	private: System::Windows::Forms::TextBox^ entradaUsuario;
	private: System::Windows::Forms::TextBox^ entradaCorreo;
	private: System::Windows::Forms::Label^ labelTitulo;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::RadioButton^ radioMasculino;
	private: System::Windows::Forms::RadioButton^ radioFemenino;
	private: System::Windows::Forms::RadioButton^ radioOtros;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ notaCPlusPlus;
	private: System::Windows::Forms::TextBox^ notaCSharp;
	private: System::Windows::Forms::TextBox^ notaJava;








	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		void InitializeComponent(void)
		{
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->salida = (gcnew System::Windows::Forms::Label());
			this->entradaUsuario = (gcnew System::Windows::Forms::TextBox());
			this->entradaCorreo = (gcnew System::Windows::Forms::TextBox());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->radioMasculino = (gcnew System::Windows::Forms::RadioButton());
			this->radioFemenino = (gcnew System::Windows::Forms::RadioButton());
			this->radioOtros = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->notaCPlusPlus = (gcnew System::Windows::Forms::TextBox());
			this->notaCSharp = (gcnew System::Windows::Forms::TextBox());
			this->notaJava = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnEnviar
			// 
			this->btnEnviar->Location = System::Drawing::Point(225, 383);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(117, 49);
			this->btnEnviar->TabIndex = 0;
			this->btnEnviar->Tag = L"btnEnviar";
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &MyForm::btnEnviar_Click);
			// 
			// salida
			// 
			this->salida->AutoSize = true;
			this->salida->Location = System::Drawing::Point(21, 291);
			this->salida->Name = L"salida";
			this->salida->Size = System::Drawing::Size(0, 13);
			this->salida->TabIndex = 1;
			// 
			// entradaUsuario
			// 
			this->entradaUsuario->ForeColor = System::Drawing::Color::Silver;
			this->entradaUsuario->Location = System::Drawing::Point(24, 75);
			this->entradaUsuario->Name = L"entradaUsuario";
			this->entradaUsuario->Size = System::Drawing::Size(228, 20);
			this->entradaUsuario->TabIndex = 1;
			this->entradaUsuario->Text = L"Introduce tu nombre: ";
			this->entradaUsuario->Enter += gcnew System::EventHandler(this, &MyForm::entradaUsuario_Enter);
			// 
			// entradaCorreo
			// 
			this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
			this->entradaCorreo->Location = System::Drawing::Point(24, 113);
			this->entradaCorreo->Name = L"entradaCorreo";
			this->entradaCorreo->Size = System::Drawing::Size(228, 20);
			this->entradaCorreo->TabIndex = 2;
			this->entradaCorreo->Text = L"Introduce tu correo: ";
			this->entradaCorreo->Enter += gcnew System::EventHandler(this, &MyForm::entradaCorreo_Enter);
			// 
			// labelTitulo
			// 
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitulo->Location = System::Drawing::Point(18, 20);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(546, 31);
			this->labelTitulo->TabIndex = 3;
			this->labelTitulo->Text = L"Aplicación WINDOWS FORMS CON C++";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(341, 115);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(45, 17);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"C++";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &MyForm::activarNotaCPlusPlus);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(341, 138);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(40, 17);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"C#";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Click += gcnew System::EventHandler(this, &MyForm::activarNotaCSharp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(340, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"¿Qué cursos has estudiado\?";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(341, 161);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"Java";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->Click += gcnew System::EventHandler(this, &MyForm::activarNotaJava);
			// 
			// radioMasculino
			// 
			this->radioMasculino->AutoSize = true;
			this->radioMasculino->Location = System::Drawing::Point(17, 15);
			this->radioMasculino->Name = L"radioMasculino";
			this->radioMasculino->Size = System::Drawing::Size(73, 17);
			this->radioMasculino->TabIndex = 8;
			this->radioMasculino->TabStop = true;
			this->radioMasculino->Text = L"Masculino";
			this->radioMasculino->UseVisualStyleBackColor = true;
			// 
			// radioFemenino
			// 
			this->radioFemenino->AutoSize = true;
			this->radioFemenino->Location = System::Drawing::Point(17, 39);
			this->radioFemenino->Name = L"radioFemenino";
			this->radioFemenino->Size = System::Drawing::Size(71, 17);
			this->radioFemenino->TabIndex = 9;
			this->radioFemenino->TabStop = true;
			this->radioFemenino->Text = L"Femenino";
			this->radioFemenino->UseVisualStyleBackColor = true;
			// 
			// radioOtros
			// 
			this->radioOtros->AutoSize = true;
			this->radioOtros->Location = System::Drawing::Point(17, 62);
			this->radioOtros->Name = L"radioOtros";
			this->radioOtros->Size = System::Drawing::Size(50, 17);
			this->radioOtros->TabIndex = 10;
			this->radioOtros->TabStop = true;
			this->radioOtros->Text = L"Otros";
			this->radioOtros->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioFemenino);
			this->groupBox1->Controls->Add(this->radioMasculino);
			this->groupBox1->Controls->Add(this->radioOtros);
			this->groupBox1->Location = System::Drawing::Point(24, 164);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(155, 87);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Genero";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(407, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Nota:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(407, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Nota:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(407, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Nota:";
			// 
			// notaCPlusPlus
			// 
			this->notaCPlusPlus->Location = System::Drawing::Point(447, 112);
			this->notaCPlusPlus->Name = L"notaCPlusPlus";
			this->notaCPlusPlus->Size = System::Drawing::Size(100, 20);
			this->notaCPlusPlus->TabIndex = 16;
			this->notaCPlusPlus->Enabled = false;
			// 
			// notaCSharp
			// 
			this->notaCSharp->Location = System::Drawing::Point(447, 137);
			this->notaCSharp->Name = L"notaCSharp";
			this->notaCSharp->Size = System::Drawing::Size(100, 20);
			this->notaCSharp->TabIndex = 17;
			this->notaCSharp->Enabled = false;
			// 
			// notaJava
			// 
			this->notaJava->Location = System::Drawing::Point(447, 161);
			this->notaJava->Name = L"notaJava";
			this->notaJava->Size = System::Drawing::Size(100, 20);
			this->notaJava->TabIndex = 18;
			this->notaJava->Enabled = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 444);
			this->Controls->Add(this->notaJava);
			this->Controls->Add(this->notaCSharp);
			this->Controls->Add(this->notaCPlusPlus);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->entradaCorreo);
			this->Controls->Add(this->entradaUsuario);
			this->Controls->Add(this->salida);
			this->Controls->Add(this->btnEnviar);
			this->Name = L"MyForm";
			this->Text = L"Windows Forms";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ cursos = "";
		String^ genero;

		if (this->radioMasculino->Checked) {
			genero = this->radioMasculino->Text;
		}
		if (this->radioFemenino->Checked) {
			genero = this->radioFemenino->Text;
		}
		if (this->radioOtros->Checked) {
			genero = this->radioOtros->Text;
		}

		float sumaNotas = 0;
		float notas = 0;
		float media = 0;

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

		media = sumaNotas / notas;

		salida->Text = "Bienvenid@ "+ entradaUsuario->Text 
			+ "\nTu correo es: "+entradaCorreo->Text
			+ "\nHas elegido estudiar: "+cursos
			+ "\nTu género: "+genero
			+ "\nLa media de tus notas: "+media;
		reiniciarFormulario();
		//MessageBox::Show(this->btnEnviar->Text);
	}
	private: System::Void entradaUsuario_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->salida->Text = "";
		this->entradaUsuario->Text = "";
		this->entradaUsuario->ForeColor = System::Drawing::Color::Black;
	}

	private: System::Void entradaCorreo_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->salida->Text = "";
		this->entradaCorreo->Text = "";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Black;
	}

	private: System::Void reiniciarFormulario() {
		this->entradaUsuario->Text = "Introduce tu nombre: ";
		this->entradaUsuario->ForeColor = System::Drawing::Color::Silver;
		this->entradaCorreo->Text = "Introduce tu correo: ";
		this->entradaCorreo->ForeColor = System::Drawing::Color::Silver;
		this->checkBox1->Checked = false;
		this->checkBox2->Checked = false;
		this->checkBox3->Checked = false;
		this->radioMasculino->Checked = false;
		this->radioFemenino->Checked = false;
		this->radioOtros->Checked = false;
		this->notaCPlusPlus->Enabled = false;
		this->notaCPlusPlus->Text = "";
		this->notaCSharp->Enabled = false;
		this->notaCSharp->Text = "";
		this->notaJava->Enabled = false;
		this->notaJava->Text = "";
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
};
}
