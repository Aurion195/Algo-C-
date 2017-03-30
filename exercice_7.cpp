#include <iostream>

using namespace std ;

int puissance(int x, int n)
{
  int cpt=0 ;

  if(n==0) {return 1 ;}
  else if (n%2==0) {return cpt=puissance(x*x,n/2) ;}
  else {return cpt=x*puissance(x,n-1) ;}
}

int main()
{
  int x, n, result ;

  x=2 ; n=3 ;
  result=puissance(x,n) ;

  cout << result << endl ;
}
