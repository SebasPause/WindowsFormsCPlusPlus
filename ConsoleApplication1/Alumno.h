#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

class Alumno
{


	private:
		int edad;
		float nota;
		string nombreCompleto;

	public:
		Alumno(string nombreCompleto,float nota) {
			this->nombreCompleto = nombreCompleto;
			this->nota = nota;
		}

		Alumno(string nombreCompleto, float nota, int edad) {
			this->nombreCompleto = nombreCompleto;
			this->nota = nota;
			this->edad = edad;
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
};

