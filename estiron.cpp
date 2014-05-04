#include "utils.PRO2"
#include "Arbre.hpp"


void estiron (Arbre<int>& a, int& max) {
	int x = a.arrel();
	Arbre <int> a1, a2;
	a.fills(a1, a2);
	if (a1.es_buit() and a2.es_buit()) {
		Arbre <int> a11, a12, a21, a22;
		++max;
		a1.plantar (max, a11, a22);
		++max;
		a2.plantar (max, a21, a22);
		a.plantar (x, a1, a2);
	}
	else {
		if (not a1.es_buit()) estiron(a1, max);
		if (not a2.es_buit()) estiron(a2, max);
		a.plantar(x, a1, a2);
	} 
}

void escriure_arbre (Arbre<int>& a)
{
	if (not a.es_buit()) {
		int x = a.arrel();
		cout << x << " ";
		Arbre <int> a1, a2;
		a.fills(a1, a2);
		escriure_arbre (a1);
		escriure_arbre (a2);
		a.plantar (x, a1, a2);
	}
}

void llegir_arbre(Arbre <int>& a, int& max) {
	int x = readint();
	if (x != -1) {
		if (x > max) max = x;
		Arbre <int> a1, a2;
		llegir_arbre(a1, max);
		llegir_arbre(a2, max);
		a.plantar(x, a1, a2);
	}
}

int main() {
	int max = -1;
	Arbre<int> a;
	llegir_arbre (a, max);
	estiron(a, max);
	escriure_arbre(a);
	cout << endl;
}