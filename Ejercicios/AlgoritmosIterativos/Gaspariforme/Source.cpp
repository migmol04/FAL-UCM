#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
 El array `a[]` tiene `n` elementos válidos, donde `n >= 0`.

*/
bool es_gaspariforme(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

resul = true si y solo si:
    1. La suma acumulada de los elementos desde `a[0]` hasta cualquier índice `i` siempre es estrictamente mayor que 0.
    2. La suma total de todos los elementos del array `a[]` es igual a 0.
  En cualquier otro caso, devuelve `false`.


 */


 /*
 DISE�O DEL ALGORITMO:
 -- Especifica cada paso del dise�o en cada apartado indicado

 Paso 1. Variables
  - `gaspariforme`: Booleano que indica si el array cumple las condiciones hasta el momento.
  - `suma`: Almacena la suma acumulada de los elementos procesados hasta el índice actual.


 Paso 2. Invariante
  Antes de cada iteración del bucle para el índice `i`:
    - `suma = SUMA(a[k] para k en [0, i])`
      // Contiene la suma acumulada desde el inicio hasta el índice `i`.
    - `gaspariforme = true` si todas las sumas acumuladas son estrictamente mayores que 0 hasta el índice `i-1`.
	  // Si alguna suma acumulada es menor o igual a 0, `gaspariforme` se establece a `false`.
	- Si la suma total de todos los elementos del array es igual a 0, `gaspariforme` se establece a `true`.


 Paso 3. Inicializaci�n

Inicializa `suma = 0` porque la suma acumulada al inicio es 0.
  - Inicializa `gaspariforme = true` porque se asume inicialmente que el array cumple las condiciones.

 Paso 4. Condici�n del bucle, y c�digo tras el bucle
- El bucle recorre el array completo desde `i = 0` hasta `i < n`.


 Paso 5. Cuerpo del bucle

 - Incrementa `suma` con el valor de `a[i]`.
 - Si `suma <= 0`, asigna `false` a `gaspariforme` porque el array ya no cumple la condición y el bucle continúa.

 Paso 6. Justificaci�n de que el algoritmo siempre termina
  - Al finalizar el bucle, verifica si `suma == 0`. Si es así, asigna `true` a `gaspariforme`.
  - Devuelve el valor de `gaspariforme`.


 Paso 7. Complejidad
  - Tiempo: \(O(n)\), ya que se recorre cada elemento del array una vez.
  - Espacio: \(O(1)\), ya que solo utiliza variables auxiliares.

 */



bool es_gaspariforme(const int a[], int n) {
	bool gaspariforme = true;
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += a[i];
		if (suma <= 0) {
			gaspariforme = false;
		}
	}

	if (suma == 0 ) {
		gaspariforme = true;
	}
	return gaspariforme;
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
			if (es_gaspariforme(a, n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n >= 0);
}