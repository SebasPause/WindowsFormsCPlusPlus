using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#pragma once
ref class Alumnos
{
public:
	//Propiedades públicas
	int Edad;
	String^ Nombre;

	//Constructor de la clase con dos parámetros: String^ e int
	Alumnos(String^ fNombre, int fEdad)
	{
		Nombre = fNombre;
		Edad = fEdad;
	}

};