/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>
#include <climits>
using namespace std;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada del dise�o sistem�tico del mismo.
*/


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(4.2) Resoluci�n utilizando los patrones vistos en clase

(4.3) Determinaci�n justificada de la complejidad del algoritmo final.



*/


bool es_superb_aux(int v[], int inicio, int fin) {
	int n = fin - inicio + 1;
	if (n < 3) {
		return true;  
	}

	int mitad = (fin - inicio) / 2;
	int maximoValor = INT_MIN;
	int minimoValor = INT_MAX;

	for (int i = inicio; i < mitad; i++) {
		if (v[i] > maximoValor) {
			maximoValor = v[i];
		}
	}
	for (int i = mitad + 1; i <= fin; i++) {
		if (v[i] < minimoValor) {
			minimoValor = v[i];
		}
	}

	if (v[mitad] == abs(maximoValor - minimoValor) &&
		es_superb_aux(v, inicio, mitad - 1) &&
		es_superb_aux(v, mitad + 1, fin)) {
		return true;
	}
	else {
		return false;
	}
}

bool es_superb(int v[], int n) {
	return es_superb_aux(v,  0, n - 1);
	
}


/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).


const static int MAX_ELEMENTS = 10000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		int v[MAX_ELEMENTS];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (es_superb(v, n)) {
			cout << "SUPERB" << endl;;
		}
		else {
			cout << "NO SUPERB" << endl;
		}
		return true;
	}
}


int main() {
	while (ejecuta_caso());
	return 0;
}
