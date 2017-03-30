#include <iostream>
#include <cmath>

using namespace std ;

double puissance(int n, double x)
{
  if (n==0) {return 1 ;}
  else {return x*puissance(n-1,x) ;}
}

int main()
{
  int n=2 ;
  double x=6, result=0 ;

  result=puissance(n,x) ;

  cout << result << endl ;

  return 0 ;
}
