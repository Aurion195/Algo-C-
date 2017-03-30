#include <iostream>

using namespace std ;

void feuille(int n, float& lo, float& la)
{
  float largeur=la ;
  float longeur=lo;

  if(n==0) {return ;}
  else
  {
    lo=largeur ;
    la=longeur/2 ;
    feuille(n-1,lo,la) ;
  }
}

int main()
{
  float la=84.1, lo=118.9 ;
  int n=4 ;

  feuille(n,lo,la) ;

  cout <<"Longeur : " << lo << "\n" << "Largeur : " << la << endl ;

  return 0 ;
}
