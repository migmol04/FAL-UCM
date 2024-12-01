/*
NOMBRE Y APELLIDOS:

N� USUARIO DOMJUDGE:

*/

#include <iostream>

using namespace std;

const int MAX_PERSONAS = 20;
const int MAX_VEHICULOS = 10;


// Datos de entrada
typedef struct {
	bool ha_bebido[MAX_PERSONAS];   // ha_bebido[i]: La persona i ha bebido
	int capacidad[MAX_VEHICULOS];   // capacidad[v]: N� de personas que caben en el veh�culo v 
	int n_personas;                 // N� total de personas en el clan
	int n_vehiculos;                // N� total de veh�culos
} tDatos;




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

bool puede(const tDatos& datos, int vehiculos[MAX_VEHICULOS], int borrachos[MAX_VEHICULOS], int v, int persona) {
    if (vehiculos[v] >= datos.capacidad[v]) 
        return false;
    if (datos.ha_bebido[persona]) {
        if (borrachos[v] + 1 > datos.capacidad[v] / 2) 
            return false;
    }
    return true;
}

void asignar(const tDatos& datos, int persona, int vehiculos[MAX_VEHICULOS], int borrachos[MAX_VEHICULOS], int& combinaciones, int no_borrachos_restantes) {
    if (persona == datos.n_personas) {
        for (int v = 0; v < datos.n_vehiculos; v++) {
            if (vehiculos[v] == 0) return; // No puede dejarse ning�n veh�culo vac�o
            if (vehiculos[v] > 0 && borrachos[v] == vehiculos[v]) return; // Debe haber al menos una persona no borracha
        }
        combinaciones++;
        return;
    }

    int vehiculos_sin_conductor = 0;
    for (int v = 0; v < datos.n_vehiculos; v++) {
        if (vehiculos[v] > 0 && borrachos[v] == vehiculos[v]) {
            vehiculos_sin_conductor++;
        }
    }

    if (vehiculos_sin_conductor > no_borrachos_restantes) {
        return; // Poda: m�s veh�culos sin conductor que no borrachos restantes
    }

    for (int v = 0; v < datos.n_vehiculos; v++) {
        if (puede(datos, vehiculos, borrachos, v, persona)) {
            vehiculos[v]++;
            if (datos.ha_bebido[persona]) {
                borrachos[v]++;
            }
            else {
                no_borrachos_restantes--;
            }

            if (no_borrachos_restantes >= 0) {
                asignar(datos, persona + 1, vehiculos, borrachos, combinaciones, no_borrachos_restantes);
            }

            vehiculos[v]--;
            if (datos.ha_bebido[persona]) {
                borrachos[v]--;
            }
            else {
                no_borrachos_restantes++;
            }
        }
    }
}

int num_asignaciones(const tDatos& datos) {
    int combinaciones = 0;
    int vehiculos[MAX_VEHICULOS] = { 0 };
    int borrachos[MAX_VEHICULOS] = { 0 };
    int no_borrachos_restantes = 0;

    for (int i = 0; i < datos.n_personas; i++) {
        if (!datos.ha_bebido[i]) no_borrachos_restantes++;
    }

    asignar(datos, 0, vehiculos, borrachos, combinaciones, no_borrachos_restantes);
    return combinaciones;
}


bool ejecuta() {
	tDatos datos;
	cin >> datos.n_vehiculos;
	if (datos.n_vehiculos == -1) return false;
	cin >> datos.n_personas;
	for (int v = 0; v < datos.n_vehiculos; v++) {
		int bebe;
		cin >> datos.capacidad[v];
	}
	for (int p = 0; p < datos.n_personas; p++) {
		int bebe;
		cin >> bebe;
		if (bebe == 0) {
			datos.ha_bebido[p] = false;
		}
		else {
			datos.ha_bebido[p] = true;
		}
	}
	cout << num_asignaciones(datos) << endl;
	return true;

}


int main() {
	while (ejecuta());
}