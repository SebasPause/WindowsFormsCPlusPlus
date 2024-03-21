#include<iostream>
#include <stdio.h>
#include <string>
using namespace std;

int MediaConArreglos()
{
	int notas[5];
	for (int i = 0; i < 5; i++) {
		cout << "Escribe la nota " << i + 1 << ": ";
		cin >> notas[i];
	}

	float sumaNotas = 0;

	for (int nota : notas) {
		sumaNotas += nota;
	}
	cout << "\nLa suma de las notas equivale a " << sumaNotas;
	cout << "\nLongitud array: " << sizeof(notas) / sizeof(notas[0]);
	float mediaNotas = sumaNotas / (sizeof(notas)/sizeof(notas[0]));

	cout << "\nLa media de las notas es = " << mediaNotas << endl;

	//system("pause"); solo para ejecutar exe
	return 0;
}