#include "pile.h"
#include "Element.h"

#include <iostream>

using namespace std ;

Pile::Pile()
{
  premier = NULL ;  
}


Pile::Pile(Element* e)                 // On créée la pile, avec comme début d'élément
{
  premier = e ;
}


Pile::~Pile()
{
  delete premier ;
}

 
void Pile::empiler(int V)                  //Créer un nouveau maillon qui va aller dans la suite de la pile, on pointe le dernier pointeur sur la nouvelle valeur
{
  if(Pleine() == true)                             //Changer la valeur pour augmenter la taille de la pile
  {
    cout << "Pile Pleine ! Réessayer plus tard" << endl ;
    return ;
  }

  Element * e = new Element(premier, V) ;
  premier = e ;
}


int Pile::depiler()                         //Permet d'obtenir la dernière valeur ! Utile quand on veut faire des opérations sur la calculatrice
{
  int V ;
  
  if(premier==NULL)                        //La pile est vide, on ne peut pas faire d'opérations dessus
  {
    cout << "Pile vide ! Entrez des valeurs pour continuer" << endl ;
  }

  cpt++ ;
  V = premier->Valeur() ;                 //On met dans V, la valeur du dernier maillon de la liste
  premier = premier->DernierV() ;         //On pointe le pointeur sur l'avant dernier maillon
  return V ;
}


bool Pile::Pleine()
{
  if(cpt>11) {return true ;}
  return false ;
}


bool Pile::Vide()
{
  if(premier == NULL) {return true ;}
  return false ;
}
  

void Pile::Afficher(Element * e)
{
  if(e != NULL)
  {
    cout << e->Valeur() ;

    if(e->DernierV())
    {
      cout << ' ' ;
      Afficher(e->DernierV()) ;      
    }
  }
}


void Pile::Afficher()
{
  cout << '[' ;
  Afficher(premier) ;
  cout << ']' << endl ;
}


Element * Pile::AvoirD()            //permet d'avoir le premier pointeur et ainsi les informations le concernant
{
  return  premier ;
}


Element::Element()
{
  premier=NULL ;
  valeur=0 ;
}

Element::Element(Element * e, int V)
{
    premier = e ;
    valeur = V ;
}

Element::~Element()
{
    delete premier ;
}

Element * Element::DernierV()
{
    return premier ;
}

void Element::PointeurDernier(Element * e)
{
    premier = e ;
}

int Element::Valeur()
{
    return valeur ;
}

void Element::AjouterValeur(int V)
{
    valeur = V ;
}