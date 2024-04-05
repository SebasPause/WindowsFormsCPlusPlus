using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#pragma once
ref class Noticia
{
public:
	int id;
	String^ titulo;
	String^ texto;
	String^ categoria;
	DateTime fecha;

	Noticia(int id, String^ titulo, String^ texto, String^ categoria, DateTime fecha) {
		this->id = id;
		this->titulo = titulo;
		this->texto = texto;
		this->categoria = categoria;
		this->fecha = fecha;
	}
};

