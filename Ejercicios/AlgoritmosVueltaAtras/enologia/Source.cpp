
#include <iostream>
using namespace std;

/* Estructura utilizada para almacenar la información de un tema */
typedef struct {
	float tiempo_req;  // tiempo requerido para estudiar el tema
	float nota_prim;   // aportación a la nota de la primera parte
	float nota_sec;    // aportación a la nota de la segunda parte
} tInfoTema;



/*
DISEÑO DEL ALGORITMO

Para superar este ejercicio, aparte de programar el algoritmo, debes
describir aqui detalladamente su diseño (parámetros y variables utilizados,
y su cometido, cometido de los resultados devueltos por las funciones,
idea general del algoritmo, estructura de las soluciones,
análisis de casos, acciones realizadas para cada caso...)





*/

/* temas: Información sobre los temas de los que consta el examen (ver tInfoTema)
   num_temas: Numero de temas de los que consta el examen -su información aparece
			  al principio de info_temas
   tiempo_disponible: Tiempo total disponible para realizar el examen.
   Valor devuelto: La puntuación media máxima que se puede conseguir, o -1 si no
				   es posible aprobar el examen */


void mejor_puntuacion_rec(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible,
    int k, float nota_prim, float nota_sec, float tiempo_usado, float& max_puntuacion) {
    // Caso base
    if (k == num_temas || tiempo_usado > tiempo_disponible) {
        if (nota_prim >= 5.0 && nota_sec >= 5.0) {
            float media = (nota_prim + nota_sec) / 2.0;
            if (media > max_puntuacion) {
                max_puntuacion = media;
            }
        }
        return;
    }

    
    float max_nota_prim = nota_prim;
    float max_nota_sec = nota_sec;
    for (int i = k; i < num_temas; i++) {
        max_nota_prim += info_temas[i].nota_prim;
        max_nota_sec += info_temas[i].nota_sec;
    }

    // Si con una rama no llegamos a 5 cortamos
    if (max_nota_prim < 5.0 || max_nota_sec < 5.0) {
        return;
    }

    // No incluyo
    mejor_puntuacion_rec(info_temas, num_temas, tiempo_disponible, k + 1, nota_prim, nota_sec, tiempo_usado, max_puntuacion);

    //Lo incluyo
    if (tiempo_usado + info_temas[k].tiempo_req <= tiempo_disponible) {
        mejor_puntuacion_rec(info_temas, num_temas, tiempo_disponible, k + 1,
            nota_prim + info_temas[k].nota_prim, nota_sec + info_temas[k].nota_sec,
            tiempo_usado + info_temas[k].tiempo_req, max_puntuacion);
    }
}

float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible) {
    float maxima_puntuacion = -1;
    mejor_puntuacion_rec(info_temas, num_temas, tiempo_disponible, 0, 0.0, 0.0, 0.0, maxima_puntuacion);
    return maxima_puntuacion;
}

/* Código para leer y ejecutar casos de prueba: no debe modificarse */
const unsigned int MAX_TEMAS = 20;

bool procesa_caso() {
	int num_temas;
	tInfoTema info_temas[MAX_TEMAS];
	cin >> num_temas;
	if (num_temas != -1) {
		float tiempo_disponible;
		cin >> tiempo_disponible;
		for (int i = 0; i < num_temas; i++) {
			cin >> info_temas[i].tiempo_req;
			cin >> info_temas[i].nota_prim;
			cin >> info_temas[i].nota_sec;
		}
		cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}