
#include <iostream>
using namespace std;

const int MAX_OBJS = 20;

// Lista con los objetos a portar 
typedef struct {
	int tamanios[MAX_OBJS];  // Array en cuyas primeras posiciones se guardan
	// los tamaños de los objetos
	int n_objetos;           // Numero de objetos
} tObjetos;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/
void min_numero_de_cajas_rec(const tObjetos& objetos, int capacidad_caja, int cajas[], int num_cajas, int k, int& minCajas) {
    if (num_cajas >= minCajas) {  //poda
        return; 
    }

    if (k == objetos.n_objetos) {
        if (num_cajas < minCajas) {
            minCajas = num_cajas;

        }
        return;
    }


    for (int i = 0; i < num_cajas; ++i) {
        if (cajas[i] + objetos.tamanios[k] <= capacidad_caja) {
            cajas[i] += objetos.tamanios[k];
            min_numero_de_cajas_rec(objetos, capacidad_caja, cajas, num_cajas, k + 1, minCajas);
            cajas[i] -= objetos.tamanios[k];
        }
    }

    cajas[num_cajas] = objetos.tamanios[k];
    min_numero_de_cajas_rec(objetos, capacidad_caja, cajas, num_cajas + 1, k + 1, minCajas);
    cajas[num_cajas] = 0;
}

int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja) {
    int minCajas = objetos.n_objetos; 
    int cajas[MAX_OBJS] = { 0 }; 
    min_numero_de_cajas_rec(objetos, capacidad_caja, cajas, 0, 0, minCajas);
    return minCajas;
}


bool ejecuta_caso() {
	int capacidad;
	cin >> capacidad;
	if (capacidad != -1) {
		tObjetos objetos;
		cin >> objetos.n_objetos;
		for (int i = 0; i < objetos.n_objetos; i++) {
			cin >> objetos.tamanios[i];
		}
		cout << min_numero_de_cajas(objetos, capacidad) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}