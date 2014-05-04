#include "utils.PRO2"
#include "Arbre.hpp"

void llegir_arbre(Arbre <int>& a) {
	int x = readint();
	if (x != -1) {
		Arbre <int> a1, a2;
		llegir_arbre(a1, a2);
		a.plantar(x, a1, a2);
	}
}

int main() {
	Arbre<int> a;
}