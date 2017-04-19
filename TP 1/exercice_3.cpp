#include <iostream>

using namespace std ;

double cos(double x, double epsilon) ;

double sin(double x,double epsilon)
{
  double result=0.0 ;

  if(x<epsilon) {return x ;}
  else
  {
    result=2*sin(x/2.0,epsilon)*cos(x/2.0,epsilon) ;
  }

  return result ;
}

double cos(double x,double epsilon)
{
  double rst=0 ;
  if(x<epsilon) {return 1 ;}
  else
  {
    double y=cos(x/2.0,epsilon) ;
    double z=sin(x/2.0,epsilon) ;

    rst= y*y - z*z ;
  }

  return rst ;
}

int main()
{
  double cpt_cos=0.0, cpt_sin=0.0 ;
  double x=5 ;
  double epsilon=0.1 ;

  cpt_sin=sin(x,epsilon) ;
  cpt_cos=cos(x,epsilon) ;

  cout << "le sinus de " << x << " est de : " << cpt_sin << endl ;
  cout << "Le cosinus de " << x << " est de : " << cpt_cos << endl ;

  return 0 ;
}
