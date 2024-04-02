#include <cstdlib>
#include <iostream>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#pragma once
ref class Alumno
{

private:
	int edad;
	float nota;
	String^ nombreCompleto;
	String^ correo;
	String^ cursos;

public:
	Alumno() {}

	Alumno(String^ nombreCompleto, float nota) {
		this->nombreCompleto = nombreCompleto;
		this->nota = nota;
	}

	Alumno(String^ nombreCompleto, String^ correo, float nota, int edad, String^ cursos) {
		this->nombreCompleto = nombreCompleto;
		this->correo = correo;
		this->nota = nota;
		this->edad = edad;
		this->cursos = cursos;
	}

	void setEdad(int edad) {
		this->edad = edad;
	}

	int getEdad() {
		return this->edad;
	}

	void setNota(float nota) {
		this->nota = nota;
	}

	float getNota() {
		return this->nota;
	}

	void setNombreCompleto(String^ nombreCompleto) {
		this->nombreCompleto = nombreCompleto;
	}

	String^ getNombreCompleto() {
		return this->nombreCompleto;
	}

	void setCorreo(String^ correo) {
		this->correo = correo;
	}

	String^ getCorreo() {
		return this->correo;
	}

	void setCursos(String^ cursos) {
		this->cursos = cursos;
	}

	String^ getCursos() {
		return this->cursos;
	}

};


