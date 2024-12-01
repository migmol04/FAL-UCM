#include <vector>
#include <iostream>
using namespace std;


const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
// Representaci�n de la matriz de afinidades
typedef struct {
	unsigned int n_clientes;                              // numero de clientes. 
	unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES];  // la matriz se almacena en las 'n_clientes' primeras filas,
	// 'n_clientes' primeras columnas	                                                      
} tMatrizAfinidad;


/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/
/*
A[][] matriz afinidad
N num clientes
c : cliente : Entrada
Emparejados[] : vector booleano
afinidad_Actual : entrada
max_afinidad : E/S


*/
int calcula_maxima_afinidad_posible(const tMatrizAfinidad& as, bool emparejados[MAX_CLIENTES]) {
    int max_afinidad_posible = 0;
    for (unsigned int i = 0; i < as.n_clientes; ++i) {
        for (unsigned int j = i + 1; j < as.n_clientes; ++j) {
            if (!emparejados[i] && !emparejados[j] && as.afinidades[i][j] > 0 && as.afinidades[j][i] > 0) {
                max_afinidad_posible += as.afinidades[i][j] + as.afinidades[j][i];
            }
        }
    }
    return max_afinidad_posible;
}

void maxima_afinidad_rec(const tMatrizAfinidad& as, int c, bool emparejados[MAX_CLIENTES], int afinidad_actual, int& max_afinidad) {
    if (c == as.n_clientes) { // Caso base
        if (afinidad_actual > max_afinidad) {
            max_afinidad = afinidad_actual;
        }
        return;
    }

    if (emparejados[c]) {
        maxima_afinidad_rec(as, c + 1, emparejados, afinidad_actual, max_afinidad);
    }
    else {
        for (int cliente = c + 1; cliente < as.n_clientes; cliente++) {
            if (!emparejados[cliente] && as.afinidades[c][cliente] > 0 && as.afinidades[cliente][c] > 0) {
                emparejados[c] = emparejados[cliente] = true;
                int nueva_afinidad = afinidad_actual + as.afinidades[c][cliente] + as.afinidades[cliente][c];
                int max_afinidad_posible = nueva_afinidad + calcula_maxima_afinidad_posible(as, emparejados);
                if (max_afinidad_posible > max_afinidad) {
                    maxima_afinidad_rec(as, c + 1, emparejados, nueva_afinidad, max_afinidad);
                }

                emparejados[c] = emparejados[cliente] = false;
            }
        }
    }
}

int maxima_afinidad(const tMatrizAfinidad& as) {
    bool emparejados[MAX_CLIENTES] = { false };
    int max_afinidad = 0;
    maxima_afinidad_rec(as, 0, emparejados, 0, max_afinidad);
    return max_afinidad;
}

void ejecuta_caso() {
	tMatrizAfinidad as;
	cin >> as.n_clientes;
	for (unsigned int i = 0; i < as.n_clientes; i++) {
		for (unsigned int j = 0; j < as.n_clientes; j++) {
			cin >> as.afinidades[i][j];
		}
	}
	cout << maxima_afinidad(as) << endl;
}


int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}