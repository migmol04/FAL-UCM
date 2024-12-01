/*
N� GRUPO:
NOMBRES Y APELLIDOS:


*/
#include <cstdlib>

#include <iostream>

using namespace std;


//n siempre ser� positivo (es decir, pod�is asumir n >= 1)
int diametro(int a[], int n) {
	int mayor = a[0];
	int menor = a[0];
	
	int maxdiferencia = 0;
	for (int i = 0; i < n; i++) {
		int aux1 = a[i];
		int aux2 = a[i];
		
		if (aux1 >= mayor) {
			mayor = aux1;;
	    }
	    if (aux2 <= menor) {
			menor = aux2;
		}
	}

	maxdiferencia = abs(mayor - menor);
	return maxdiferencia;
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
		cout << diametro(a, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}