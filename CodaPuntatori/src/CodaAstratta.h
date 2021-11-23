/*
 * CodaAstratta.h
 *
 *  Created on: 23 dic 2020
 *      Author: franc
 */

#ifndef CODAASTRATTA_H_
#define CODAASTRATTA_H_

template <class T, class P>
class coda{

public:
	typedef T valore;
	typedef P posizione;


	virtual void creaCoda() =0;
	virtual T leggiCoda() const =0;
	virtual void inCoda(valore ) =0;
	virtual void fuoriCoda() =0;
	virtual bool codaVuota();



};



#endif /* CODAASTRATTA_H_ */
