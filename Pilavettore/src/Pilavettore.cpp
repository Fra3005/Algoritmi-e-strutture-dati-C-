//============================================================================
// Name        : Pilavettore.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Pila.h"


int main() {
	Pila <int> pila1;
	int a =1;
	int b =2;
	int c =3;

	pila1.inPila(a);
	pila1.inPila(b);
	pila1.inPila(c);
	pila1.inPila(a);
	pila1.inPila(b);
	pila1.inPila(c);

	pila1.fuoriPila();



	pila1.stampa();
	pila1.stampa();



}
