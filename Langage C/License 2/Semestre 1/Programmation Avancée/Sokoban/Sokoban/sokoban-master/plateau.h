#ifndef _PLATEAU_H
#include<stdlib.h>
#include<stdio.h>
/*Structure plateau*/
struct plateau_s
{
	char **tableau;
	int hauteur;
	int longueur;	
};
typedef struct plateau_s  plateau_t;
/*Déclarations des fonctions utilisateurs*/
plateau_t * creer_plateau(int  ,int );
void detruire_plateau(plateau_t *);
void afficher_plateau(plateau_t *);
char contenu_case(int i , int j ,plateau_t *);
int modifier_case( int i ,int j,plateau_t * , char );
plateau_t *charger_plateau(const char *);
#endif



	
