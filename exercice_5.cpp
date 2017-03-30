#include <iostream>

using namespace std ;

void inserer(int *T, int N)
{
  int x, i ;
  i=N-1 ;
  x=T[N] ;

  while(x<T[i] && i>0)
  {
    T[i+1]=T[i] ;
    i-- ;
  }
  T[i+1]=x ;
}

void trier(int *T, int N)
{
  if(N==0) {return ;}
  else
  {
    trier(T,N-1) ;
    inserer(T,N) ;
  }
}

int main()
{
  int N=6 , T[N]={1,2,3,5,6,4} ;

  inserer(T,N) ;
  trier(T,N) ;
  for(int i=0 ; i<N ; i++) {cout << T[i] << "\n" << endl ;}


}
