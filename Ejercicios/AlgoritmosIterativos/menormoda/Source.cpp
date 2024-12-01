#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos



/*
PRECONDICION DE LA FUNCION:
  - El array `a[]` contiene `n` elementos válidos, donde `n >= 1`.
  - El array `a[]` está ordenado de forma no decreciente.
*/
int menor_moda(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  - resul = menor valor que tiene la mayor frecuencia en el array `a[]`.
  - Si hay varios valores con la misma frecuencia máxima, devuelve el menor de ellos.
*/


/*
DISEÑO DEL ALGORITMO:

Paso 1. Variables:
  - `contador`: Cuenta la frecuencia del elemento actual.
  - `maxContador`: Almacena la frecuencia máxima encontrada hasta ahora.
  - `candidato`: Elemento actual que se está evaluando.
  - `valor`: Almacena el menor valor con la frecuencia máxima.

Paso 2. Invariante:
  Antes de cada iteración del bucle:
    - `contador` contiene la frecuencia del elemento `candidato` desde su inicio hasta el índice actual.
    - `maxContador` contiene la mayor frecuencia encontrada hasta el momento.
    - `valor` es el menor elemento que tiene la frecuencia `maxContador`.

Paso 3. Inicialización:
  - `contador = 0`: La frecuencia del primer elemento no se ha contado aún.
  - `maxContador = 0`: Inicialmente no hay frecuencias evaluadas.
  - `candidato = a[0]`: Comienza con el primer elemento del array.
  - `valor = a[0]`: Por defecto, el primer elemento es el menor valor candidato.

Paso 4. Condición del bucle:
  - El bucle recorre el array desde el índice `i = 1` hasta `i < n`.

Paso 5. Cuerpo del bucle:
  - Si el elemento actual `a[i]` es igual al `candidato`, incrementa `contador`.
  - Si no, compara `contador` con `maxContador`:
    - Si `contador > maxContador`, actualiza `maxContador` y establece `valor = candidato`.
    - Si son iguales, `valor` no cambia porque ya es el menor valor.
  - Actualiza `candidato` y reinicia `contador` para el nuevo elemento.

Paso 6. Código tras el bucle:
  - Al salir del bucle, compara la frecuencia del último `candidato` con `maxContador` y actualiza `valor` si es necesario.

Paso 7. Complejidad:
  - Tiempo: O(n), ya que el array se recorre una sola vez.
  - Espacio: O(1), ya que solo se utilizan variables auxiliares constantes.
*/




int menor_moda(const int a[], int n) {
	int contador = 0;
	int maxContador = 0;
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
			candidato = a[i];
			contador = 0;
		}
	}
	if (contador > maxContador) {
		valor = candidato;
	}
	return valor;
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
			cout << menor_moda(a, n) << endl;
		}
	} while (n != -1);
}