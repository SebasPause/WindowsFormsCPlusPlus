#include<iostream>
#include <stdio.h>
#include <string>
using namespace std;


int ForAnidados()
{
	int matriz[3][3] = {
		{2,4,3},
		{6,9,2},
		{7,9,1}
	};

	cout << "Array:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "{";
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				cout << matriz[i][j];
			}
			else {
				cout << "," << matriz[i][j];
			}
		}
		cout << "}" << endl;
	}

	cout << endl << "Multiplos de 3: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matriz[i][j] % 3 == 0) {
				cout << matriz[i][j] << " % 3 = 0" << endl;
			}
		}
	}

	cout << endl << "Array cambiando multiplos de 3 por A" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "{";
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				if (matriz[i][j] % 3 == 0) {
					cout << "A";
				}
				else {
					cout << matriz[i][j];
				}
			}
			else {
				if (matriz[i][j] % 3 == 0) {
					cout << "," << "A";
				}
				else {
					cout << "," << matriz[i][j];
				}
			}
		}
		cout << "}" << endl;
	}


	//system("pause"); solo para ejecutar exe
	return 0;
}