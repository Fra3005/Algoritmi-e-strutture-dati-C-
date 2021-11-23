/*
 * Lista_puntatori_ordinata.h
 *
 *  Created on: 21 dic 2020
 *      Author: franc
 */
#ifndef LISTA_PUNTATORI_ORDINATA_H_
#define LISTA_PUNTATORI_ORDINATA_H_

#include "linear_list.h"
#include <string>

template<class T>
class Ordered_list;

template<class T>
class List_nodeO{

	friend class Ordered_list<T>;
private:
	T value;
	List_nodeO<T> * prev;
	List_nodeO<T> * next;

};

template<class T>
class Ordered_list : public Linear_list<T, List_nodeO<T> *>{
private:
	List_nodeO<T> * head;
	int length;

public:
	typedef typename Linear_list<T, List_nodeO<T> *>::value_type valuetype;
	typedef typename Linear_list<T, List_nodeO<T> *>::position position;
	Ordered_list();
	Ordered_list(const Ordered_list<T>&);
	~Ordered_list();
	void create();
	bool empty() const;
	valuetype read(position) const;
	void insert (const valuetype& , position);
	void insertO(const valuetype&);
	void write(const valuetype&, position);
	position begin() const;
	position last() const;
	bool end(position p) const;
	position next(position) const;
	position previous(position) const;
	void erase(position);
	bool search (const valuetype &x);
	int size() const{
		return length;
	}
	// sovraccarico di operatori
	Ordered_list<T>& operator=(const Ordered_list<T>&); // the assignment operator
	bool operator==(const Ordered_list<T> &) const; // tests two list for equality

};

template <class T>

void Ordered_list <T> :: write (const valuetype &a, position p){
	if (!end(p)){
		p->value =a;
	}
}

template<class T>
Ordered_list<T>::Ordered_list(){
	length = 0;
	head = new List_nodeO<T>;
	head->next = head;
	head->prev = head;
}


//ostruttore che crea la lista copiandone una gia esistente
template <class T>
Ordered_list<T>::Ordered_list(const Ordered_list<T>& L){
	  length = L.size();

		head = new List_nodeO<T>;
		head->next = head;
		head->prev = head;

		if (!L.empty()){
			position p = L.last();
			for (int i=0; i <= L.length; i++){
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
}


//distruttore
template<class T>
Ordered_list<T>::~Ordered_list(){
	while(!empty())
		erase(begin());
	delete head;
}




template<class T>
void Ordered_list<T>:: insert (const valuetype &a, position p){

	position t = new List_nodeO<T>;

	t -> value =a;
	t ->next =p;
	t -> prev = p->prev;
	p-> prev -> next = t;
	p ->prev =t;


	length ++;
}



template<class T>
void Ordered_list<T>::create(){
	if(empty())
		length = 0;

}
//dice che se il successivo del valore sentinella è il valore sentinella stesso allora è vuota
template<class T>
bool Ordered_list<T>::empty() const{
	return(head->next == head);

}

template<class T>
typename Ordered_list<T>::valuetype
Ordered_list<T>::read(position p) const{
	if(!end(p))
		return p->value;
}

template<class T>
typename Ordered_list<T>::position
Ordered_list<T>::begin() const{
	return(head->next);
}
//ritorna il valore ultimo della lista
//ricorda che head è sentinella e punta sia alla testa che alla coda
template<class T>
typename Ordered_list<T>::position
Ordered_list<T>::last() const{
	return(head->prev);
}

template<class T>
bool Ordered_list<T>::end(position p)const {
	return(p == head);
}
template<class T>
typename Ordered_list<T>::position
Ordered_list<T>::next(position p) const{
	return p->next;
}

template<class T>
typename Ordered_list<T>::position
Ordered_list<T>::previous(position p) const{
	if(p != head)
		return p->prev;
}

template<class T>
void Ordered_list<T>::erase(position p){

	if(!empty() && !end(p)){
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
	}
}

template<class T>
void Ordered_list<T>::insertO(const valuetype &x){
	/*position t = new List_node<T>;
	t->value = x;
	t->next = p;
	t->prev = p->prev;
	p->prev->next = t;
	p->prev = t;
	length++;*/
	position inizio = new List_nodeO<T>;
	valuetype v;
	inizio = begin();
	v = read(inizio);
	if (empty()){
		 position t = new List_nodeO<T>;
		        t->value = x;
		        t->next = head;
		        t->prev = head->prev;
		        head->prev->next = t;
		        head->prev = t;
		        length++;
	}

	else{
		inizio = begin();
	while(read(inizio)< x && !end(inizio)){
		inizio = next(inizio);
	}
	insert(x,inizio);
	}
	/*position t = new List_nodeO<T>;
	t->value = x;
	t->next = inizio;
	t->prev = inizio->prev;
	inizio->prev->next = t;
	inizio->prev = t;
	length++;

*/

}

template<class T>
bool Ordered_list<T> :: search (const valuetype &x){


	if (empty()){
		return false;
	}else {
		position t = new List_nodeO<T>;
		t = begin();
		while (!end(t)){
			if(read(t)== x){
				return true;
			}else {
				t = t->next;
			}
		}
		if (end(t)){
			return false;
		}

	}
}


template <class T>
Ordered_list<T>& Ordered_list<T>::operator=(const Ordered_list<T>& L)
{
	if (this != &L)
	{
		length = L.size();

		head = new List_nodeO<T>;
		head->next = head;
		head->prev = head;

        cout << L.empty();
        cout << L.size();
		if (!L.empty())
		{
            position p = L.last();
			for (int i=0; i < L.size(); i++)
			{
				cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Ordered_list<T>::operator==(const Ordered_list<T> &L) const
{
	if (L.size() != length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p))
	{
		if (p->_value != pL->_value)
			return false;
		p = p->next;
		pL = pL->next;
	}
	return true;
}




#endif /* LISTA_PUNTATORI_ORDINATA_H_ */
