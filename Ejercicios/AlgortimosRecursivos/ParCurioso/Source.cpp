#include <iostream>
#include <algorithm>
using namespace std;


/*
(1) Precondición

(2) Postcondición

(3) Si vas a utilizar una generalización, especificación
	pre-pos de la generalización

(4) Casos no recursivos

(5) Casos recursivos

(6) Terminación (expresión de cota)

(7) Si has usado una generalización, definición por
	inmersión de es_paracurioso

(8) Determinación de la complejidad (recurrencias y su resolución)


*/
bool es_par_curioso_aux(int v[], int inicio, int fin) {
	int n = fin - inicio + 1;
	if (n == 1) return true;
	int mitad = (inicio + fin) / 2;
	int numPares = 0;
	int numImpares = 0;
	int sumaPar = 0;
	int sumaImpar = 0;

	for (int i = inicio; i <= mitad; i++) {
		if (v[i] % 2 == 0) {
			numPares++;
			sumaPar += v[i];
		}

	}


	for (int i = mitad + 1; i <= fin; i++) {
		if (v[i] % 2 != 0) {
			numImpares++;
			sumaImpar += v[i];
		}

	}

	if (numPares > numImpares || sumaPar > sumaImpar) return false;

	return es_par_curioso_aux(v, inicio, mitad) || es_par_curioso_aux(v, mitad + 1, fin);


}

bool  es_parcurioso(int v[], int n) {
	return es_par_curioso_aux(v, 0, n - 1);

}


// NO MODIFICAR

const static int MAX_ELEMENTS = 100000;

void ejecuta_caso() {
	static int v[MAX_ELEMENTS];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (es_parcurioso(v, n)) {
		cout << "SI" << endl;;
	}
	else {
		cout << "NO" << endl;
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		ejecuta_caso();
	return 0;
}