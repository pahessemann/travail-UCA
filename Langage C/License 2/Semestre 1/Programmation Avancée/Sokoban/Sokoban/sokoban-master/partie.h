#ifndef _PARTIE_H
#define _PARTIE_H
#include "liste.h"
#include "plateau.h"

/*structure partie*/
struct partie_s 
{
	plateau_t * plateau_partie;
	point_t pos_joueur ;
	int score;
	liste_t *pos_case_arrivee;
	liste_t *coups;

};
typedef struct partie_s  partie_t ;

/*Déclarations des fonctions utilisateurs*/
partie_t *nouvelle_partie(const char * f);
void detruire_partie(partie_t *p);
int partie_terminee(partie_t *t);
int coup_autorise(partie_t* , char);
void deplacement(int n, point_t *p);
void modif_pos_joueur(partie_t *partie, point_t *p,int n,int* c);
void jouer_coup(partie_t *p, point_t *s);
void annuler_coup(partie_t *partie,point_t* p,point_t *positionreel,int c,int j);
int tester_plateau();
liste_t *case_arrivee(plateau_t *t);
point_t pos_joueur(plateau_t *t);
point_t creer_position(int , int);
#endif
