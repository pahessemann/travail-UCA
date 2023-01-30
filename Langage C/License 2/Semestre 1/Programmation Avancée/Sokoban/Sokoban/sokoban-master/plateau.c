#include"plateau.h"
/*Creation du plateau*/
plateau_t *creer_plateau(int h, int l) {
	int i,j;	
	plateau_t * res =NULL;
	res=(plateau_t*)malloc(sizeof(plateau_t));
	res->tableau = (char **)malloc(sizeof(char*) * h);
	for ( i = 0 ; i < h ; i ++)
	{
		res->tableau[i] = (char *)malloc(sizeof(char) * l);
	}
	res->longueur=l;
	res->hauteur=h;
	return res;
}

/*Destruction du plateau*/	
void detruire_plateau(plateau_t *det_plat) 
{
	free(det_plat->tableau);
	free(det_plat);
}

/*Affichage du contenue d'une case*/
char contenu_case(int x, int y, plateau_t * c_case)
{		
	 return c_case->tableau[x][y];
}

/*Modification du contenu d'une case*/
int modifier_case(int x ,int y,plateau_t *p, char v)
{
	int reussite = 1;
	switch(v) {
	case 'M':
	case 'P':
	case 'A':
	case 'C':
	case '.':

		p->tableau[x][y] = v;
		break;
	default:
		reussite = 0;
	}	
	return reussite;
}

/*Affichage du plateau*/	
void afficher_plateau(plateau_t *affic_plat)
{
	int i , j;
	for(i=0 ;i < affic_plat->hauteur; i++)
	{
		for(j=0;j < affic_plat->longueur; j++)
		{
			
			printf(" %c",affic_plat->tableau[i][j]);
			
		}
		printf("\n");
	}
}


plateau_t *charger_plateau( const char *fichier)
{	
	int i , j;
	plateau_t *res = NULL;
	int h,l;
        char p;
	FILE *f = NULL;
	f = fopen(fichier,"r");
	fscanf(f, "%d %d\n",&h,&l);
	res = creer_plateau(h,l);
	for(i=0; i < res->hauteur; i++)
	{ 
		for(j=0; j < res->longueur; j++)
		{

			fscanf(f, "%c", &res->tableau[i][j]);
			

		}
		fscanf(f, "%c", &p); /* faire passer la tête de lecture à la ligne suivante */
		

	}
	fclose(f);
return res ;	
}

