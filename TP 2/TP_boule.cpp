#include <iostream>
#include <cmath>

using namespace std;

int  * question(int N, int x, int d)

{
  int *Tbis=new int [N] ;
  int poid=10 ;

  for(int i=1 ; i<=N ; i++)
  {
    if(i==x) {Tbis[i]=poid+d ;}
    else {Tbis[i]=poid ;}
  }

  return Tbis ;
}

int balance(int *Tab, int taille, int d1, int d2)
{
  int cpt_D1=0 ;
  int cpt_D2=0 ;

  for(int i=d1 ; i<d1+taille ; i++) {cpt_D1+=Tab[i] ;}
  for(int j=d2 ; j<d2+taille ; j++) {cpt_D2+=Tab[j] ;}

  return cpt_D1-cpt_D2 ;
}

int resoudre(int* Tab, int taille, int d1, int d2, int d3,int& plus_moins,int& cpt)
{
  int somme_1=balance(Tab,taille,d1,d2) ;
  cout << "Pesée : " << cpt << endl ;
  cpt++ ;

  if(taille==1)
  {
    if(plus_moins!=0)
    {
      if(somme_1==0) { return d3 ; }
      else if((somme_1>0 && plus_moins>0) || (somme_1<0 && plus_moins<0)) { return d1 ; }
      else if((somme_1<0 && plus_moins>0) || (somme_1>0 && plus_moins<0)) { return d2 ; }
    }
    else
    {
      int somme_2=balance(Tab,taille,d1,d3) ;
      cout << "Pesée : " << cpt << endl ;
      cpt++ ;

      if(somme_1==0) { return d3 ; }
      else if((somme_1>0 && somme_2>0 && plus_moins>0) || (somme_1<0 && somme_2>0 && plus_moins<0)) { return d1; }
      else if((somme_1<0 && somme_2==0 && plus_moins<0) || (somme_1>0 && somme_2==0 && plus_moins>0)) { return d2 ; }
    }
  }
  else
  {
    if(plus_moins!=0)
    {
      if(somme_1==0) { return resoudre(Tab, taille/3, d3, d3+(taille/3), d3+(taille/3*2), plus_moins, cpt) ; }
      else if((somme_1<0 && plus_moins<0) || (somme_1>0 && plus_moins>0)) { return resoudre(Tab, taille/3, d1, d1+taille/3, d1+(taille/3*2), plus_moins, cpt) ; }
      else { return resoudre(Tab, taille/3, d2, d2+taille/3, d2+(taille/3*2), plus_moins, cpt) ; }
    }

    int somme_2=balance(Tab,taille,d1,d3) ;
    cout << "Pesée : " << cpt << endl ;
    cpt++;

    if((somme_1<0 && somme_2==0) || (somme_1<0 && somme_2<0)) {plus_moins=-1 ;}
    else {plus_moins=1 ;}

    if(somme_1==0) {return resoudre(Tab,taille,d3,d3+taille/3,d3+(2*taille/3),plus_moins,cpt) ;}
    else if ((somme_1>0 && somme_2>0) || (somme_1<0 && somme_2<0)) { return resoudre(Tab, taille/3, d1, d1+taille/3, d1+(2*taille/3), plus_moins, cpt) ; }
    else if((somme_1>0 && somme_2==0) || (somme_1<0 && somme_2==0)) { return resoudre(Tab, taille/3, d2, d2+taille/3, d2+(2*taille/3*2), plus_moins, cpt) ; }
  }
}


bool verifier(int* Tab, int N, int y, int pm)
{
  for(int i=1 ; i<=N ;i++)
  {
    if(pm>0) { if(Tab[y]>Tab[i]) {return true ;} }
    else if (pm<0) { if(Tab[y]<Tab[i]) {return true ;} }
  }
  return false ;
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
  bool trouve ;

  int *Tab=question(27,1,4) ;
  int plus_moins=1 ;
  int cpt=1 ;
  //affichage(Tab,27) ;

  int y=resoudre(Tab,9,1,10,17,plus_moins,cpt) ;
  cout << "La boule intruse est la boule : " << y << endl ;
  if(plus_moins>0) {cout << "La différence de poids est supétieur !   : " << plus_moins << endl ;}
  else {cout << "La différence de poids est inférieur !   : " << plus_moins << endl ;}

  int pm=plus_moins ;
  //trouve=verifier(Tab,17,y,pm) ;
  //if(trouve) {cout << "La fonction résoudre marche" << endl ;}
  //else {cout << "La fonctionr résoudre ne marche pas" << endl ;}

  return 0 ;
}
