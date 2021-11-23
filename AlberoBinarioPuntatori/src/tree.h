/*
 * tree.h
 *
 *  Created on: 27 dic 2020
 *      Author: franc
 */

#ifndef TREE_H_
#define TREE_H_

//#include "nodo.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <limits.h>
#include <vector>
using namespace std;


template<class T>
//struttura nodo per albero binario puntatore
struct nodo {

	T elemento = T();
	int livello = 0; // non necessario
	nodo<T> *padre ;
	nodo<T> *sx ;
	nodo<T> *dx ;



	nodo<T>& operator=(const nodo<T> &rhs) {
		elemento = rhs.elemento;
		livello = rhs.livello;
		padre = rhs.padre;
		sx = rhs.sx;
		dx = rhs.dx;
		return *this;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream &output, const nodo<T> &n) {
	output << "{" << n.elemento << "," << n.livello << "}";
	return output;
}

template<class T>
class tree {
public:

	tree();
	//tree(const tree<T>&);
	~tree();

	//osservatori
	typedef nodo<T>* Nodo;
	void create();
	bool empty() const;
	Nodo root() const;
	Nodo parent(Nodo) const;
	Nodo sx(Nodo) const;
	Nodo dx(Nodo) const;
	bool sx_empty(Nodo) const;
	bool dx_empty(Nodo) const;
	//modificatori
	void erase(Nodo);
	void write(Nodo, const T);
	T read(Nodo) const;
	void ins_sx(Nodo);
	void ins_dx(Nodo);
	void ins_root(Nodo);

	bool foglia(Nodo n);
	int livello(Nodo n);
	int profondita(Nodo n1);
	void is_heigth_balanced(Nodo n1, bool &ris);
	bool is_heigth_balanced(Nodo n1);
	int dimensione();
	void stampaSottoAlbero(Nodo n);
	void stampa();
	int altezzaMinimale( Nodo n);

private:
	Nodo albero;
	int size; //indicherà la dimensione dell'abero dopo ogni inserimento

};



template<class T>
tree<T>::tree() {
	albero = new nodo<T>;
	size = 0;
}

template<class T>
tree<T>::~tree() {
	erase(albero);
}

template<class T>
void tree<T>::create() {
	albero = new nodo<T>;
	size = 0;
}

template<class T>
bool tree<T>::empty() const {
	if (size == 0)
		return true;
	else {
		return false;
	}
}

template<class T>
nodo<T>* tree<T>::root() const {
	return tree<T>::albero;
}

template<class T>
nodo<T>* tree<T>::parent(Nodo n) const {
	return n->padre;
}

template<class T>
nodo<T>* tree<T>::sx(Nodo n) const {
	return n->sx;
}

template<class T>
nodo<T>* tree<T>::dx(Nodo n) const {
	return n->dx;
}

template<class T>
bool tree<T>::sx_empty(Nodo n) const {
	if (sx(n) == nullptr) {
		return true;
	} else {
		return false;
	}
}

template<class T>
bool tree<T>::dx_empty(Nodo n) const {
	if (dx(n) == nullptr) {
		return true;
	} else {
		return false;
	}
}

template<class T>
T tree<T>::read(Nodo n) const {
	return n->elemento;
}

template<class T>
void tree<T>::write(Nodo n, const T e) {
	n->elemento = e;
}

template<class T>
void tree<T>::erase(Nodo n) {
	if (n != nullptr) {
		erase(n->sx);
		erase(n->dx);
		delete n;
		size--;
	}
}
/*
 *
 */
template<class T>
void tree<T>::ins_root(Nodo n) {
	if (empty()) {
		albero = n;
		size++;
		albero->livello = 0;
	}
}
/*
 * controlla prima se non esiste gia un sinistro del nodo n
 */
template<class T>
void tree<T>::ins_sx(Nodo n) {

		if (sx_empty(n)) {
			n->sx = new nodo<T>;
			n->sx->padre = n;

			n->sx->dx = nullptr;
			n->sx->sx = nullptr;
			n->sx->livello = n->padre->livello + 1; // non serve
			size++;
		}

}
/*
 * controlla prima se non esiste gia un detro del nodo n
 */
template<class T>
void tree<T>::ins_dx(Nodo n) {

		if (dx_empty(n)) {
			n->dx = new nodo<T>;
			n->dx->padre = n;

			n->dx->dx = nullptr;
			n->dx->sx = nullptr;
			n->dx->livello = n->padre->livello + 1;
			size++;
		}

}

template<class T>
int tree<T>::dimensione() {
	return this->size;
}

template<class T>
bool tree<T>::foglia(Nodo n) {
	bool flag;
	if (sx_empty(n) && dx_empty(n)) {
		flag = true;
	}
	return flag;
}

template<class T>
int tree<T>::livello(Nodo n) {
	return n->livello;
}

template<class T>
int tree<T>::profondita(Nodo n1) {

	if (sx_empty(n1) && dx_empty(n1))
		return (0);
	int u = 0;
	if (!sx_empty(n1)) {
		u = profondita(sx(n1));
	}
	int v = 0;
	if (!dx_empty(n1)) {
		v = profondita(dx(n1));
	}
	if (u > v)
		return (u + 1);
	else
		return (v + 1);

}

template<class T>
void tree<T>::is_heigth_balanced(Nodo n1, bool &ris) {
	if (n1 != nullptr) {
		if (!sx_empty(n1) && dx_empty(n1)) {
			if (profondita(sx(n1)) - profondita(dx(n1)) < 1
					|| profondita(dx(n1)) - profondita(sx(n1)) < 1) {
				ris = true;
			} else {
				ris = false;
			}

			is_heigth_balanced(sx(n1), ris);
			is_heigth_balanced(dx(n1), ris);

		}
	}

}

template<class T>
bool tree<T>::is_heigth_balanced(Nodo n1) {

	bool ris = false;
	is_heigth_balanced(n1, ris);

	return ris;

}

template<class T>
void tree<T>::stampaSottoAlbero(Nodo n) {
	std::cout << "[" << n->elemento;
	if (!sx_empty(n))
		stampaSottoAlbero(sx(n));
	else
		std::cout << "NIL";
	std::cout << ", ";
	if (!dx_empty(n))
		stampaSottoAlbero(dx(n));
	else
		std::cout << "NIL";
	std::cout << " ]";

}

template<class T>
void tree<T>::stampa() {
	if (!empty())
		stampaSottoAlbero(root());
	else
		std::cout << "[]" << std::endl;
	std::cout << std::endl;

}

template<class T>
int tree<T> :: altezzaMinimale(Nodo n){
	int h1;
	int hr;
	if(n== nullptr){
		return 0;
	}else{
		if(!sx_empty(n)){
			h1 = altezzaMinimale(sx(n));
		}
		if(!dx_empty(n)){
			hr = altezzaMinimale(dx(n));
		}
	}
	return min(h1,hr)+1;


}




#endif /* TREE_H_ */
