
#include <iostream>

using namespace std;


/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- parámetro (en caso de que utilices una generalización), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/
bool cuenta_digitos(int n) {
	int digito = 0;;
    int contador = 0;
	int suma_digitos = 0;
	while (n > 0) {
		digito = n % 10;
		contador++;
		suma_digitos += digito;
		n = n / 10;
	}

	if (suma_digitos % contador == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool sumdivisible(int n) {
	if (n < 10) {  
		return true;
	}
	else if (cuenta_digitos(n)) {
		return sumdivisible(n / 10);  
	}
	else {
		return false;
	}

}


/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA:
   NO MODIFICAR */

int main() {
	int n;
	do {
		cin >> n;
		if (n > 0) {
			if (sumdivisible(n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n > 0);
}

