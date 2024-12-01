/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:

MIGUEL ANGEL MOLINA DE LA ROSA Y PABLO NIETO LÓPEZ
Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;



/*
(1) �C�mo son las soluciones parciales viables de este problema?
Las soluciones parciales viables son aquellas en las que la suma de los elementos seleccionados no supera el umbral 'U'. 
En cada paso, se añade un nuevo elemento al conjunto de la solución parcial, siempre y cuando no se supere el umbral.

(2) �Cu�ndo una soluci�n es final?
Una solución es final cuando se han considerado todos los elementos del conjunto 'C' y la suma de los elementos seleccionados no supera el umbral 'U'.

(3) Dada una soluci�n viable, �c�mo se generan nuevas soluciones viables a partir de ella?
A partir de una solución viable, se generan nuevas soluciones añadiendo un nuevo elemento del conjunto 'C' a la solución existente, siempre y cuando la suma de los elementos no supere el umbral 'U'.


(4) �C�mo se representar�n las soluciones en este problema? Describe los distintos elementos
Las soluciones se representan como un subconjunto de 'C' cuya suma de elementos no supera 'U'.
Los elementos del conjunto 'C' y el umbral 'U' son parámetros de entrada. La solución se representa implícitamente a través del recorrido recursivo del conjunto 'C'.
	de informaci�n que las componen, indicando si se representan como par�metros de entrada,
	de entrada/salida (estado global), si se representan impl�citamente...

(5) �Qu� marcadores utiliza el algoritmo? Describe claramente su prop�sito, los elementos
El algoritmo utiliza el marcador 'minimalistas' para contar el número de soluciones viables. Este marcador se pasa como un parámetro de entrada/salida
	de informaci�n que los componen, as� como si dichos elementos se representan como par�metros
	de entrada, de entrada/salida (estado global)...

(6) Si el algoritmo utiliza generalizaci�n, indica como es la misma, describiendo claramente
	el prop�sito de cada par�metro.
	El algoritmo utiliza la técnica de vuelta atras para explorar todas las posibles combinaciones de elementos en 'C' que no superen 'U'.
	Esta es una forma de generalización, ya que se aplica el mismo proceso a cada subconjunto de 'C'.


(7) An�lisis de casos: casos base, casos recursivos
El caso base es cuando la suma de los elementos seleccionados supera 'U' o cuando se han considerado todos los elementos de 'C'. En estos casos, no se generan más soluciones a partir de la actual. 
El caso recursivo es cuando la suma de los elementos seleccionados no supera 'U'. 
En este caso, se generan nuevas soluciones añadiendo un nuevo elemento a la solución actual

(8) Si el algoritmo utiliza una generalizaci�n, describe c�mo se implementa el algoritmo
	en t�rminos de la misma (inmersi�n)
	El algoritmo se implementa a través de una función recursiva que explora todas las posibles combinaciones de elementos en 'C'. 
	En cada llamada recursiva, se añade un nuevo elemento a la solución actual y se comprueba si la suma de los elementos seleccionados supera 'U'. 
	Si no es así, se incrementa el contador de 'minimalistas' y se realizan más llamadas recursivas para explorar las soluciones restantes.

*/


// En los 'n' (n>0) primeros elementos de 'c' se encuentran almacenados
// los elementos del conjunto 'C'.
// En 'u' est� el umbral 'U' (U >= 0). 


void num_minimalistas_tmp(int c[], int n, int u, int suma, int minimo, int& minimalistas) {
	int tmp = suma;
	for (int i = 0; i < n; i++) {
		int min = minimo;
		if (c[i] != min) {
			if (min == -1) {
				min = c[i];
			}

			else if (c[i] < min) {
				min = c[i];
			}
			tmp += c[i];

			if (tmp <= u) {
				minimalistas++;
				num_minimalistas_tmp(c, n, u, tmp, min, minimalistas);
			}
			tmp = suma;
		}

	}

}

int num_minimalistas(int c[], int n, int u) {
	int minimalistas = 0;
	num_minimalistas_tmp(c, n, u, 0, -1, minimalistas);
	return minimalistas;
}


const int MAX_VALS = 100;
bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		int v[MAX_VALS];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int u;
		cin >> u;
		cout << num_minimalistas(v, n, u) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}