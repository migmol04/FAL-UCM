/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:


Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/


#include <iostream>
using namespace std;


/*
PRECONDICION DE LA FUNCION:
  - El array `v[]` contiene `n` elementos válidos, donde `n >= 0`.
  - Los elementos del array son números enteros.
*/


int /* resul */ long_tramo_par_mas_largo(int v[], unsigned int n);

/*
POSTCONDICION DE LA FUNCION:
  - resul = longitud del tramo más largo de elementos consecutivos en `v[]` que son pares.
  - Si no hay elementos pares en el array, resul = 0.
*/

/*
DISEÑO DEL ALGORITMO:

PASO 1. Variables adicionales:
  - `max`: Almacena la longitud del tramo más largo de números pares encontrado hasta el momento.
  - `lon`: Almacena la longitud del tramo actual de números pares.
  - `der`: Índice que recorre el array.

PASO 2. Invariante:
  Antes de cada iteración del bucle:
    - `lon` representa la longitud del tramo actual de números pares que termina en `v[der - 1]`.
    - `max` contiene la longitud del tramo más largo de números pares encontrado hasta el índice `der - 1`.

PASO 3. Inicialización:
  - `max = 0`: Al inicio, no se ha encontrado ningún tramo de números pares.
  - `lon = 0`: Al inicio, no hay ningún tramo actual.
  - `der = 0`: El índice empieza desde el primer elemento del array.

PASO 4. Condición del bucle:
  - El bucle se ejecuta mientras `der < n`, es decir, mientras queden elementos en el array por procesar.

PASO 5. Cuerpo del bucle:
  - Si el elemento actual `v[der]` es par (`v[der] % 2 == 0`), incrementa `lon`.
  - Si no es par, reinicia `lon` a 0 porque el tramo actual termina.
  - Actualiza `max` si `lon > max`.

PASO 6. Código tras el bucle:
  - Al salir del bucle, `max` contiene la longitud del tramo más largo de números pares encontrado en el array.

PASO 7. Complejidad:
  - Tiempo: O(n), ya que el array se recorre una sola vez.
  - Espacio: O(1), ya que solo se utilizan variables auxiliares constantes.
*/



int /* resul */ long_tramo_par_mas_largo(int v[], int n) {
	int max = 0;
	int lon = 0;
	int der = 0;
	int izq = 0;
	while(der < n){
		if (v[der] % 2 == 0) {
			lon++;
		}

		else {
			lon = 0;
		}

		if (lon > max) {
			max = lon;
		}
		der++;
	}
	return max;
}



/* PROGRAMA DE PRUEBA: No modificar */

const int MAX_ELEMS = 1000000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	static int v[MAX_ELEMS];
	if (n == -1) return false;
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << long_tramo_par_mas_largo(v, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}