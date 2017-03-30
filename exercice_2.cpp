#include <iostream>

using namespace std ;

int fact_iterative(int n)
{
  int cpt=1 ;

  for(int i=1 ; i<n+1 ; i++) {cpt=cpt*i ;}

  return cpt ;
}

int fact_recursive(int n)
{
  if(n==0) {return 1 ;}
  else {return n*fact_recursive(n-1) ;}
}

int main()
{
  int n=3, cpt_i=0, cpt_f=0 ;

  cpt_i=fact_iterative(n) ;
  cpt_f=fact_recursive(n) ;

  cout << cpt_f << endl ;
}
