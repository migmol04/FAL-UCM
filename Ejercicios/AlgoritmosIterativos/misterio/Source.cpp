#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*
PRECONDICION DE LA FUNCION:
  - El array `a[]` contiene `n` elementos válidos, donde `n >= 1`.
  - El array `a[]` está ordenado de forma no decreciente.
*/



int misterio(const int a[], int n) {
	int maxContador = 1;
	int contador = 1;
	int candidato = a[0];
	int valor = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] == candidato) {
			contador++;
		}
		else {
			if (contador > maxContador) {
				maxContador = contador;
				valor = candidato;
			}
			contador = 1;
			candidato = a[i];
		}
	}

	if (contador > maxContador) {
		valor = candidato;
	}
	return valor;
}


/*
COMPLEJIDAD:
  - Tiempo: O(n), donde `n` es el tamaño del array `a[]`. Cada elemento se procesa una sola vez.
  - Espacio: O(1), ya que el algoritmo utiliza únicamente variables auxiliares constantes.
*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n >= 0) {
			cout << misterio(a, n) << endl;
		}
	} while (n != -1);
}