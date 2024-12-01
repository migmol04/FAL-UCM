/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se añade el nombre y apellidos,
el ejercicio no se corregirá (puntuará como 0).

*/
#include <iostream>

using namespace std;


const int MAX_PROCESOS = 100;

// Tipo para codificar los datos de entrada
// al problema
typedef struct {
	int t_procesamiento;  // Tiempo de procesamiento 'T' de los procesadores.
	// Cada procesador permite utizar, como máximo,
	// 'T' unidades de tiempo.
	int t_procesos[MAX_PROCESOS];  // Unidades de tiempo requeridas por cada proceso. 
	int b_procesos[MAX_PROCESOS];  // Beneficio reportado por cada proceso.
	int n;                         // Número de procesos 'N' (n <= MAX_PROCESOS).
} tEntrada;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del diseño del algoritmo. No
se tendrá en cuenta la codificación del algoritmo, a menos que
esté acompañada del diseño sistemático del mismo.
*/


/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Si estás utilizando algún criterio de poda adicional, explica detalladamente
	el criterio utilizado

(7) Análisis de casos

(7.1) Caso(s) base


(7.2) Caso(s) recursivos

(8) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/
void max_beneficio_rec(const tEntrada& entrada, int k, int benef_actual, int tiempo_p1, int tiempo_p2, int& max_beneficio) {
	if (k == entrada.n) { //Caso base
		if (benef_actual > max_beneficio) {
			max_beneficio = benef_actual;
		}
		return;
	}

	int max_beneficio_posible = 0;
	for (int i = 0; i < entrada.n; i++) {
		max_beneficio_posible += entrada.b_procesos[i];
	}

	//Si vemos que no obtenemos un beneficio mejor podamos
	if (benef_actual + max_beneficio_posible <= max_beneficio) {
		return;
	}

	
	max_beneficio_rec(entrada, k + 1, benef_actual, tiempo_p1, tiempo_p2, max_beneficio);  //No lo incluyo

	//Lo incluyo
	if (tiempo_p1 + entrada.t_procesos[k] <= entrada.t_procesamiento) {
		max_beneficio_rec(entrada, k + 1, benef_actual + entrada.b_procesos[k], tiempo_p1 + entrada.t_procesos[k], tiempo_p2, max_beneficio);
	}


	if (tiempo_p2 + entrada.t_procesos[k] <= entrada.t_procesamiento) {
		max_beneficio_rec(entrada, k + 1, benef_actual + entrada.b_procesos[k], tiempo_p1, tiempo_p2 + entrada.t_procesos[k], max_beneficio);
	}
}
int max_beneficio(const tEntrada& entrada) {
	int max_benef = 0;
	max_beneficio_rec(entrada, 0, 0, 0, 0, max_benef);
	return max_benef;
}

/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el código que sigue no se corregirán (puntuarán 0).

bool ejecuta_caso() {
	int t_procesamiento;
	int n_procesos;
	cin >> t_procesamiento >> n_procesos;
	if (t_procesamiento == 0 && n_procesos == 0) {
		return false;
	}
	else {
		tEntrada entrada;
		entrada.n = n_procesos;
		entrada.t_procesamiento = t_procesamiento;
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.t_procesos[p];
		}
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.b_procesos[p];
		}
		cout << max_beneficio(entrada) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}


