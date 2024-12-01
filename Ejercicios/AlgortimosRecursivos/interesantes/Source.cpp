
#include <iostream>
using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/
bool es_interesante_aux(int n, int sum , int sumLeft , int sumRight ) {
	if (n == 0) {
		return sum != 0;
	}
	else {
		int digit = n % 10;
		if (digit == 0 || sumLeft % digit != 0 || sumRight % digit != 0) {
			return false;
		}
		return es_interesante_aux(n / 10, sum + digit, sumLeft + digit, sum - digit);
	}
}


bool es_interesante(unsigned int n) {
	return es_interesante_aux(n, 0, 0, 0);
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}