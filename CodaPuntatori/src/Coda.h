/*
 * Coda.h
 *
 *  Created on: 23 dic 2020
 *      Author: franc
 */

#ifndef CODA_H_
#define CODA_H_
#include "cella.h"
#include "CodaAstratta.h"
using std::ostream;
template<class T>
class codaPunt: public coda<T, cella<T>*> {
public:
	typedef typename coda<T, cella<T>*>::posizione posizione;
	typedef typename coda<T, cella<T>*>::tipoelem tipoelem;

	codaPunt();
	~codaPunt();

//metodi

	void creaCoda();
	tipoelem leggiCoda()const;
	void inCoda(tipoelem);
	void fuoriCoda();
	bool codaVuota();

private:
	posizione testa;
	posizione coda;

};

template<class T>
codaPunt<T> :: codaPunt(){
	testa = NULL;
	coda = NULL;

}

template <class T>
codaPunt <T> :: ~codaPunt(){
	while (!codaVuota()){
		fuoriCoda();
	}
	delete testa;
	delete coda;

}

template<class T>
void codaPunt<T> :: creaCoda(){

	testa =0;
	coda =0;

}



template <class T>
typename codaPunt<T> :: tipoelem codaPunt <T> :: leggiCoda()const{
	return testa->get_elemento();


}


template<class T>
void codaPunt<T> :: inCoda(tipoelem a){
	if (codaVuota()){
		testa->set_elemento(a);

	}else {
		coda->set_elemento(a);
		coda++;
	}


}


template<class T>
void codaPunt<T> :: fuoriCoda(){
	posizione temp;
	if(!codaVuota()){

	temp = testa;
	testa->successivo();

	delete temp;
	}else{
		cout<<"codavuota";
	}


}


template<class T>
bool codaPunt<T>:: codaVuota(){
	testa = NULL;
	coda = NULL;

}


template < class T>
ostream& operator<<(ostream& os, codaPunt<T> &l){

	codaPunt<T> tmp (l);



  os << " [ " ;
  while (! (tmp.codaVuota ())) {
   os <<tmp. leggiCoda ();
   tmp.fuoriCoda ();
   if ( tmp.leggiCoda()) {
      os << " , " ;
    }

  }
  os << " ]  " ;
}




#endif /* CODA_H_ */
