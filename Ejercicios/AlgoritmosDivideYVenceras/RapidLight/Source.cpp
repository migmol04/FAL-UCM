/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:


Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/

#include <iostream>

using namespace std;


/*
(1) GENERALIZACION (EN CASO DE QUE PROCEDA): Entradas y salidas

(2) DISE�O

(3) TERMINACI�N:

(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE:

(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO:

*/

/*
(1) GENERALIZACIÓN:

1.1. Entradas:
- `etapas[]`: (int[], entrada) Array de enteros que representa las distancias de las etapas del viaje.
- `n`: (int, entrada) Número de etapas.
- `repostajes_permitidos`: (int, entrada) Número máximo de repostajes permitidos.
- `capacidad`: (int, entrada, solo en `puedeCompletarViaje`) Capacidad del tanque para un intento dado.

1.2. Salidas:
- `puedeCompletarViaje`: Devuelve `true` si es posible completar el viaje con la capacidad del tanque dada, respetando el número de repostajes permitidos. Devuelve `false` en caso contrario.
- `min_capacidad`: Devuelve el valor mínimo de capacidad necesaria del tanque para completar el viaje respetando los repostajes permitidos.

(2) DISEÑO:

2.1. Función `puedeCompletarViaje`:
- Variables:
  - `repostajes`: Contador del número de repostajes realizados.
  - `combustible_actual`: Cantidad de combustible restante en el tanque.
- Lógica:
  - Recorrer cada etapa y verificar si se puede cubrir con el combustible actual.
  - Si no es posible, realizar un repostaje y restar el consumo de la etapa del nuevo tanque lleno.
  - Si el número de repostajes excede `repostajes_permitidos`, devolver `false`.

2.2. Función `min_capacidad`:
- Variables:
  - `izquierda`: Inicializado con la etapa más larga (mínima capacidad posible).
  - `derecha`: Inicializado con la suma de todas las etapas (máxima capacidad posible).
  - `resultado`: Almacena la capacidad mínima válida.
- Lógica:
  - Realizar una búsqueda binaria sobre el rango `[izquierda, derecha]`.
  - En cada iteración:
    - Calcular la capacidad media y verificar con `puedeCompletarViaje`.
    - Si es válida, actualizar `resultado` y reducir el rango superior.
    - Si no es válida, aumentar el rango inferior.
  - Devolver `resultado` al terminar la búsqueda binaria.

(3) TERMINACIÓN:
- `puedeCompletarViaje`:
  - El bucle avanza por cada etapa del viaje y siempre termina en `n` iteraciones.
- `min_capacidad`:
  - La búsqueda binaria reduce el rango `[izquierda, derecha]` a la mitad en cada iteración. El algoritmo siempre termina cuando el rango se colapsa.

(4) IMPLEMENTACIÓN POR INMERSIÓN:
- La función `min_capacidad` utiliza `puedeCompletarViaje` para verificar si una capacidad dada es suficiente. Esto permite resolver el problema utilizando búsqueda binaria.

(5) DETERMINACIÓN DEL COSTE DEL ALGORITMO EN EL PEOR CASO:

5.1. Coste de `puedeCompletarViaje`:
- Complejidad temporal: O(n), ya que recorre todas las etapas del viaje.

5.2. Coste de `min_capacidad`:
- Realiza una búsqueda binaria en el rango `[max_etapa, suma_total]`, cuyo tamaño es O(log suma_total).
- En cada iteración, llama a `puedeCompletarViaje` que tiene coste O(n).

5.3. Coste total:
- Complejidad total: O(n * log suma_total), donde `n` es el número de etapas y `suma_total` es la suma de todas las distancias de las etapas.

*/


bool puedeCompletarViaje(int etapas[], int n, int repostajes_permitidos, int capacidad) {
    int repostajes = 0;
    int combustible_actual = capacidad;

    for (int i = 0; i < n; ++i) {
        if (etapas[i] > capacidad) {
            return false;
        }

        if (combustible_actual >= etapas[i]) {
            combustible_actual -= etapas[i];
        }
        else {
         
            repostajes++;
            if (repostajes > repostajes_permitidos) {
                return false;
            }
          
            combustible_actual = capacidad - etapas[i];
        }
    }
    return true;
}

int min_capacidad(int etapas[], int n, int repostajes_permitidos) {
    int suma_total = 0;
    int max_etapa = 0;

    for (int i = 0; i < n; ++i) {
        suma_total += etapas[i];
        if (etapas[i] > max_etapa) {
            max_etapa = etapas[i];
        }
    }

    int izquierda = max_etapa;
    int derecha = suma_total;
    int resultado = suma_total;

    while (izquierda <= derecha) {
        int media = (izquierda + derecha) / 2;

        if (puedeCompletarViaje(etapas, n, repostajes_permitidos, media)) {
            resultado = media;
            derecha = media - 1;
        }
        else {
            izquierda = media + 1;
        }
    }

    return resultado;
}


const int MAX_ETAPAS = 100000;


bool ejecuta_caso() {
	static int v[MAX_ETAPAS];
	int n, c;
	cin >> n;
	if (n == -1) return false;
	else {
		cin >> c;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		cout << min_capacidad(v, n, c) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}
