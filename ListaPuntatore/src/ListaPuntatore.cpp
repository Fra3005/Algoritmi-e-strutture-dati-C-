//============================================================================
// Name        : ListaPuntatore.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//#include "Linked_list.h"
//#include "Lista_puntatori_ordinata.h"
#include "EsercizioListe.h"
#include "list_vector.h"
#include <string>
int main() {

	/*Linked_list <int> list1;


	int b =1;

	list1.insert(1, list1.begin());
	list1.insert(b, list1.begin());
	list1.insert(1, list1.begin());
	list1.insert(1, list1.begin());
	cout<<list1;
	cout<<list1.palindroma();
*/

	eo_strings lista;
	List_vector<string> list3;



	string a = "aaaa";
	string b = "ciao";
	string c = "bbbbb";
	string d = "cicicicia";
	string r = "adsfreg";

	//list3.insert(a, list3.begin());

	lista.inserisci(a);
	lista.inserisci(b);
	lista.inserisci(c);
	lista.inserisci(d);
	lista.inserisci(r);
	lista.visualizza_dispari();
	//cout<<lista.minimo();
	lista.stampa();









}
