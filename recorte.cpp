#include "utils.PRO2"
#include "Arbre.hpp"

void recorte (Arbre<int>& a) 
{
	int x = a.arrel();
	Arbre <int> a1, a2;
	a.fills(a1, a2);
	if (not a1.es_buit() or not a2.es_buit()) {
		if (not a1.es_buit()) recorte(a1);
		if (not a2.es_buit()) recorte(a2);
		a.plantar(x, a1, a2);
	} 
}

void llegir_arbre(Arbre <int>& a) {
	int x = readint();
	if (x != -1) {
		Arbre <int> a1, a2;
		llegir_arbre(a1);
		llegir_arbre(a2);
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

int main() {
	Arbre<int> a;
	llegir_arbre(a);
	recorte(a);
	escriure_arbre(a);
	cout << endl;
}