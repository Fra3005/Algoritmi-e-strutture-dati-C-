/*
 * main.cpp
 *
 *  Created on: 28 dic 2020
 *      Author: franc
 */

#include "tree.h"
#include <iostream>
using namespace std;
int main(){
	tree<int> a;
	typename tree<int>::Nodo n;
	n = new nodo<int>;



	a.ins_root(n);
	a.write(n, 1);


/* a.ins_sx(a.root());
 a.ins_dx(a.root());

 a.write(a.sx(a.root()), 2);

 a.write(a.dx(n), 3);
*/
//cout << a.read(a.sx(a.root()));
 //cout<<a.altezzaMinimale(n);

	a.stampa();


//cout<<a.dimensione();




 //cout<<a.dimensione();

//cout<<a.livello(m);
//cout<<a.read(n);








	//a.print(a.root());
	 //a.stampa(a.root());
	//cout<<a.foglia(m);
  //cout<<a.is_heigth_balanced(a.root());
	//cout<<a.livello(a.root());

}
