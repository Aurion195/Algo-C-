#ifndef __PILE_H__
#define __PILE_H__

#include <iostream>
#include "Element.h"

class Pile
{
  Element * premier ;
  int cpt ;
  
  public:

  Pile();
  Pile(Element*);
  ~Pile();
  void empiler(int V);
  int depiler();
  bool Pleine();
  bool Vide();
  void Afficher();
  Element* AvoirD() ;

private:
  void Afficher(Element*) ;
};


#endif

