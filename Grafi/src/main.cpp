/*
 * main.cpp
 *
 *  Created on: 30 gen 2021
 *      Author: franc
 */

#include"GrafoMat.h"


int main(){

	GrafoMat<int, int> grafo(10);
	GrafoMat<int,int>::Nodo n1;
	grafo.insNodo(n1);
	grafo.scriviEtichetta(n1, 1);
	grafo.stampaDFS(n1);



}

