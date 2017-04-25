#include <iostream>
#include <cmath>

using namespace std;

int  * question(int N, int x, int d)

{
  int *Tbis=new int [N] ;
  int poid=100 ;

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
  if(taille==1)
  {
    if(plus_moins!=0)
    {
      int somme_1=balance(Tab,taille,d1,d2) ;
      //cout << "Pesée : " << cpt << endl ;
      cpt++ ;

      if(somme_1==0) { return d3 ; }
      else if((somme_1>0 && plus_moins>0) || (somme_1<0 && plus_moins<0)) { return d1 ; }
      else if((somme_1<0 && plus_moins>0) || (somme_1>0 && plus_moins<0)) { return d2 ; }
    }
    else
    {
      int somme_1=balance(Tab,taille,d1,d2) ;
      //cout << "Pesée : " << cpt << endl ;
      cpt++ ;

      int somme_3=balance(Tab,taille,d1,d3) ;
      //cout << "Pesée : " << cpt << endl ;
      cpt++ ;

      if(somme_1==0)
      {
        if(somme_3<0) {plus_moins=1 ;}
        else {plus_moins=-1 ;}
        return d3 ;
      }
      else if((somme_1>0 && somme_3>0) || (somme_1<0 && somme_3<0))
      {
        if(somme_1>0) {plus_moins=-1 ;}
        else {plus_moins=1 ;}
        return d1;
      }
      else if((somme_1>0 && somme_3==0) || (somme_1<0 && somme_3==0))
      {
        if(somme_1>0) {plus_moins=1 ;}
        else {plus_moins=-1 ;}
        return d2 ;
      }
    }
  }
  else
  {
    int somme_1=balance(Tab,taille,d1,d2) ;
    //cout << "Pesée : " << cpt << endl ;
    cpt++ ;

    if(plus_moins!=0)
    {
      if(somme_1==0) {return resoudre(Tab,taille/3,d3,d3+taille/3,d3+(2*taille/3),plus_moins,cpt) ;}
      else if((somme_1<0 && plus_moins>0) || (somme_1>0 && plus_moins<0)) {return resoudre(Tab,taille/3,d2,d2+taille/3,d2+(2*taille/3),plus_moins,cpt) ;}
      else {return resoudre(Tab, taille/3, d1, d1+taille/3, d1+(2*taille/3), plus_moins, cpt) ; }
    }

    int somme_2=balance(Tab,taille,d1,d3) ;
    //cout << "Pesée : " << cpt << endl ;
    cpt++;

    if(somme_1==0)
    {
      if(somme_2<0) {plus_moins=1 ;}
      else {plus_moins=-1 ;}
      return resoudre(Tab,taille/3,d3,d3+taille/3,d3+(2*taille/3),plus_moins,cpt) ;
    }
    else if((somme_1>0 && somme_2==0) || (somme_1<0 && somme_2==0))
    {
      if(somme_1>0) {plus_moins=-1 ;}
      else {plus_moins=1 ;}
      return resoudre(Tab, taille/3, d2, d2+taille/3, d2+(2*taille/3), plus_moins, cpt) ;
    }
    else
    {
      if(somme_1>0) {plus_moins=1 ;}
      else {plus_moins=-1 ;}
      return resoudre(Tab, taille/3, d1, d1+taille/3, d1+(2*taille/3), plus_moins, cpt) ;
    }
  }
}

bool verifier(int* Tab, int taille, int y, int x, int pm)
{
  if(x!=y) return false ;
  for(int i=1 ; i<taille ;i++)
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

bool valider(int taille)
{
	for(int i=1 ; i<=taille ; i++)
	{
    int cpt=1 ;
		int plus_moins=0 ;
		int * T = question(taille, i, 1);
		int y=resoudre(T, taille/3, 1, 1+taille/3, 1+(2*taille/3), plus_moins,cpt);
    int pm=plus_moins ;

		if(!verifier(T, taille, y, i, pm))
		{
			cout << "Erreur pour : " << " (" << i << ") +" << endl;
			return false;
		}

		T=question(taille, i, -1);
		plus_moins=0;
		int z=resoudre(T, taille/3, 1, 1+taille/3, 1+(2*taille/3), plus_moins,cpt);
    int pm_2=plus_moins ;

		if(!verifier(T, taille, z,i, pm_2))
		{
			cout << "Erreur pour ; " <<" (" << i << ")" << endl;
			return false;
		}
	}

  cout << "Tout es bon !!! :) Vous pouvez partir du cour !! " << endl ;
	return true;
}

int main()
{
  bool trouver ;

  /*for(int a=1 ; a<28 ; a++)
  {
    int *Tab=question(27,a,10) ;
    int plus_moins=0 ;
    int cpt=1 ;
    //affichage(Tab,27) ;

    cout << "Test de la fonction pour indice : " << a << endl ;
    int y=resoudre(Tab,9,1,10,19,plus_moins,cpt) ;
    cout << "La boule intruse est la boule : " << y << endl ;
    if(plus_moins>0) {cout << "La différence de poids est supétieur !   : " << plus_moins << endl ;}
    else {cout << "La différence de poids est inférieur !   : " << plus_moins << endl ;}

    int pm=plus_moins ;
    bool trouve=verifier(Tab,27,y,a,pm) ;
    if(trouve==true) {cout << "fonctionne" << endl ;}
    else {cout << "erreur" << endl ;}
    cout << "----------------------------" << "\n" << endl ;
  }*/

  trouver=valider(27) ;

  return 0 ;
}
