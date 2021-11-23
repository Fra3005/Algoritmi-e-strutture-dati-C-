#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "list_vector.h"

template<class P, class N>
	class Arco_ {
 public:
	N nodo1;
	N nodo2;
	P peso;
};


template<class E, class P, class N>
	class Grafo {
 public:
	typedef E Etichetta;
	typedef P Peso;
	typedef N Nodo;

	typedef Arco_<Peso, Nodo> Arco;
	typedef List_vector<Nodo*> ListaNodi;

	typedef typename List_vector<Nodo*>::position ListaNodiPos;
	typedef List_vector<Arco> ListaArchi;

	virtual bool vuoto() const = 0;
	virtual void insNodo(Nodo&) = 0;
	virtual void insArco(Nodo, Nodo&, Peso) = 0;
	virtual void cancNodo(Nodo) = 0;
	virtual void cancArco(Nodo, Nodo) = 0;
	//	virtual bool esisteNodo(Nodo) = 0;
	//	virtual bool esisteArco(Arco) = 0;
	virtual ListaNodi Adiacenti(Nodo) const = 0;
	virtual ListaNodi list_nodi() const = 0;
	virtual Etichetta leggiEtichetta(Nodo) const = 0;
	virtual void scriviEtichetta(Nodo, Etichetta) = 0;
	virtual Peso leggiPeso(Nodo, Nodo) const = 0;
	virtual void scriviPeso(Nodo, Nodo, Peso) = 0;

	virtual int numNodi() = 0;
	virtual int numArchi() = 0;
	virtual int inDegree(Nodo)	=0;
	virtual int OutDegree(Nodo)=0;
	virtual void BFS(Nodo)=0;
	virtual double meanOutDegree(Nodo)=0;
	virtual void findPath(Nodo& u,Nodo& D)=0;
	virtual  void stampaDFS(Nodo& u)=0;//algoritmo DFS
	virtual   void setVisitato(Nodo& u)=0;
	virtual   bool getVisitato(Nodo& u)=0;
	virtual   void setNotVisitato()=0;//inizializza a false tutti i visitati
	virtual bool trovaPercorso(Nodo&,Nodo&,bool&)=0;
	   virtual void stampaPercorso(Nodo&,Nodo&)=0;






	virtual ~Grafo(){};

};

#endif // GRAFO_H_INCLUDED
