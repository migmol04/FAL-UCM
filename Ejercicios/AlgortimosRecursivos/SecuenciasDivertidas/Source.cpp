/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
MIGUEL ANGEL MOLINA DE LA ROSA 
PABLO NIETO LOPEZ

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:


*/

#include<iostream>

using namespace std;


/* Representacion de los personajes */
typedef enum { PRINCESA, CABALLERO, DRAGON } tPersonaje;
struct Info {
	int princesas;
	int caballeros;
	int dragones;
	bool esDivertida;
};
/*
(1) GENERALIZACION (EN CASO DE QUE PROCEDA): Entradas y salidas
La función es_divertida toma un array de tPersonaje y su tamaño como entrada. La salida es un valor booleano que indica si la secuencia de personajes es divertida o no.

(2) DISE�O
Divide el array en dos mitades y resuelve el problema de forma recursiva para cada mitad. Las soluciones para las mitades se combinan para obtener la solución para todo el array.

(3) TERMINACI�N:
la recursión termina cuando el tamaño del subarray se convierte en 0 (es decir, i > j). En este caso, la función devuelve un objeto Info con todos los campos establecidos en 0 y esDivertida establecido en verdadero.

(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE:
En este caso, el algoritmo se “sumerge” en el array de personajes, dividiéndolo en dos mitades hasta que llega a un solo elemento (el caso base). Nos fijamos en la llamada a es_divertida(personajes, 0, n - 1) y dentro de esta funcion a  es_divertida(personajes, i, m - 1);
es_divertida(personajes, m + 1, j);

(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO:
La complejidad de la función es O(n log n) porque cada llamada recursiva procesa la mitad del array y hay log n niveles de recursión.  Si empezamos con un array de tamaño n, después de un nivel de recursión, el tamaño del array se reduce a n/2. Después de dos niveles, se reduce a n/4, y así sucesivamente

*/
Info es_divertida(tPersonaje personajes[], int i, int j) {
	Info info;
	if (i > j) {
		info.princesas = info.caballeros = info.dragones = 0;
		info.esDivertida = true;
	}
	else if (i == j) {
		// Caso base: un solo elemento
		switch (personajes[i]) {
		case PRINCESA:
			info.princesas = 1;
			info.caballeros = 0;
			info.dragones = 0;
			break;
		case CABALLERO:
			info.princesas = 0;
			info.caballeros = 1;
			info.dragones = 0;
			break;
		case DRAGON:
			info.princesas = 0;
			info.caballeros = 0;
			info.dragones = 1;
			break;
		}
		info.esDivertida = true;
	}
	else {
		// Caso recursivo: dividir el vector en dos
		int m = (i + j) / 2;
		Info izq = es_divertida(personajes, i, m - 1);
		Info der = es_divertida(personajes, m + 1, j);
		info.princesas = izq.princesas + der.princesas + (personajes[m] == PRINCESA ? 1 : 0);  //? es otra manera de ecribir if else de manera mas concisa
		info.caballeros = izq.caballeros + der.caballeros + (personajes[m] == CABALLERO ? 1 : 0);
		info.dragones = izq.dragones + der.dragones + (personajes[m] == DRAGON ? 1 : 0);
		info.esDivertida = izq.esDivertida && der.esDivertida && ((izq.dragones > der.caballeros && personajes[m] == CABALLERO) || (izq.dragones == der.caballeros && personajes[m] == PRINCESA) || (izq.dragones < der.caballeros && ((personajes[m] == DRAGON && info.princesas > 0) || (personajes[m] == PRINCESA && info.princesas == 1))));
	}
	return info;
}

bool es_divertida(tPersonaje personajes[], int n) {
	return es_divertida(personajes, 0, n - 1).esDivertida;
}
// NO MODIFICAR NADA A PARTIR DE AQUI

const int MAX_TAM = 1000000;
const int REPS = 500;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		static tPersonaje personajes[MAX_TAM];
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			personajes[i] = tPersonaje(p);
		}

		if (n == MAX_TAM) {
			for (int i = 0; i < REPS; i++) {
				es_divertida(personajes, n);
			}
		}
		if (es_divertida(personajes, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}