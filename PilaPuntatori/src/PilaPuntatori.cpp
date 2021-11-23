//============================================================================
// Name        : PilaPuntatori.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "PilaPT.h"

int main() {

	Pila<int>  pila1;

	int a =1;
	int b =2;
	int c =23;

	pila1.inPila(a);
	pila1.inPila(b);
	pila1.inPila(c);


	//pila1.fuoriPila();
	cout<<pila1;
	cout<<pila1;


}
