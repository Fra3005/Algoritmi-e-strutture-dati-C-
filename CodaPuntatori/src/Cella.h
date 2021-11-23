/*
 * Cella.h
 *
 *  Created on: 23 dic 2020
 *      Author: franc
 */

#ifndef CELLA_H_
#define CELLA_H_

#import <iostream>

template<class T>
class cella {

public:
	typedef T tipoelem;

	tipoelem get_elemento();
	void set_elemento(tipoelem);

	cella();
	~cella();
	void successivo(cella <T> *);

private:
	cella <T> *succ;
	tipoelem elemento;


};


template<class T>
cella <T> :: cella(){
	elemento =0;
	succ = nullptr;

}



template<class T>
cella<T> :: ~cella(){


}



template<class T>
T cella <T> :: get_elemento(){

	return elemento;

}


template<class T>
void cella <T>:: set_elemento (tipoelem e){
	elemento->e;

}


template<class T>
 cella <T> :: successivo (cella <T> *a){
	 return a->succ;
}





#endif /* CELLA_H_ */
