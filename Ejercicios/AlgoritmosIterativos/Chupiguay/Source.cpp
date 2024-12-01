#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
El array `a[]` tiene `n` elementos válidos, donde `n >= 0`.


*/
int num_chupiguays(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
`resul` es igual a la cantidad de elementos `a[i]` que cumplen:
  - `i == 0` y `a[i] == 0`, o
  - `i > 0` y `suma_acumulada != 0` y `a[i] % suma_acumulada == 0`.




 */


 /*
 DISE�O DEL ALGORITMO:
 -- Especifica cada paso del dise�o en cada apartado indicado

 Paso 1. Variables
 contador_chupiguay: Almacena la cantidad de elementos que cumplen las condiciones para ser "chupiguays".
suma_acumulada: Almacena la suma acumulada de los elementos del array desde el índice 0 hasta el índice actual.


 Paso 2. Invariante
 Al inicio de cada iteración del bucle (índice i):
  1. suma_acumulada = sum(a[k] para k en [0, i-1])
     // suma_acumulada contiene la suma de los elementos desde a[0] hasta a[i-1].
  2. contador_chupiguay = 
     |{j en [0, i-1] : 
         (j == 0 && a[j] == 0) || 
         (j > 0 && suma_acumulada != 0 && a[j] % suma_acumulada == 0)
       }|
     // contador_chupiguay cuenta los elementos "chupiguays" encontrados entre a[0] y a[i-1].


 Paso 3. Inicializaci�n

Inicializa contador_chupiguay a 0 porque aún no se ha contado ningún elemento.
Inicializa suma_acumulada a 0 porque no hay suma acumulada al inicio.

 Paso 4. Condici�n del bucle, y c�digo tras el bucle

Condición del bucle: Itera desde i = 0 hasta i < n, procesando cada elemento del array.
Código tras el bucle: Devuelve contador_chupiguay, que contiene el total de elementos "chupiguays".

 Paso 5. Cuerpo del bucle

En cada iteración:

Comprueba si el elemento cumple las condiciones para ser "chupiguay".
Si lo cumple, incrementa contador_chupiguay.
Actualiza suma_acumulada sumando el valor de a[i].

 Paso 6. Justificaci�n de que el algoritmo siempre termina

El bucle siempre termina porque recorre un número fijo de elementos del array (n), que es finito.

 Paso 7. Complejidad

O(n) ya que se recorre el array una vez
 */


int num_chupiguays(const int a[], int n) {
	int contador_chupiguay = 0;
	int suma_acumulada = 0;
	if (a[0] == 0) {
		contador_chupiguay++;
	}
	for (int i = 0; i < n; i++) {
		if (i > 0 && suma_acumulada != 0 && a[i] % suma_acumulada == 0) {
			contador_chupiguay++;
		}
		suma_acumulada += a[i];
	}
	return contador_chupiguay;
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
			cout << num_chupiguays(a, n) << endl;
		}
	} while (n != -1);
}