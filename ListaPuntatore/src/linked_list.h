/*
 * linked_list.h
 *
 *  Created on: 19 dic 2020
 *      Author: franc
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "linear_list.h"
template <class T>
class Linked_list;
template <class T>
class List_node {
	friend class Linked_list<T>;

	T value;
	List_node<T> *prec;
	List_node <T> *succ;

};



template < class T >

class Linked_list : public Linear_list<T, List_node<T>*>{

public:
	typedef typename Linear_list<T, List_node<T>*>:: value_type value_type;
	typedef typename Linear_list <T, List_node<T>*>:: position position;

	//costruttori


	Linked_list();
	Linked_list (const Linked_list<T>&);

	~Linked_list();

	void create();
		bool empty() const;
		value_type read(position) const;
		void write(const value_type &, position);
		position begin() const; //testa
		position last() const; //coda
		bool end(position) const; //is end
		position next(position) const;
		position previous(position) const;
		void insert(const value_type &, position);
		void erase(position);
		void inverti();


		int size() const {
			return length;

		}


		// sovraccarico di operatori
		Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
		bool operator==(const Linked_list<T> &) const; // tests two list for equality
		List_node<T> * head; //testa della lista - sentinella

	 private:
		int length; // the length of the list
};

//costruttore sentinella

template <class T>
Linked_list< T > :: Linked_list(){ // @suppress("Class members should be properly initialized")
	head = new List_node<T>;
	head ->prec =head;
	head ->succ =head;
	length =0;
}


//inverte le posizioni speculari (1234 diventa 4321), è un ciclo che si blocca nel caso di lista dispari quando le posizioni sono uguali
//nel caso di lista pari quando il puntatore coda si trova a sinistra del puntatore testa
template<class T>
void Linked_list<T>::inverti(){
    Linked_list<T>::position coda;
    Linked_list<T>::position testa;
    Linked_list<T>::value_type v;
    testa=begin();
    coda=last();

    while(coda!=testa && testa!=coda->next){
        v = read(coda);
        write(testa->value, coda);
        write(v, testa);
        testa = testa->next;
        coda = coda->prev;
    }


}






template <class T>
Linked_list <T> :: ~Linked_list(){

	while (!empty()){
		erase(begin());
	}

	delete head;
}

//costruttore di copia
//input: reference da copiare
template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) { // @suppress("Class members should be properly initialized")
    length = L.size();

    //setta sentinella nuova lista
	head = new List_node<T>;
	head->succ = head;
	head->prec = head;

    //inserisce sempre in testa
	if (!L.empty()){
		position p = L.last();
		for (int i=0; i < L._length; i++){
            //inserisce nella posizione che vuoi (begin()) per mantere l'ordine originale
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}



template <class T>

void Linked_list<T> :: create(){
	if(empty()){
		length =0;
	}

}

//dice che se il successivo del valore sentinella è il valore sentinella stesso allora è vuota
template <class T>
bool Linked_list <T> :: empty()const {
	return head == head -> succ;
}

//const per non modificare il risultato
//ritorna la testa della lista

template<class T>
typename Linked_list <T> ::position Linked_list<T> :: begin() const{
	return head->succ;
}


//ritorna il valore ultimo della lista
//ricorda che head è sentinella e punta sia alla testa che alla coda
template <class T>
typename Linked_list <T> :: position Linked_list<T> :: last() const{

	return head ->prec;
}

template <class T> typename Linked_list<T> :: position
 Linked_list <T> ::next (position p)const {
	return p ->succ;
}


template <class T>typename Linked_list <T> :: position
Linked_list <T> ::  previous (position p)const {

	if(p != head){
		p->prec;
	}

}

template <class T>

bool Linked_list <T> :: end(position p)const {

	return p == head;

}




template <class T>
typename Linked_list<T> :: value_type
Linked_list <T> :: read (position p) const {

	if (!end (p)){

		return p ->value;
	}
}


template <class T>

void Linked_list <T> :: write (const value_type &a, position p){
	if (!end(p)){
		p->value =a;
	}
}

template<class T>

void Linked_list<T>:: insert (const value_type &a, position p){

	position t = new List_node<T>;

	t -> value =a;
	t ->succ =p;
	t -> prec = p->prec;
	p-> prec -> succ = t;
	p ->prec =t;


	length ++;
}


template <class T>

void Linked_list <T> :: erase (position p){
	if(!end(p) && !empty()){
	p->prec->succ = p->succ;
	p->succ->prec = p->prec;
	delete p;
	length --;

	}


}





template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
	if (this != &L){ //se la lista attuale è diversa da quella che gli passo
		//_length = L.size();
        //aggiorno la nuova dimensione e creo una nuova lista che punta alla sentinella
		head = new List_node<T>;
		head->succ = head;
		head->prec = head;
        //stampa se è vuota e la dimensione
        /*
		cout << L.empty();
        cout << L.size();
		*/
		if (!L.empty()){
            //se L non vuota, copio la lista L nella lista che ho creato, dall'ultimo al primo (vedi costruttore copia)
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				//cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this; //ritorna la nuova lista creata
}


//overloading operatore di confronto
template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
    //Se le liste hanno size diverse, allora esci
	if (L.size() != length)
		return false;
	//teste due liste
	position p, pL;
	p = begin();
	pL = L.begin();
	//fin quando non finisce una lista (p o PL uguale)
	while (!end(p)){
		if (p->_value != pL->_value) //se i valori del nodo attuale sono diversi, RIP
			return false;
		//aggiorna i puntatori dei nodi
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}




#endif /* LINKED_LIST_H_ */
