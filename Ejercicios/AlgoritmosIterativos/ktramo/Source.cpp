
#include <iostream>

using namespace std;


/*
PRECONDICION DE LA FUNCION:
  - El array `a[]` tiene `n` elementos válidos, donde `n >= 0`.
  - El valor de `k` es un entero no negativo y representa la cantidad de elementos `true` que deben encontrarse en un tramo.
*/


int tramo_mas_corto(bool a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  - resul = longitud del tramo más corto del array `a[]` que contiene exactamente `k` valores `true`.
  - Si no existe tal tramo, resul = n + 1, indicando que no se encontró ningún tramo válido.
*/


 /*
DISEÑO DEL ALGORITMO:

Paso 1. Variables:
  - `i`: Índice izquierdo del tramo actual.
  - `j`: Índice derecho del tramo actual.
  - `cont`: Contador de elementos `true` dentro del tramo actual.
  - `min_len`: Almacena la longitud del tramo más corto que cumple la condición.

Paso 2. Invariante:
  Antes de cada iteración del bucle:
    - `cont` representa la cantidad de valores `true` en el tramo `a[i..j]`.
    - `min_len` contiene la longitud más corta de un tramo que contiene exactamente `k` valores `true` encontrada hasta ahora.
    - Para cualquier tramo que no cumple la condición `cont == k`, no se considera como candidato para `min_len`.

Paso 3. Inicialización:
  - `i = 0` y `j = 0` inician el tramo en el inicio del array.
  - `cont = 0` porque no se ha incluido ningún elemento en el tramo aún.
  - `min_len = n + 1` ya que inicialmente no hay tramos válidos.

Paso 4. Condición del bucle:
  - El bucle se ejecuta mientras `j < n`, es decir, el índice derecho del tramo no ha alcanzado el final del array.

Paso 5. Cuerpo del bucle:
  - Si `a[j]` es `true`, incrementa el contador `cont`.
  - Si `cont == k`, intenta minimizar `min_len` calculando la longitud del tramo actual.
  - Si el tramo actual contiene más de `k` valores `true` (por avanzar `j`), ajusta `i` hacia la derecha mientras mantiene la condición `cont == k`.

Paso 6. Justificación de que el algoritmo siempre termina:
  - El índice `j` avanza en cada iteración principal hasta que alcanza el final del array (`j = n`).
  - El índice `i` también avanza para reducir la longitud del tramo siempre que se cumpla `cont == k`.
  - Dado que ambos índices se limitan por `n`, el algoritmo siempre termina.

Paso 7. Complejidad:
  - Tiempo: O(n), ya que cada índice (`i` y `j`) recorre el array como máximo una vez.
  - Espacio: O(1), ya que solo utiliza un número constante de variables auxiliares.
*/

int tramo_mas_corto(bool a[], int n, int k) {
	int i = 0;
	int j = 0;
	int cont = 0;
	int min_len = n + 1;

	while (j < n) {
		if (a[j]) {
			cont++;
		}

		while (cont == k) {
			min_len = (j - i + 1 < min_len) ? j - i + 1 : min_len;
			if (a[i]) {
				cont--;
			}
			i++;
		}

		j++;
	}

	return min_len;
}

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA:
   NO MODIFICAR */


void lee_caso(int& n, bool a[], int& k) {
	cin >> n;
	if (n != -1) {
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			a[i] = bool(elem);
		}
		cin >> k;
	}
}

const int MAX_TAM = 100;
int main() {
	int n;
	bool a[MAX_TAM];
	int k;
	do {
		lee_caso(n, a, k);
		if (n != -1) {
			cout << tramo_mas_corto(a, n, k) << endl;
		}
	} while (n != -1);
}

