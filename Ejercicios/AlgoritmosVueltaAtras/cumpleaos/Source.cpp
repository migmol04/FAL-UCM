#include <iostream>
using namespace std;

const unsigned int MAX_NINIOS = 20; // maximo numero de ni�os
// el n�mero de sitios siempre
// ser� menor o igual que el
// n�mero de ni�os

// Representaci�n de la matriz de satisfacciones
typedef struct {
	int n_ninios;	// numero de ni�os.
	int n_sitios;	// numero de sitios
	int sat[MAX_NINIOS][MAX_NINIOS];  // la posici�n i,j representa la satisfaccion
	// que siente el ninio i si se le asigna el sitio j											   
} tMatrizSatisfacciones;


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

bool puede(const tMatrizSatisfacciones& sats, int num_tabu, int invitado, int j, int h) {
	int m = sats.n_sitios;
	if (invitado % m == j) {
		num_tabu = num_tabu + 1;
	}

	if ((sats.sat[invitado][j] > 0 && num_tabu <= m / 3)) {
		return true;
	}

	else {
		return false;
	}

}




void invitar(const tMatrizSatisfacciones& sats, int h, int num_tabu, bool sitios[], int invitado, int sat_actual, int& max_Actualidad) {
	if (invitado == sats.n_ninios) {
		if (sat_actual > max_Actualidad) {
			max_Actualidad = sat_actual;
		}
		return;
	}
	else {
			for (int j = 0; j < sats.n_sitios; j++) {
				if (!sitios[j] && puede(sats, num_tabu,invitado,  j, h)) {
					sitios[j] = true;
					invitar(sats, h, num_tabu, sitios, invitado + 1, sat_actual + sats.sat[invitado][j], max_Actualidad);
					sitios[j] = false;
					num_tabu = 0;

				}
			}
		
		if (invitado != h) {
			invitar(sats, h, num_tabu, sitios, invitado + 1, sat_actual, max_Actualidad);
		}

	}

}

int satisfaccion_maxima(const tMatrizSatisfacciones& sats, int h) {
	int max = 0;
	
	bool sitios[MAX_NINIOS] = { false };
	invitar(sats, h,0, sitios, 0, 0, max);
	return max;
	
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	tMatrizSatisfacciones sats;
	cin >> sats.n_ninios;
	if (sats.n_ninios != -1) {
		cin >> sats.n_sitios;
		int h;
		cin >> h;
		for (int sitio = 0; sitio < sats.n_sitios; sitio++) {
			for (int ninio = 0; ninio < sats.n_ninios; ninio++) {
				cin >> sats.sat[ninio][sitio];
			}
		}
		cout << satisfaccion_maxima(sats, h) << endl;
		return true;
	}
	else {
		return false;
	}
}


int main() {
	while (ejecuta_caso());
}