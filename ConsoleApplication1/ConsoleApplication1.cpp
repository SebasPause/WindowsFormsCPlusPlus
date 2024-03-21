#include<iostream>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

int ConsoleApplication1()
{
	string nombre = "";
	string apellido = "";
	cout << "Introduce nombre: ";
	cin >> nombre;
	cout << "Introduce apellido: ";
	cin >> apellido;
	cout << "Nombre: " << nombre << " " << apellido << endl;

	string frutas[3] = { "manzana","pera","sandia" };

	for (string objeto : frutas) {
		cout << "Fruta: " + objeto << endl;
	}

	//system("pause"); solo para ejecutar exe
	return 0;
}