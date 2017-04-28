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
      cout << "Pesée : " << cpt << endl ;
      cpt++ ;

      if(somme_1==0) { return d3 ; }
      else if((somme_1>0 && plus_moins>0) || (somme_1<0 && plus_moins<0)) { return d1 ; }
      else if((somme_1<0 && plus_moins>0) || (somme_1>0 && plus_moins<0)) { return d2 ; }
    }
    else											//Cette partie est nécessaire car si on a que 3 boulle on ne peut que le résoudre qu'avec cette méthode
    {
      int somme_1=balance(Tab,taille,d1,d2) ;
      cout << "Pesée : " << cpt << endl ;
      cpt++ ;

      int somme_3=balance(Tab,taille,d1,d3) ;
      cout << "Pesée : " << cpt << endl ;
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
    cout << "Pesée : " << cpt << endl ;
    cpt++ ;

    if(plus_moins!=0)
    {
      if(somme_1==0) {return resoudre(Tab,taille/3,d3,d3+taille/3,d3+(2*taille/3),plus_moins,cpt) ;}
      else if((somme_1<0 && plus_moins>0) || (somme_1>0 && plus_moins<0)) {return resoudre(Tab,taille/3,d2,d2+taille/3,d2+(2*taille/3),plus_moins,cpt) ;}
      else {return resoudre(Tab, taille/3, d1, d1+taille/3, d1+(2*taille/3), plus_moins, cpt) ; }
    }
    else
    {
      int somme_2=balance(Tab,taille,d1,d3) ;
      cout << "Pesée : " << cpt << endl ;
      cpt++;

      if(somme_1==0)									//On a nos deux pesée, on peut maintenant connaître plus ou moins et lui affecter une valeur.
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
}

bool verifier(int* Tab, int taille, int y, int x, int pm)
{
  if(x!=y) return false ;
  for(int i=1 ; i<=taille ;i++)
  {
    if(pm>0) { if(Tab[y]<Tab[i]) {return false ;} }
    else if (pm<0) { if(Tab[y]>Tab[i]) {return false;} }
  }
  return true ;
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

  cout << "Test pour plus_moins supérieur !" << "\n" << endl ;
	for(int i=1 ; i<=taille ; i++)
	{
    int cpt=1 ;
		int plus_moins=0 ;                                                            //Changer plus_moins pour avoir un nombre de pesée différente
    cout << "Test pour l'indice : " << i << endl ;
		int * T = question(taille, i, 1);
		int y=resoudre(T, taille/3, 1, 1+taille/3, 1+(2*taille/3), plus_moins,cpt) ;
    cout << "La boule intruse est la boule : " << y << endl ;
    cout << "Plus moins est égal à : " << plus_moins << endl ;
    int pm=plus_moins ;

		if(!verifier(T, taille, y, i, pm))
		{
			cout << "Erreur pour : " << " (" << i << ") +" << endl;
			return false;
		}

    cout << "\n" << "---------------------------" << "\n" << endl ;
  }

  cout << "Test pour plus_moins inférieur !" << "\n" << endl ;
  for(int j=1 ; j<=taille ; j++)
  {
  	int *T_bis=question(taille, j, -1);
		int plus_moins=0;
    int cpt_bis=1 ;
    cout << "Test pour l'indice : " << j << endl ;
		int z=resoudre(T_bis, taille/3, 1, 1+taille/3, 1+(2*taille/3), plus_moins,cpt_bis);   //J'ai mis des +1, parce que sur mon tableau la premier boule est 1, Par conséquent si on veut
    cout << "La boule intruse est la boule : " << z << endl ;                             //des paquets équilibre il faut rajouter 1
    cout << "Plus moins est égal à : " << plus_moins << endl ;
    int pm_2=plus_moins ;

		if(!verifier(T_bis, taille, z,j, pm_2))
		{
			cout << "Erreur pour ; " <<" (" << j << ")" << endl;
			return false;
		}

    cout << "\n" << "---------------------------" << "\n" << endl ;
	}

  cout << "Tout es bon !!! :) Vous pouvez partir du cour !! " << endl ;

	return true;
}

int main()
{
  bool trouver ;
  trouver=valider(27) ;       //Changer la taille pour changer le nombre de boulles

  return 0 ;
}
