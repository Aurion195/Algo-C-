void Maillon::supprime_1er(int X)								//Question 3
{
	Maillon* tmp = debut ;
	Maillon* tmp2 = NULL ;

	while(tmp!=NULL && tmp->info <= X)
	{
		if(tmp2 == NULL && tmp->info == X)
		{
			debut = tmp->suiv ;
			delete tmp ;
			tmp = debut ;

			return ;
		}
		else
		{
			tmp2 = tmp ;
			tmp = tmp->suiv ;

			if(tmp->info == X)
			{
				tmp2 = tmp->suiv ;
				delete tmp ;
				tmp = tmp2 ;

				return ; 
			}
		}
	}
}


void Maillon::supprime_tout(int X)				//Question 4
{
	Maillon* tmp=debut ;
	Maillon* tmp2=NULL ;

	while(tmp!=NULL && tmp->info <= X)
	{
		if(tmp->info == X)
		{
			if(tmp2 == NULL)
			{
				debut = tmp->suiv ;
				delete tmp ;
				tmp2 = debut ;
			}
			else
			{
				tmp2 = tmp->suiv ;
				delete tmp ;
				tmp = tmp2 ; 
			}
		}

		tmp2 = tmp ;
		tmp = tmp->suiv ;
	}
}

void Liste::concatene(Liste& L1, Liste& L2)
{
	Maillon* bis = L1.debut ;
	Maillon* tres = L2.debut ;

	bool con = true ;

	while(con)
	{

			Maillon* dernier ;
			dernier = new Maillon ;

			dernier->info = bis->info ;
			dernier->suiv = bis->suiv ;

			bis = bis->suiv ;
			if(bis->suiv == NULL)
			{
				dernier->suiv =

		con = false ;
	}

	while(L1.debut!=NULL)
	{	
		Maillon* sup=debut ;

		if(L1.debut==NULL) {return ;}
  		L1.debut= sup -> suiv ;

  		delete sup ;
	}

	while(L2.debut!=NULL)
	{	
		Maillon* sup2=debut ;

		if(L2.debut==NULL) {return ;}
  		L2.debut= sup2 -> suiv ;

  		delete sup2 ;
	}
}



