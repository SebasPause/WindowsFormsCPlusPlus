using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#pragma once
ref class Persona
{
public:
	int Edad;
	String^ Nombre;
	String^ Email;
	String^ Curso;
	Persona(int fEdad, String^ fNombre, String^ fEmail, String^ fCurso)
	{
		Nombre = fNombre;
		Email = fEmail;
		Curso = fCurso;
		Edad = fEdad;
	}

};

