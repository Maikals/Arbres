#include "utils.PRO2"
#include "Arbre.hpp"

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

void llegir_arbre(Arbre <int>& a) {
	int x = readint();
	if (x != -1) {
		Arbre <int> a1, a2;
		llegir_arbre(a1);
		llegir_arbre(a2);
		a.plantar(x, a1, a2);
	}
}

int main() {
	Arbre<int> a;
}