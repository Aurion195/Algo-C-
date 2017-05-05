#ifndef DEF_CLASSE_H
#define DEF_CLASSE_H

#include <iostream>
#include <string>

class Personne 
{
	std::string Nom ;
  std::string Prenom ;
  std::string Adresse ;
  int CodePostale ;
  std::string NumDeTel ;

  public :
  Personne(std::string nomf, std::string prenom, std::string Addresse, int CP, std::string num);
} ;

class Maillon
{
  friend class Liste ;
  int info ;
  Maillon *suiv ;
} ;

class Liste
{
  Maillon *debut ;
} ;

#endif
