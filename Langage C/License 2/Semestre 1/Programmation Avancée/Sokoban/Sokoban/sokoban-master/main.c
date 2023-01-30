#include <stdlib.h>
#include "partie.h"
/*Fonction principale*/
int main()
{	partie_t *k = NULL;
	k = nouvelle_partie("partie_1.map");
	/* printf("position avant joueur: x[%d] , y=[%d]\n",k->pos_joueur.x,k->pos_joueur.y);*/
	 afficher_plateau(k->plateau_partie);
	 jouer_coup(k,&k->pos_joueur);
         detruire_partie(k);
	
	return EXIT_SUCCESS;
}


		
	
