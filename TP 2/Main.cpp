#include <iostream>

using namespace std;

int  * question(int N, int x, int d)
{
  int *Tbis ;
  Tbis=new int [N] ;

  int poid=10 ;

  for(int i=1 ; i<(N+1) ; i++)
  {
    if(i==x) {Tbis[i]=poid+d ;}
    else {Tbis[i]=poid ;}
  }

  return Tbis ;
}

int balance(int *Tab, int taille, int d1, int d2, int& cpt)
{
  int cpt_D1=0 ;
  int cpt_D2=0 ;

  for(int i=d1 ; i<d1+taille ; i++) {cpt_D1+=Tab[i] ;}
  for (int j=d2 ; j<d2+taille ; j++) {cpt_D2+=Tab[j] ;}

  cpt++ ;
  return cpt_D1-cpt_D2 ;
}

int resoudre(int* Tab, int taille, int d1, int d2, int d3,int & plus_moins)
{
  int result=0 ;

  if(taille==1)
  {
    if(plus_moins!=0)
    {
      result=balance(Tab,taille,d1,d2,cpt) ;
      if(result==0) {return d3 ;}
      if(result<0 and plus_moins<0) {return d1 ;}
      if(result<0 and plus_moins>0) {return d2 ;}
      if(result>0 and plus_moins>0) {return d2 ;}
      if(result>0 and plus_moins<0) {return d1 ;}
    }

    if(plus_moins==0)
    {
      result=0 ;
      result=balance(Tab,taille,d1,d2,cpt) ;
      if(result==0)
      {
        result=balance(Tab,taille,d1,d3) ;
        if(result>0) {plus_moins=1 ;}
        else {plus_moins=-1 ;}
        return d3 ;
      }
      if(result!=0)
      {
        result=0 ;
        result=balance(Tab,taille,d1,d3,cpt) ;
        if(result==0)
        {
          result=0 ;
          result=balance(Tab,taille,d1,d2,cpt) ;
          if(resultat>0) {plus_moins=1 ;}
          else {plus_moins=-1 ;}
          return d2 ;
        }
        if(result!=0)
        {
          result=0 ;
          result=balance(Tab,taille,d1,d3,cpt) ;
          if(result>0) {plus_moins=1 ;}
          else {plus_moins=-1 ;}
          return d1 ;
        }
      }
    }
  }
  else
  {
    result=0 ;
    d1=1 ;
    d2=taille/3+d1 ;
    d3=taille ;

  }
}

void affichage(int *Tab, int N)
{
  cout << "Voici la listes des boules" << endl ;

  for(int i=1 ; i<=N ; i++)
  {
    cout << "B" << i << " |  " << Tab[i] << "  |" << endl ;
  }
}

int main()
{
  int N, taille, x, d, plus_moins;

  N=27 ;
  int cpt=0 ;

  cout << "Valeur de la boulle : " ; cin >> x ;
  cout << "Différence de poids : " ; cin >> d ;
  cout << "Plus (1) / Moins (-1) : " ; cin >> plus_moins ;


  int *Tab=question(N,x,d) ;
  affichage(Tab,N) ;

  int result;
  result=balance(Tab,9,1,10,cpt) ;
  cout << result << endl ;

}
