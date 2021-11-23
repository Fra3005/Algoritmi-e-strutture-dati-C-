/*
 * codapt.h
 *
 *  Created on: 23 dic 2020
 *      Author: Utente
 */

#ifndef CODAPT_H_
#define CODAPT_H_

#import <iostream>

using std::cout;
using std::ostream;

template<class T>
struct NodoC {
	T elemento;
	NodoC<T> *succ;
};

template<typename T>
class Coda {
public:
	/* Definizioni*/
	typedef NodoC<T> * posizione;

	/* Costruttori*/
	// Default
	Coda();

	// Copia
	Coda(const Coda& );

	// Distruttore
	~Coda();

	/* Osservatori*/
	bool codaVuota() const;
	T leggiCoda() const;

	/* Modificatori*/
	void fuoriCoda();
	void inCoda(T elemento);

	/* Di Servizio*/
	void stampaCoda();

private:
	posizione testa;
	posizione fondo;
};

template< class T >
ostream& operator<<(ostream& os,  const Coda<T> &F){
	Coda  <T> tmp(F);
	os << "[";
	while(!(tmp.codaVuota())){
		os<<tmp.leggiCoda();
		tmp.fuoriCoda();
		if(!tmp.codaVuota()){
			os<<",";
		}
	}
	os << "] \n";

	return os;
}


//=================================================
// IMPLEMENTAZIONE
//=================================================

/* Costruttori*/

// Default
template<typename T> Coda<T>::Coda() {
	T ElementoNullo;
	testa = new NodoC<T>;
	fondo = new NodoC<T>;
	testa->elemento = ElementoNullo;
	testa = nullptr;
	fondo = nullptr;
}

template <class T> Coda<T>::Coda(const Coda<T>& origin){
	auto originNode = origin.testa;
	T ElementoNullo;
	//pila di supporto
	Coda codaSupp;
	testa = new NodoC<T>;
	fondo = new NodoC<T>;
	testa->elemento = ElementoNullo;
	testa = nullptr;
	fondo = nullptr;

	//copio i valori della pila originale in quella di supporto
	while(originNode){
		codaSupp.inCoda(originNode->elemento);
		originNode = originNode->succ;
	}

	//copio i valori dalla pila di supporto alla pila di output per rimettere gli elementi in ordine
	while(!(codaSupp.codaVuota())){
		this->inCoda(codaSupp.leggiCoda());
		codaSupp.fuoriCoda();
	}
}

// Distruttore
template<typename T> Coda<T>::~Coda() {
	while (testa != nullptr) {
		this->fuoriCoda();
	}
	delete testa;
	delete fondo;
}

/* Osservatori*/
template<typename T> bool Coda<T>::codaVuota() const {
	return testa == nullptr;
}

template<typename T> T Coda<T>::leggiCoda() const {
	if (testa != nullptr) {
		return testa->elemento;
	} else {
		std::cout << "vuota ";
		T obj = T(); // creo un oggetto di tipo T inizializzato con valore di Default
		return obj; //stampo il valore di default in caso di coda vuota
	}
}

/* Modificatori*/
/*
 * vecchia testa viene associata tmp
 * testa punta a successiva
 * e vecchia testa viene eliminata
 */
template<typename T> void Coda<T>::fuoriCoda() {
	if (testa != nullptr) {
		Coda::posizione tmp;
		tmp = new NodoC<T>;
		tmp = testa;
		testa = testa->succ;
		delete (tmp);
	} else {
		return;
	}
}
/*
 * come per le pila anche qui vediamo se la coda è vuota o no
 * se è vuota fondo e testa in quel momento sono uguali
 * se non è vuota il successivo di vecchi fondo sarà nodo
 * e nodo poi diventerà il nuovo fondo
 */
template<typename T> void Coda<T>::inCoda(T elemento) {
	Coda::posizione nodo;
	nodo = new NodoC<T>;
	nodo->elemento = elemento;
	nodo->succ = nullptr;
	bool vuota = this->codaVuota();
	if (vuota) {
		testa = nodo;
		fondo = nodo;
	} else {
		Coda::posizione back;
		back = new NodoC<T>;
		back = fondo; //back prende l'indirizzo di fondo
		back->succ = nodo;
		fondo = nodo;
	}

}




#endif /* CODAPT_H_ */





