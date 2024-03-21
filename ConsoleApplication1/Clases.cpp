#include<iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "Alumno.h"
#include <vector>

using namespace std;

void mostrarAlumnos(vector<Alumno> alumnos){
	for (int i = 0; i < alumnos.size(); i++) {
		cout << "Alumno: " << alumnos[i].getNombreCompleto() << " con nota: " << alumnos[i].getNota() << endl;
	}
}

int main()
{
	vector<Alumno> listaAlumnos;

	cout << "Introduce alumnos";
	for (int i = 1; i <= 3; i++) {
		string nombreCompleto;
		float nota;
		cout << endl << "Nombre completo alumno " << i << " : ";
		getline(cin, nombreCompleto);
		cout << "Nota: ";
		cin >> nota;
		cin.ignore(100, '\n');
		listaAlumnos.push_back(Alumno(nombreCompleto,nota));
	}


	cout << endl << "Alumnos: " << endl;
	mostrarAlumnos(listaAlumnos);

	listaAlumnos[0].setNota(6);
	listaAlumnos[1].setNota(8.4);
	listaAlumnos[2].setNota(3.9);


	cout << endl << "Alumnos con nota editada: " << endl;
	mostrarAlumnos(listaAlumnos);


	//system("pause"); solo para ejecutar exe
	return 0;
}