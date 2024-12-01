/*
N� DE GRUPO:
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA:

EN CASO DE QUE ALGUNO DE LOS MIEMBROS DEL
GRUPO NO HAYA PARTICIPADO EN LA PRACTICA,
INDICARLO AQUI, EXPLICANDO TAMBI�N EL MOTIVO:



*/

#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  El array `a[]` tiene `n` elementos válidos, donde `n >= 0`.

*/
bool divertida(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:

  Q: { resul = (  (PARATODO i:0<=i<n:(SUMA j:0<=j<=i:a[j])>=0) && ( (SUMA i:0<=i<n:a[i])=0 ) ) }

 */




bool divertida(const int a[], int n) {
	bool fun = true;
	int sum = 0;
	for (int i = 0; i < n && fun; i++) {
		sum = sum + a[i];
		if (sum < 0) {
			fun = false;
		}
	}

	if (sum != 0) {
		fun = false;
	}
	return fun;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
 - Tamaño del problema: `n`, el número de elementos en el array.
      - En el peor caso, el bucle recorre los `n` elementos del array y realiza operaciones constantes por cada elemento.
      - Por lo tanto, el tiempo de ejecución en el peor caso es O(n).
      - Espacialmente, el algoritmo utiliza solo variables auxiliares (`sum` y `fun`), lo que implica una complejidad espacial O(1).


*/




/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR! */

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
			if (divertida(a, n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n != -1);
}