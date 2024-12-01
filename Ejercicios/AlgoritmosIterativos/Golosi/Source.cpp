/*
N� GRUPO:

NOMBRE Y APELLIDOS DE LOS MIEMBROS DEL GRUPO:

SI ALGUNO DE LOS MIEMBROS NO HA PARTICIPADO,
INDICAR AQU� EL MOTIVO:

IMPORTANTE: Si no se a�adem estos datos, el ejercicio no
se corregir� (puntuar� 0)

*/

#include <iostream>

using namespace std;

/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada de la especificaci�n y el dise�o sistem�tico
del mismo.
*/


/*
   vcs: vector de valores cal�ricos.
   vns: vector de valores nutricionales.
   n: N�mero de chuches.
   u: Umbral cal�rico
*/
/*
PRECONDICION DE LA FUNCION:
  - `vcs` y `vns` son arrays de tamaño `n` con valores válidos.
  - `n >= 0`, es decir, el número de chuches no puede ser negativo.
  - `u >= 0`, ya que no tiene sentido trabajar con un umbral calórico negativo.
*/
int mejor_cajita(int vcs[], int vns[], int n, int u);
/*
POSTCONDICION DE LA FUNCION:
  - resul = máximo valor nutricional que se puede obtener de una selección
    continua de chuches del vector `vcs` tal que la suma calórica de esa
    selección no exceda el umbral `u`.
  - Si no hay selección válida (es decir, todas las combinaciones exceden
    el umbral calórico), entonces resul = -1.
*/
/*
DISEÑO DEL ALGORITMO:

Paso 1. Variables:
  - `suma_calorica`: Almacena la suma acumulada de calorías de la ventana actual.
  - `suma_nutricional`: Almacena la suma acumulada de valores nutricionales de la ventana actual.
  - `izq`: Índice izquierdo de la ventana deslizante.
  - `max`: Almacena el valor máximo nutricional encontrado que cumple con las restricciones.

Paso 2. Invariante:
  Antes de cada iteración del bucle:
    - `suma_calorica` es la suma de los elementos `vcs[izq]` a `vcs[der]`.
    - `suma_nutricional` es la suma de los elementos `vns[izq]` a `vns[der]`.
    - `max` es el mayor valor nutricional encontrado hasta el momento para ventanas cuyo valor calórico no exceda `u`.

Paso 3. Inicialización:
  - `suma_calorica = 0`: La suma de calorías comienza vacía.
  - `suma_nutricional = 0`: La suma nutricional comienza vacía.
  - `izq = 0`: El índice izquierdo apunta al inicio del vector.
  - `max = -1`: Inicialmente no hay selección válida, por lo que el máximo es -1.

Paso 4. Condición del bucle:
  - Se recorre el array desde el índice `der = 0` hasta `der < n`.

Paso 5. Cuerpo del bucle:
  - Añade el elemento actual al acumulador `suma_calorica` y `suma_nutricional`.
  - Si `suma_calorica > u`:
    - Reduce `suma_calorica` y `suma_nutricional` eliminando elementos desde el índice `izq`, y avanza `izq`.
  - Si la ventana actual cumple `suma_calorica <= u` y `suma_nutricional > max`:
    - Actualiza `max` con el valor nutricional de la ventana actual.

Paso 6. Código tras el bucle:
  - Al terminar el bucle, `max` contiene el mayor valor nutricional encontrado para ventanas válidas, o -1 si ninguna ventana cumple las restricciones.

Paso 7. Complejidad:
  - Tiempo: O(n), ya que cada elemento se procesa como máximo dos veces (una al entrar en la ventana y otra al salir).
  - Espacio: O(1), porque solo se usan variables auxiliares.
*/

int mejor_cajita(int vcs[], int vns[], int n, int u) {

	int suma_calorica = 0;
	int suma_nutricional = 0;
	int izq = 0;
	int max = -1;
	for (int der = 0; der < n; der++) {
		suma_calorica += vcs[der];
		suma_nutricional += vns[der];

		
		while (suma_calorica > u) {
			suma_calorica -= vcs[izq];
			suma_nutricional -= vns[izq];
			izq++;
		}

		
		if (suma_calorica <= u && suma_nutricional > max) {
			max = suma_nutricional;
		}
	}
	return max;
	
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

const static int MAX_CHUCHES = 1000000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		static int calorias[MAX_CHUCHES];
		static int nutricionales[MAX_CHUCHES];
		for (int i = 0; i < n; i++) {
			cin >> calorias[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> nutricionales[i];
		}
		int umbral;
		cin >> umbral;
		cout << mejor_cajita(calorias, nutricionales, n, umbral) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}