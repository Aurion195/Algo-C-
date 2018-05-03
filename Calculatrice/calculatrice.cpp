#include "calculatrice.h"
#include "Element.h"

#include <iostream>
#include <math.h>
#include <string>

using namespace std ; 

  Calculatrice::Calculatrice()
  {		

    string c ;                  //Représente le caractère saisie

    bool arret = true ;       //La boucle infinie
    bool pile = false ;        //afficher la pile 

    while(arret==true)
    {
        int A, B, result ;
        int V=0 ;
        c = saisie(V);

        switch(c[0])
        {
          case 'q' :
            arret=false ;
            break ;

          case 'Q' :
            arret = false ;
            break ;

          case 'v' :
            Pile_bis.empiler(V);
            break ;

          case 'a' :
            pile = !pile ;          //permet de créer des variations de la pile
            break ;

          case 'd' :
            A = Pile_bis.depiler() ;

            if(Pile_bis.Vide()==false)
            {
              Pile_bis.empiler(A);
            }
            else
            {
              cout  << "La pile est vide" << endl;
            }

            Pile_bis.empiler(A) ;

            break;

          case ':' :
            {
                if(Pile_bis.Vide()==false)
                {
                  A = Pile_bis.depiler() ;
                  cout << A << endl  ;
                }
                else
                {
                  cout << "La pile est vide" << endl;
                }
                
                Pile_bis.empiler(A);
                break;
            }

          case '+' :
            A = Pile_bis.depiler() ;
            B = Pile_bis.depiler() ;

            Pile_bis.empiler(A + B) ;
            break ;

          case '-' :
            A = Pile_bis.depiler() ;
            B = Pile_bis.depiler() ;

            Pile_bis.empiler(B - A) ;
            break ;

          case '*' :
            A = Pile_bis.depiler() ;
            B = Pile_bis.depiler() ;

            Pile_bis.empiler(B * A) ;
            break ; 

          case '%' :
            A = Pile_bis.depiler() ;
            B = Pile_bis.depiler() ;

            Pile_bis.empiler(B % A) ;
            break ;

          case '/' :
            A = Pile_bis.depiler() ;
            B = Pile_bis.depiler() ;

            Pile_bis.empiler(B / A) ;
            break ;           

          case '=' :
            result = Pile_bis.depiler() ;
            cout  << "> " << result << endl ;
            break ;
        }

            if(pile)
            Pile_bis.Afficher();
    }
  }
  
  char Calculatrice::saisie(int & V)
  {		
    // Cette fonction saisit une string (S) l'analyse
	  // puis renvoie un caractere indiquant le type saisie :
  	// 'v' pour une valeur stockee dans V
  	// le caractere pour un operateur ('+', '-'...)
  	// ou une commande ('a', 'q'...)
    // Dans le cas d'une valeur celle-ci est retournée 
    // dans l'argument V
  
    string S;

    cout << "< ";
    cin >> S;
    
    if((S[0]=='-' && S[1]=='\0') || S[0]!='-')
    {
		  switch(S[0])
      {

        //Au cas ou la saise est une opération
        case '/' :
          return '/' ;

        case '*' :
          return '*' ;

        case '-' : 
          return '-' ;

        case '+' :
          return '+' ;

        case '%' :
          return '%' ;


        //On passe a la saisie des commandes
        case '=' :
          return '=' ;

        case 'q' :
          return 'q' ;

        case 'Q' :
          return 'Q' ;

        case ':' :
          return ':' ;

        case 'd' :
          return 'd' ;

        case 'a' :
          return 'a' ;

        //On passe au valeur int
        default :
          int i=0 ;
          int n=S.size();

          while(n>0)
          {
            n-=1 ;
            V+=(S[i]-'0')*pow(10,n) ;
            i++ ;
          }
          
          return 'v' ;   
      }
    }
    else
    {
      int n=S.size();
      int j=1 ;
      
      while(n>1)
      {
        n-=1;
        V+=(S[j]-'0')*pow(10,n-1) ;
        j++ ;
      }
        
      V*=(-1) ;
      
      return 'v' ;
      } 

    }
