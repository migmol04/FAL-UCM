/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>
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

/*
(1) Generalización:

Parámetros de la generalización:
- `a[]`: (tipo: int[], entrada) Vector ordenado con `n` elementos.
- `b[]`: (tipo: int[], entrada) Vector ordenado con `n+1` elementos, que contiene todos los elementos de `a` más un "intruso".
- `ini`: (tipo: int, entrada) Índice inicial del subarray actual en el que se está buscando.
- `fin`: (tipo: int, entrada) Índice final del subarray actual en el que se está buscando.

Propósito:
Determinar el valor del "intruso" (el elemento extra en `b[]` que no está en `a[]`).

(2) Análisis de casos:

(2.1) Casos base:
- Si `ini == fin`:
  - Si `a[ini] == b[ini]`: El intruso es `b[ini + 1]` porque está justo después.
  - Si `a[ini] != b[ini]`: El intruso es `b[ini]` porque está en esa posición.

(2.2) Casos recursivos:
- Dividir el rango `[ini, fin]` en dos mitades usando `medio = (ini + fin) / 2`.
- Comparar `a[medio]` con `b[medio]`:
  - Si son iguales, el intruso está en la segunda mitad (`[medio + 1, fin]`).
  - Si no son iguales, el intruso está en la primera mitad (`[ini, medio]`).

(3) Definición por inmersión del algoritmo:
- Se realiza una búsqueda binaria en el vector `b[]` usando recursión.
- En cada llamada recursiva, se reduce el rango de búsqueda a la mitad.
- El caso base devuelve directamente el valor del intruso al alcanzar una sola posición.

(4) Complejidad del algoritmo:

(4.1) Ecuación de recurrencia:
T(n) = T(n/2) + O(1)

(4.2) Resolución:
Usando el patrón de división y conquista, la solución es:
T(n) = O(log n)

(4.3) Complejidad final:
El algoritmo tiene una complejidad O(log n), ya que en cada paso divide el rango de búsqueda a la mitad.
*/

// El vector 'a' tiene 'n' elmenentos. El vector 'b' n+1

int intruso(int a[], int n, int b[], int ini, int fin) {
	if (ini == fin) {
		if (a[ini] == b[ini]) {
			return b[ini + 1];
		}
		else {
			return b[ini];
		}
	}
	else {
		int medio = (ini + fin) / 2;
		if (b[medio] == a[medio]) {
			return intruso(a, n, b, medio + 1, fin);
		}
		else {
			return intruso(a, n, b, ini, medio);
		}
	}

}
int intruso(int a[], int n, int b[]) {
	return intruso(a, n, b, 0, n - 1);
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const int NMAX = 10000; // El vector 'a' no tendr� m�s de 10000 de elementos

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		int a[NMAX];
		int b[NMAX + 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++) {
			cin >> b[i];
		}
		cout << intruso(a, n, b) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}