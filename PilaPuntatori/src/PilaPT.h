/*
 * PilaPT.h
 *
 *  Created on: 22 dic 2020
 *      Author: franc
 */

#ifndef PILAPT_H_
#define PILAPT_H_
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
template <class T>
class Pila;
template <class T>

struct Nodo {
	T e;
	Nodo <T> *prev;
};


template <class T>

class Pila{
public:
	typedef Nodo <T> *posizione;
	typedef T tipolemen;
	Pila();
	~Pila();
	Pila(const Pila&);

	//metodi

	bool Pilavuota() const;
	T leggiPila()const ;

	//modificatori
	void fuoriPila() ;
	void inPila(T);
	void stampaPila() const ;




private:
	posizione pila;


};

//costruttori distruttori



template<class T>
Pila <T> :: Pila(){
	pila = new Nodo<T>;
	pila =nullptr;

}


template<class T>
Pila <T> :: ~Pila(){
	while(pila != nullptr){
		this->fuoriPila();
	}

	delete pila;
}

template <class T>
Pila<T>::Pila(const Pila<T>& origin){
  auto originNode = origin.pila;
  T ElementoNullo;
  //pila di supporto
  Pila pilaSupp;
  pila = new Nodo<T>;
  pila->e = ElementoNullo;
  pila = nullptr;

  //copio i valori della pila originale in quella di supporto
  while(originNode){
    pilaSupp.inPila(originNode->e);
    originNode = originNode->prev;
  }

  //copio i valori dalla pila di supporto alla pila di output per rimettere gli elementi in ordine
  while(!(pilaSupp.Pilavuota())){
    this->inPila(pilaSupp.leggiPila());
    pilaSupp.fuoriPila();
  }
}







//osservatori


template<class T>
bool Pila <T> :: Pilavuota()const{
	return pila == nullptr;
}



template<class T>
 T Pila<T> :: leggiPila()const {

	if(pila!= nullptr){
		return pila->e;
	}
	else{
		T obj =T();
		return obj;
	}

}


/* Modificatori*/
template <class T>
void Pila<T>::fuoriPila() {
  // E SE CANCELLO QUANDO NON CI SONO PIU ELEMENTI?

  if(pila!=nullptr){
    Pila::posizione tmp;
    tmp = new Nodo<T>;
    tmp = pila;
    pila=pila->prev;
    delete(tmp);
  }else{
    return;
  }
}




template<class T>
void Pila<T> :: inPila(T elemento){
	Pila :: posizione nodo;
	nodo = new Nodo<T>;
	nodo->e=elemento;
	nodo->prev=nullptr;

	if(Pilavuota()){
		pila = nodo;
	}
	else{
		Pila :: posizione tmp;
		tmp = new Nodo<T>;
		tmp = pila;
		nodo->prev=tmp;
		pila=nodo;
	}



}







template < class T>
ostream& operator<<(ostream& os, Pila<T> &l){

	Pila<T> tmp (l);



  os << " [ " ;
  while (! (tmp.Pilavuota ())) {
   os <<tmp. leggiPila ();
   tmp.fuoriPila ();
   if ( tmp.leggiPila()) {
      os << " , " ;
    }

  }
  os << " ]  " ;
}




#endif /* PILAPT_H_ */

