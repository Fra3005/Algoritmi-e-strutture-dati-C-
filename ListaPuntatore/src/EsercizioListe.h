/*
 * EsercizioListe.h
 *
 *  Created on: 8 feb 2021
 *      Author: franc
 */

#ifndef ESERCIZIOLISTE_H_
#define ESERCIZIOLISTE_H_

#include "list_vector.h"
#include "coda.h"
#include <string.h>
using namespace std;

class eo_strings {
public:
// inserisce inserisce una stringa nella corrispondente lista
	void inserisci(string s);
// rimuove la stringa dalla corrispondente lista
	void rimuovi(string s);
// rimuove le stringhe di lunghezza pari che iniziano con il carattere c
	void rimuovi(char c);
// restituisce il numero di stringhe di lunghezza pari
	int freq_pari();
// visualizza le stringhe di lunghezza dispari ordinate per lunghezza
	void visualizza_dispari();
	void stampa();
	eo_strings();
	int minimo();
	int par();
	int disp();
private:
	List_vector<string> pari;
	List_vector<string> dispari;
	int dimensione_pari ;
	int dimensione_disp ;
};

eo_strings :: eo_strings(){
	dimensione_pari=0;
	dimensione_disp=0;
}

void eo_strings::inserisci(string s) {

	if (s.size() % 2 == 0) {
		if (pari.empty()) {
			pari.insert(s, pari.begin());
			dimensione_pari++;

		} else {
			pari.insert(s, dimensione_pari);
			dimensione_pari++;
		}

	}

	if (s.size() % 2!=0) {
		if (dispari.empty()) {
			dispari.insert(s, dispari.begin());
			dimensione_disp++;
		} else  {

			dispari.insert(s, dimensione_disp);
			dimensione_disp++;
		}
	}

}

int eo_strings:: par(){
	return dimensione_pari;
}
int eo_strings:: disp(){
	return dimensione_disp;
}

void eo_strings::rimuovi(string s) {
	if (s.size() % 2 == 0) {
		for (int i=0; i<=dimensione_pari; i++){
			if(pari.read(i) == s){
				pari.erase(i);
				dimensione_pari--;
			}


		}


	}else {
		for(int i =0; i<=dimensione_disp; i++){
			if(dispari.read(i) == s){
				dispari.erase(i);
				dimensione_disp--;
			}
		}
	}

}



void eo_strings::rimuovi(char c) {
	for (int i = 0; i <= dimensione_pari; i++) {

		if (pari.read(i).find(c,i)) {
			pari.erase(i);
		}
	}

}

void eo_strings::visualizza_dispari(){


}

int eo_strings::minimo(){
	int j=dispari.read(dispari.begin()).length();
	for(int i=1; i<=dimensione_disp; i++){
		if(j>dispari.read(i).length()){
			j = dispari.read(i).length();
		}
	}
	return j;

}




void eo_strings::stampa() {
	cout << pari << endl;
	cout << dispari << endl;
}

#endif /* ESERCIZIOLISTE_H_ */
