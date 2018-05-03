#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <iostream>

using namespace std ;

class Element
{
	Element * premier ;
	int valeur ;

	public : 
		Element() ;
		Element(Element *, int);
		~Element();

		Element * DernierV();							//Obtenir la derniere valeur de la pile
		void PointeurDernier(Element * e);				//Pointe sur le dernier maillon pour avoir la valeur
		int Valeur();									//Permet de retourner la valeur du maillon (utile pour la calculatrice)
		void AjouterValeur(int V) ;
} ;

#endif