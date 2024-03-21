#include<iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

void menu(){
	cout << endl;
	cout << "Selecciona una opcion" << endl;
	cout << "1: Opcion 1" << endl;
	cout << "2: Opcion 2" << endl;
	cout << "3: Opcion 3" << endl;
	cout << "4: Salir" << endl;
}

void mostrarMensaje(int opcion) {
	cout << "Has elegido la opcion: " << opcion << endl;
}

int Menu()
{
	int opcion = 0;
	do {
		menu();
		cin >> opcion;
		switch (opcion) {
			case 1:
				mostrarMensaje(1);
				break;
			case 2:
				mostrarMensaje(2);
				break;
			case 3:
				mostrarMensaje(3);
				break;
			default:
				break;
		}
	} while (opcion < 4);


	//system("pause"); solo para ejecutar exe
	return 0;
}