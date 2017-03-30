#include <iostream>

using namespace std ;

int PGCD(int a, int b)
{
  if(a>b) return PGCD(b,a-b) ;
  else if (a<b) return PGCD(a,b-a) ;
  else return a ;
}


int main()
{
  int a=4, b=6, pgcd=0 ;

  pgcd=PGCD(a,b) ;

  cout << pgcd << endl ;

}
