#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*
PRECONDICION DE LA FUNCION:
  - El array `a[]` tiene `n` elementos válidos, donde `n >= 0`.
  - El valor de `k` es un entero no negativo y representa la capacidad máxima de la mochila.
*/

int llena_mochila(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  - resul = longitud del tramo más largo posible del array `a[]` cuya suma de elementos no exceda `k`.
  - Si no hay ningún tramo válido, el resultado será 0.
*/


 /*
DISEÑO DEL ALGORITMO:

Paso 1. Variables:
  - `i`: Índice actual que se mueve por el array.
  - `inicio`: Índice izquierdo del tramo actual.
  - `suma`: Suma acumulada de los elementos del tramo actual.
  - `lon`: Almacena la longitud del tramo más largo que cumple la condición.

Paso 2. Invariante:
  Antes de cada iteración del bucle:
    - `suma` representa la suma de los elementos `a[inicio]` a `a[i]`.
    - `lon` contiene la longitud del tramo más largo encontrado hasta el momento cuyo valor no exceda `k`.
    - Para cualquier tramo que exceda `k`, el índice `inicio` se incrementa y se ajusta la suma.

Paso 3. Inicialización:
  - `i = 0` y `inicio = 0` inician el tramo en el comienzo del array.
  - `suma = 0` porque aún no se han agregado elementos al tramo.
  - `lon = 0` porque inicialmente no se ha encontrado ningún tramo válido.

Paso 4. Condición del bucle:
  - El bucle se ejecuta mientras `i < n`, es decir, mientras queden elementos en el array por procesar.

Paso 5. Cuerpo del bucle:
  - Añade el elemento actual al acumulador `suma`.
  - Si `suma > k`, elimina elementos desde el índice `inicio` y avanza `inicio` hasta que la suma no exceda `k`.
  - Si el tramo actual cumple la condición `suma <= k`, incrementa la longitud del tramo (`lon`).

Paso 6. Justificación de que el algoritmo siempre termina:
  - El índice `i` avanza en cada iteración principal hasta que alcanza el final del array (`i = n`).
  - El índice `inicio` también avanza si la suma acumulada excede `k`, garantizando que el bucle no se repita infinitamente.

Paso 7. Complejidad:
  - Tiempo: O(n), ya que cada elemento del array se procesa como máximo dos veces (una al ser añadido a la suma y otra al ser eliminado).
  - Espacio: O(1), ya que solo se utilizan variables auxiliares constantes.
*/
int llena_mochila(const int a[], int n, int k) {
	int i = 0;
	int inicio = 0;
	int suma = 0;
	int lon = 0;
	while (i < n) {
		suma += a[i];
		if (suma > k) {
			suma -= a[inicio];
			inicio++;
		}
		else {
			lon++;
		}
		
		i++;
	}

	return lon;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

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
			int k;
			cin >> k;
			cout << llena_mochila(a, n, k) << endl;
		}
	} while (n != -1);
}