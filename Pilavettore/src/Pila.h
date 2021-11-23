/*
 * Pila.h
 *
 *  Created on: 23 dic 2020
 *      Author: franc
 */

#ifndef PILA_H_
#define PILA_H_
#import <iostream>

using std::cout;
using std::ostream;

template<class T>
class Pila {

public:
	typedef T elementi;
	//costruttori
	Pila();
	~Pila();

	//modificatori
	void creaPila();
	void inPila(elementi);
	void fuoriPila();

	//osservatori

	bool pilaVuota() const;
	T leggiPila();
	void stampa();

private:
	elementi *el;
	int testa;
	int dimensione = 100;

};

//definizione costruttori

template<class T>

Pila<T>::Pila() {
	el = new elementi[dimensione];
	creaPila();
}

template<class T>
Pila<T>::~Pila() {
	delete[] el;
}

template<class T>
void Pila<T>::creaPila() {
	testa = 0;
}

template<class T>
bool Pila<T>::pilaVuota() const {
	return testa == 0;
}

template<class T>
void Pila<T>::inPila(elementi e) {
	if (testa != dimensione) {
		el[testa] = e;
		testa++;
	} else {
		cout << "raggiunta capacita massima";
	}

}

template<class T>
void Pila<T>::fuoriPila() {

	testa -- ;

}

template<class T>
T Pila<T>::leggiPila() {
	testa--;
	return el[testa];

}

template<class T>
void Pila<T>::stampa() {
	int a = 0;
	if (!pilaVuota()) {
		cout << "[";
		while (a <= testa - 1) {
			cout << el[a];
			a++;
			if (a <= testa - 1) {
				cout << ",";
			}
		}
		cout << "]";
	} else {
		cout << "pila vuota";
	}

}
/*
 template < class T>
 ostream& operator<<(ostream& os, Pila<T> &l){

 os << " [ " ;
 while (! (l.pilaVuota ())) {
 os <<l. leggiPila ();
 l.fuoriPila ();
 if ( l.leggiPila()) {
 os << " , " ;
 }

 }
 os << " ]  " ;
 }
 */

#endif /* PILA_H_ */
