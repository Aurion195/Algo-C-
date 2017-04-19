#include <iostream>
#include <string.h>

using namespace std ;

void miroir()
{
  int N=1, cpt=0 ;
  char x ;

  cin >> x ;

  if(x=='.') {return ;}
  else
  {
    miroir() ;
  }

  cout << x << endl ;
}

int main()
{
  miroir() ;

}
