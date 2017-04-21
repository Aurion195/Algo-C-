#include <iostream>
#include <cmath>

using namespace std;

int  * question(int N, int x, int d)

{
  int *Tbis=new int [N] ;
  int poid=10 ;

  for(int i=1 ; i<(N+1) ; i++)
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

int resoudre(int* Tab, int taille, int d1, int d2, int d3,int& plus_moins)
{
  if(taille==1)
  {
      int somme_1=balance(Tab,1,d1,d2) ;     //<!-- Pesée 3 !-->
      int somme_2=balance(Tab,1,d2,d3) ;      //<!-- Pesée 4 !-->

      if(somme_1==0 && somme_2>0) {plus_moins=-1 ; return d3 ;}
      if(somme_1==0 && somme_2<0) {plus_moins=1 ; return d3 ;}
      if(somme_1<0 && somme_2==0) {plus_moins=-1 ; return d1 ;}
      if(somme_1>0 && somme_2==0) {plus_moins=1 ; return d1 ;}
      if(somme_1<0 && somme_2!=0) {plus_moins=1 ; return d2;}
      if(somme_1>0 && somme_2!=0) {plus_moins=-1 ; return d2;}
  }
  else
  {
    int diff_d1_d2=balance(Tab,taille,d1,d2) ;   //<!-- Pesée 1 !-->
    int diff_d2_d3=balance(Tab,taille,d2,d3) ;   //<!-- Pesée 2 !-->

    if(diff_d1_d2==0) {return resoudre(Tab,taille/3,d3,d3+(taille/3),d3+(taille/3*2),plus_moins) ;}
    else if(diff_d1_d2!=0 && diff_d2_d3==0) {return resoudre(Tab,taille/3,d1,d1+(taille/3),d1+(taille/3*2),plus_moins) ;}
    else {return resoudre(Tab,taille/3,d2,d2+(taille/3),d2+(taille/3*2),plus_moins) ;}
  }
}

bool verifier(int* Tab, int N, int y, int pm)
{
  for(int i=1 ; i<=N ;i++)
  {
    if(pm>0) { if(Tab[y]>Tab[i]) {return true ;} }
    else if (pm<0) { if(Tab[y]<Tab[i]) {return true ;} }
    else {return false ;}
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
  int N, taille, x, d, plus_moins, d1, d2, d3, y, pm ;
  bool trouve ;

  N=27 ; d1=1 ; d2=10 ; d3=19 ; y=0 ; plus_moins=0 ;
  int cpt=0 ;

  do {
    cout << "Valeur de la boulle : " ; cin >> x ;
    if(x>27 || x<1) {cout << "Erreur : boule non connus !" << endl ;}
  } while (x>27 || x<1) ;

  cout << "Différence de poids : " ; cin >> d ;


  int *Tab=question(N,x,d) ;
  //affichage(Tab,N) ;

  //int result;
  //result=balance(Tab,9,1,10,cpt) ;
  //cout << result << endl ;

  y=resoudre(Tab,9,d1,d2,d3,plus_moins) ;
  cout << "La boule intruse est la boule : " << y << endl ;
  if(plus_moins>0) {cout << "La différence de poids est supétieur !   : " << plus_moins << endl ;}
  else {cout << "La différence de poids est inférieur !   : " << plus_moins << endl ;}

  pm=plus_moins ;
  trouve=verifier(Tab,N,y,pm) ;
  if(trouve) {cout << "La fonction résoudre marche" << endl ;}
  else {cout << "La fonctionr résoudre ne marche pas" << endl ;}

  return 0 ;
}
