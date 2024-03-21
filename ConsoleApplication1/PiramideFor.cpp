#include<iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

int PiramideFor()
{
	int altura = 0;
	cout << "Introduce altura de la piramide: ";
	cin >> altura;

	cout << endl;
	for (int numBlancos = altura - 1, numAsteriscos = 1; numBlancos >= 0;numBlancos--,numAsteriscos +=2) {
		for (int i = 1; i <= numBlancos; i++) {
			cout << " ";
		}
		for (int j = 1; j <= numAsteriscos; j++) {
			cout << "*";
			Sleep(100);
		}
		cout << endl;
	}


	//system("pause"); solo para ejecutar exe
	return 0;
}