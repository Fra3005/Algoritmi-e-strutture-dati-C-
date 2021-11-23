/*
 * coda.h
 *
 *  Created on: 12 gen 2021
 *      Author: franc
 */

#ifndef CODA_H_
#define CODA_H_
#include "assert.h" //assert è un .h che gestisce gli errori restituendo un messaggio di errore

template<class T>
class Coda{
public:
	Coda(int);

	~Coda();

	bool codaVuota() const;
	T leggiCoda() const;

	void fuoriCoda();
	void inCoda(T elemento);
private:
	T * elementi;
	//testa è la posizione del primo elemento inserito nella coda, size è l'attuale lunghezza della coda, maxSize è la lunghezza massima che la coda può avere
	int testa, size, maxSize;
};

template<class T>
Coda<T>::Coda(int d){
	maxSize = d;
	elementi = new T [maxSize];
	size = 0;
	testa = 0;
}

template<class T>
Coda<T>::~Coda(){
	delete [] elementi;
}

template<class T>
bool Coda<T>::codaVuota()const{
	if(size==0)
		return true;
	else
			return false;
}

template<class T>
T Coda<T>::leggiCoda()const{
	assert(!codaVuota());
	return elementi[testa];
}

template<class T>
void Coda<T>::fuoriCoda(){
	assert(!codaVuota());
	//settiamo la nuova testa come a vecchia testa + 1 modulo maxSise, cosi facendo si ha sempre la posizione successiva alla testa precedente senza uscire dal vettore
	//e ritornando alla prima posizione quando si raggiunge la fine (ammesso ci sia spazio) questo perchè è una coda con vettore circolare
	testa = (testa+1) % maxSize;
	size--;
}

/*
 * fa il modulo di testa attuale + lunghezza attuale per inserire nella prossima posizione
 * infine incrementa dimensione attuale
 */
template<class T>
void Coda<T>::inCoda(T e){
	assert(size!=maxSize);
	elementi[(testa+size)%maxSize ] = e;
	size++;
}

#endif /* CODA_H_ */
