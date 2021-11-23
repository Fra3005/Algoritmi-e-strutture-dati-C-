/*
 * util_n_tree.h
 *
 *  Created on: 12 feb 2021
 *      Author: franc
 */

#ifndef UTIL_N_TREE_H_
#define UTIL_N_TREE_H_

#include "alberoN.h"
template<class T>
class util_n_tree{
public:
	typedef typename Albero<T>::Nodo Nodo;
	/* Restituisce il numero di foglie presenti nell'albero n-ario T */
	int n_leaf(const Albero< T > &);
	/* Restituisce il numero di nodi in T di livello k */
	int n_level(Albero< T> &, int k);
	void contaFoglie(Nodo,int*);
	void contaNodiK(Nodo , int*, int);



};

template<class T>
int util_n_tree<T>::n_leaf( const Albero<T> &albero){
	int valore=0;
	Nodo n = albero.radiceAlbero();
	contaFoglie(n,&valore);
	return valore;


}

template<class T>
void util_n_tree<T>::contaFoglie(Nodo n, int *k){
	if(n->getPrimoFiglio()==nullptr){
		*k= *k+1;

	}else{
		n  = n->getPrimoFiglio();
		while(n!=nullptr){
			contaFoglie(n, k);
			n=  n->getProxFratello();
		}

	}
}


template<class T>
int util_n_tree<T>::n_level(  Albero<T> &albero, int k){

int somma=0;
Nodo n= albero.radiceAlbero();
contaNodiK(n,&somma,k);

return somma;
}


template<class T>
void util_n_tree<T> ::contaNodiK(Nodo n, int *k, int livello){
	if(n->getLivello() ==livello){
		*k= *k +1;
	}
	n = n->getPrimoFiglio();
	while(n!=nullptr){
		contaNodiK(n,k,livello);
		n = n->getProxFratello();

	}

}



#endif /* UTIL_N_TREE_H_ */
