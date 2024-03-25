#pragma once
#include <iostream>
#include <cstdlib>
#include "Contenido.h"

namespace Login {

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

	public: int a;
	public: int b;
	public: int i = 0;
	public: static int suma;
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ sumaEsperada;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ valoresSuma;

	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>s
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sumaEsperada = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->valoresSuma = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(388, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LOGIN";
			// 
			// sumaEsperada
			// 
			this->sumaEsperada->Location = System::Drawing::Point(357, 138);
			this->sumaEsperada->Name = L"sumaEsperada";
			this->sumaEsperada->Size = System::Drawing::Size(100, 20);
			this->sumaEsperada->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(240, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Introduce la suma de: ";
			// 
			// valoresSuma
			// 
			this->valoresSuma->AutoSize = true;
			this->valoresSuma->Location = System::Drawing::Point(357, 107);
			this->valoresSuma->Name = L"valoresSuma";
			this->valoresSuma->Size = System::Drawing::Size(0, 13);
			this->valoresSuma->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(369, 212);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Entrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 375);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->valoresSuma);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->sumaEsperada);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (i<3) {
			int resultado = Single::Parse(this->sumaEsperada->Text);
			if (resultado == MyForm::suma) {
				MessageBox::Show("Bienvenido, has entrado");
				Contenido^ Inicio = gcnew Contenido("Hola mundo");
				Contenido^ Inicio2 = gcnew Contenido("Hola ventana 2");
				this->Visible = false;
				Inicio->ShowDialog();
				Inicio2->ShowDialog();
				this->Visible = true;

			}
			else {
				if (i < 2) {
					MessageBox::Show("Error, vuelva a intentarlo.\nTe quedan "+ (2-i) +" intentos");
				}
			}
			i += 1;
		}
		if (i == 3) {
			MessageBox::Show("Has superado el número máximo de intentos");
			Application::Exit();
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Random^ randomInt = gcnew Random();
		a = randomInt->Next(101);
		b = randomInt->Next(101);
		//srand(static_cast<unsigned int>(time(nullptr)));
		//a = rand() % 1000;
		//b = rand() % 1000;

		MyForm::suma = a + b;
		this->valoresSuma->Text = MyForm::a + " + " + Login::MyForm::b;
	}
};
}
