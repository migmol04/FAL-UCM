/*
N� GRUPO:
NOMBRES Y APELLIDOS:


*/


#include <iostream>

using namespace std;


//n siempre ser� positivo (es decir, pod�is asumir n >= 1)
bool ORDENADO(int a[], int n) {
	bool ordenado = true;
	for (int i = 0; i < n - 1 && ordenado; i++) {
		if (a[i] > a[i + 1]) {
			ordenado = false;
		}

	}
	return ordenado;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

const int TMAX = 1000000;  // No se podr�n leer vectores de m�s de un mill�n de elementos

bool ejecuta_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1 || n > TMAX) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if(ORDENADO(a, n)){
			cout << "SI" << endl;
		}
		else{
			cout << "NO" << endl;
		}
			;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}