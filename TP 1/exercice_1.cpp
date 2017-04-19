#include <iostream>
#include <string.h>

using namespace std ;

bool palindrone(char* s, int d, int f)
{
  if(strlen(s)<2) {return true ;}
  else
  {
    if(s[d]==s[f])
    {
      if(palindrone(s,d+1,f-1)) {return true ;}
      else {return false ;}
    }
  }
}

int main()
{
  char s[10]="couoc" ;
  int d=0 ;
  int f=4;
  bool vrai ;

  vrai=palindrone(s,d,f) ;

  if(vrai==true) {cout << "c'est un palindrone" << endl ;}
  else {cout << "ce n'est pas un palindrone" << endl ;}
}
