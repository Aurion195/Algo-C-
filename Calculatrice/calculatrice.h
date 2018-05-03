#ifndef __CALCULATRICE_H__
#define __CALCULATRICE_H__

#include <iostream>
#include "pile.h"
#include "Element.h"

using namespace std;

class Calculatrice
{
  Pile Pile_bis;
  
  public:
  Calculatrice();
  char saisie(int & V);
};

#endif
