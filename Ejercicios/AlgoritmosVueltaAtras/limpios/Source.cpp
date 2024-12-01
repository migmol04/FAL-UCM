

#include <iostream>

using namespace std;

typedef unsigned long long t_num;


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

void cuenta_limpios(int d, int alpha, int sum_digitos, int num_ds, t_num num_actual, 
	int s, t_num n, int& num_limpios) {
	

		for (int dig = 1; dig <= 9; dig++) {
			if (dig + sum_digitos > s) {
				return;
			}
			else {
				
				if ((num_actual * 10 + dig) < n && sum_digitos + dig <= s) {
					num_actual = num_actual * 10 + dig;
					sum_digitos += dig;
					if (dig != d) {
						cuenta_limpios(d, alpha, sum_digitos, num_ds, num_actual, s, n, num_limpios);
					}
					else {
						num_ds++;
						if (num_ds < alpha) {
							num_limpios++;
							cuenta_limpios(d, alpha, sum_digitos, num_ds, num_actual, s, n, num_limpios);
						}
						num_ds--;

					}
					sum_digitos -= dig;
					num_actual /= 10;
				} 
				
			}

		}

	}





int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
	int num_limpios = 0, k = 1;
	cuenta_limpios(d, alpha, 0, 0, 0, s, n, num_limpios);
	return num_limpios;
}



bool ejecuta_caso() {
	int d;
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		unsigned short alpha;
		unsigned int s;
		t_num n;
		cin >> alpha >> s >> n;
		cout << num_limpios(d, alpha, n, s) << endl;
		return true;
	}
}


int main() {
	while (ejecuta_caso());
}