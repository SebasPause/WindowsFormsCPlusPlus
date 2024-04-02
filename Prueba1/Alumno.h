#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Alumno
{

private:
	int edad;
	float nota;
	string nombreCompleto;
	bool cPlusPlus;
	bool cSharp;
	bool java;

public:
	Alumno() {}

	Alumno(string nombreCompleto, float nota) {
		this->nombreCompleto = nombreCompleto;
		this->nota = nota;
	}

	Alumno(string nombreCompleto, float nota, int edad, bool cPlusPlus, bool cSharp, bool java) {
		this->nombreCompleto = nombreCompleto;
		this->nota = nota;
		this->edad = edad;
		this->cPlusPlus = cPlusPlus;
		this->cSharp = cSharp;
		this->java = java;
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

	void setNombreCompleto(string nombreCompleto) {
		this->nombreCompleto = nombreCompleto;
	}

	string getNombreCompleto() {
		return this->nombreCompleto;
	}

	void setcPlusPlus(bool cPlusPlus) {
		this->cPlusPlus = cPlusPlus;
	}

	bool getcPlusPlus() {
		return this->cPlusPlus;
	}

	void setcSharp(bool cSharp) {
		this->cSharp = cSharp;
	}

	bool getcSharp() {
		return this->cSharp;
	}

	void setjava(bool java) {
		this->java = java;
	}

	bool getjava() {
		return this->java;
	}

};
