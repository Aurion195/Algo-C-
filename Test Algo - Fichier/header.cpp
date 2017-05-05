#include <iostream>
#include <string>
#include <fstream>
#include <set>

#include "Header.h"

using namespace std ;


//------------On commence la classe personne---------------------------

Personne::Personne(string nomf, string prenom, string Addresse, int CP, string num)
{
	Nom=nomf ;
	Prenom=prenom ;
	Adresse=Addresse ;
	CodePostale=CP ;
	NumDeTel=num ;
}

//------------On commence les fonctions non menbres-------------------------

void creer()
{
	string nom=" " ;
	cout << "Quel est le nom du réportoire ! " ; cin >> nom ;
	nom+=".txt" ;
	ifstream fichier(nom.c_str(), ios::in) ;

	if(fichier) {fichier.close() ;}
	else {cerr << "Pas de fichier texte" << endl ;}
}

void ouvrir()
{
	string nom ;
	cout << "Quel réportoire voulez-vous ouvrir ? " ; cin >> nom ;
	nom+=".txt" ;

	ifstream fichier(nom.c_str(), ios::in) ;

	if(fichier) 
	{
		string ligne ;

		while(getline(fichier,ligne))
		{
			cout << ligne << endl ;
		}

		fichier.close() ;
	}
	else 
	{
		cerr << "Pas de fichier texte !" << endl ;
	}
}

void Ajouter()
{
	string nom ;
	cout << "Dans quel réportoire voulez-vous ajouter cette personne ? " ; cin >> nom ;
	nom+=".txt" ;

	string nomf, prenom,num ;
	string Addresse ; 
	string ligne ;
	int CP ;

	cout << "Nom : " ; cin >> nomf ;
	cout << "Prenom : " ; cin >> prenom ;
	cout << "Numéro de téléphone : " ; cin >> num ;
	cout << "Code postale : " ; cin >> CP ;
	cout << "Adresse : " ; getline(cin,Addresse) ;
	cout << endl ;

	ifstream ifs(nom.c_str(), ios::app) ;

	if(ifs)
	{
		 while(getline(ifs,ligne))
		{
			string nom_famille, prenom_famille ;

			ifs >> nom_famille >> prenom_famille ;

			if(nom_famille==nomf && prenom_famille==prenom)
			{
				cout << "Erreur ! le nom est déjà inscrit ! " << endl ;
				break ;
				ifs.close() ;
			}
		}
			
		cout << "La personne n'est pas dedans continuer son inscriptions ! " << endl ;
	}
	else
	{
		cout << "Il n'y a pas d'annuaire !" << endl ;
	}

	ofstream fichier_bis(nom.c_str(), ios::in | ios::app) ;

	if(fichier_bis)
	{
		Personne X(nomf, prenom, Addresse, CP, num) ;

		fichier_bis << nomf << " " << prenom << " " << num << " " << CP << " " << Addresse << endl ;

		fichier_bis.close() ;
	}
	else
	{
		cout << "Erreur" << endl ;
	}
}

void Afficher()
{
	string nom ;
	cout << "Dans quel réportoire voulez-vous ajouter cette personne ? " ; cin >> nom ;
	nom+=".txt" ;

	ifstream fichier(nom.c_str(), ios::in) ;

	if(fichier)
	{	
		string chercher, chercher_bis ;
		cout << "Entrer le nom : " ; cin >> chercher ;
		cout << "Entrer le prénom : " ; cin >> chercher_bis ;

		string ligne ;
		do 
		{
			string nomf,prenomf ;
			fichier >> nomf >> prenomf ;

			if(nomf==chercher && prenomf==chercher_bis)
			{
				string contenu ;
				getline(fichier,contenu) ;
				cout << nomf << " " << prenomf << " " << contenu << endl ;
			}
		} while(getline(fichier,ligne)) ;

		fichier.close() ;
	}
	else
	{
		cerr << "Pas de fichier !" << endl ;
	}
}

void Afficher_repertoire()
{
	string nom ;
	cout << "Dans quel réportoire voulez-vous ajouter cette personne ? " ; cin >> nom ;
	nom+=".txt" ;

	ifstream fichier(nom.c_str(), ios::in) ;

	if(fichier)
	{	
		string ligne ;

		while(getline(fichier,ligne))
		{
			cout << ligne << endl ;
		}

		fichier.close() ;
	}
	else
	{
		cerr << "Pas de fichier !" << endl ;
	}
}

void Afficher_alpha()
{
	/*Pour cette fonction comme je n'arrivais pas à voir comment la mettre en place en liste chainées
	  j'ai donc utiliser la librairie <set>*/

	string nom ;
	cout << "Quelle réportoire voulez-vous ouvrir ? " ; cin >> nom ;
	nom += ".txt" ;

    set<string> names ;				//Comme on ne précise pas de relation d'ordre se sera donc l'opérateur par défault ! <
    string ligne ;

    ifstream fichier(nom.c_str(), ios::in) ;

    if(!fichier)
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
    else
    {
    	while(getline(fichier,ligne))
        {
        	names.insert(ligne) ;		//Dans cette élément on écrit toutes les lignes du fichier trier par ordre alpha
        }

       	fichier.close();
    }
    
    
    set<string>::const_iterator				//permet d'accéder aux fonctions comme end et begins
    	names_it (names.begin()),			//on place dans names_it le debut de names
    	names_end(names.end());				//on place dans names_end la fin de names 

    for(;names_it != names_end;++names_it)		//On crée une boucle qui va du début à la fin et on affiche le répertoire !
    {
        const string & cur_name = *names_it;
        cout << cur_name << endl;
    }
}


void menu()
{
	int choix ; 

	cout << "1 - Créer un nouveaux répertoire." << endl ;
	cout << "2 - Ouvrir un répertoire existant." << endl ;
	cout << "3 - Ajouter une personne." << endl ;
	cout << "4 - Afficher une personne." << endl ;
	cout << "5 - Afficher tout le répertoire dans l'ordre du fichier." << endl ;
	cout << "6 - Aficher tout le répertoire dans l'ordre alphabétique des noms" << endl ;
	cout << "0 - Quitter." << endl ;

	cout << "Entrer votre choix : " ; cin >> choix ;

	switch(choix)
	{
		case 1 : creer() ; return ;
		case 2 : ouvrir() ; return ;
		case 3 : Ajouter() ; return ;
		case 4 : Afficher() ; return ;
		case 5 : Afficher_repertoire() ; return ;
		case 6 : Afficher_alpha() ; return ;
		case 0 : return ;
	}
}
