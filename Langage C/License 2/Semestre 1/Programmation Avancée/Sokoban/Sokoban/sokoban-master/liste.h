#ifndef _LISTE_H
#define _LISTE_H
#include<stdlib.h>
#include<stdio.h>
/*structure position*/
struct point_s 
{
	int x ;	
	int y ;
};
typedef struct point_s point_t ;


typedef struct maillon_s maillon_t;
struct maillon_s 
{
	point_t *val ;
	maillon_t *suivant;
};

struct liste_s
{
	maillon_t * premier;
	maillon_t * dernier;
	int taille;
};

typedef struct liste_s liste_t;
liste_t * liste_initialiser();
int liste_vide(liste_t *a);
int liste_cardinal(liste_t *a);
void liste_ajouter_debut(liste_t *a, point_t*);
/*void liste_ajouter_fin(liste_t *a, point_t);
struct maillon_s *liste_extraire_debut(liste_t *a);
int appartient(liste_t *a , point_t);
void liste_supprimer(liste_t *a ,point_t);*/
/*manque dans le TD */
void liste_afficher(liste_t *a);
void liste_detruire_maillon(maillon_t *a);
void liste_detruire(liste_t *a);
void liste_detruire_point(point_t *a);
#endif


