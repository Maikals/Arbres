#include "utils.PRO2"
#include "Arbre.hpp"

void escriure_arbre (Arbre<pair<int,bool> >& a)
{
	if (not a.es_buit()) {
		pair<int,bool> x = a.arrel();
		cout << x.first << " ";
		Arbre <pair<int,bool> > a1, a2;
		a.fills(a1, a2);
		escriure_arbre (a1);
		escriure_arbre (a2);
		a.plantar (x, a1, a2);
	}
}

Arbre<pair<int,bool> > ie_emparejar(Arbre<pair<int,bool> >& a1, Arbre<pair<int,bool> >& a2, int& max, int& n1, int& n2, int& inter, bool& activa1, bool& activa2) {
	Arbre <pair<int,bool> > a;
	if (not a1.es_buit() and not a2.es_buit()) {
		++inter;
		++n1;
		++n2;
		pair <int, bool> x = a1.arrel();
		if (a2.arrel().second) x.second = true;
		Arbre<pair<int,bool> > a11, a12, a21, a22, a31, a32;
		a1.fills(a11, a12);
		a2.fills(a21, a22);
		a31 = ie_emparejar(a11, a21, max, n1, n2, inter, activa1, activa2);
		a32 = ie_emparejar(a12, a22, max, n1, n2, inter, activa1, activa2);
		a.plantar(x, a31, a32); 
	}
	else if (not a1.es_buit()) {
		++n1;
		pair <int, bool> x = a1.arrel();
		Arbre<pair<int,bool> > a11, a12, a31, a32;
		a1.fills(a11, a12);
		a31 = ie_emparejar(a11, a2, max, n1, n2, inter, activa1, activa2);
		a32 = ie_emparejar(a12, a2, max, n1, n2, inter, activa1, activa2);
		if (x.second) activa1 = true;
		if (activa1) a.plantar(x, a31, a32);
	}
	else if (not a1.es_buit()) {
		++n2;
		pair <int, bool> x = a2.arrel();
		Arbre<pair<int,bool> > a21, a22, a31, a32;
		a2.fills(a21, a22);
		a31 = ie_emparejar(a1, a21, max, n1, n2, inter, activa1, activa2);
		a32 = ie_emparejar(a1, a22, max, n1, n2, inter, activa1, activa2);
		if (x.second) activa2 = true;
		if (activa2) {
			++max;
			pair<int, bool> p (max, x.second);
			a.plantar(p, a31, a32);
		}
	}
	return a;
}

Arbre<pair<int,bool> > emparejar (Arbre<pair<int,bool> >& a1, Arbre<pair<int,bool> >& a2, int max1) {
	Arbre<pair<int,bool> > a3;
	a3.a_buit();
	int n1, n2, inter;
	n1 = n2 = inter = 0;
	bool activa1, activa2;
	activa1 = activa2 = false;
	Arbre<pair<int,bool> > aux = ie_emparejar(a1, a2, max1, n1, n2, inter, activa1, activa2);
	if ((n1+n2)/4 >= inter) a3 = aux; 
	return a3;
}

void llegir_arbre(Arbre <pair <int, bool> >& a, int& max) {
	int x = readint();
	if (x != -1) {
		if (x > max) max = x;
		bool b = readbool();
		Arbre <pair<int,bool> > a1, a2;
		llegir_arbre(a1, max);
		llegir_arbre(a2, max);
		pair<int,bool> p (x, b);
		a.plantar(p, a1, a2);
	}
}

int main() {
	int max1, max2;
	max1 = max2 = -1;
	Arbre<pair<int,bool> > a1, a2;
	llegir_arbre(a1, max1);
	llegir_arbre(a2, max2);
	Arbre <pair<int,bool> > a3 = emparejar(a1, a2, max1);
	escriure_arbre(a3);
	if (a3.es_buit()) cout << "no compatible";
	cout << endl;
}