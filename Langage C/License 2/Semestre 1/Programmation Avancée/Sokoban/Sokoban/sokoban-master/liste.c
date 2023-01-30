#include "liste.h"
liste_t *liste_initialiser()
{
	liste_t *l;
	l=(liste_t*)malloc(sizeof(liste_t));
	l->taille = 0;
	l->premier = NULL;
	l->dernier = NULL;
	return l  ;
}	
int liste_vide(liste_t *a)
{
	return(0 == a->taille);
}
int liste_cardinal(liste_t *a)
{
	return(a->taille);
}
void liste_ajouter_debut(liste_t *l, point_t *x)
{
	maillon_t *m;
	m=(maillon_t*)malloc(sizeof(maillon_t));
	m->val = x;
		m->suivant = l->premier;
		l->premier = m;
		l->taille = l->taille +1;
         
	
}
void liste_detruire_maillon(maillon_t *a)
{
	free(a);
}
void liste_detruire_point(point_t *a)
{ 
	free(a);
       
}
void liste_detruire(liste_t *a)
{
	
	maillon_t * resultat ;
	resultat = a->premier ;
	
       
	while(a->taille!=0)
	{
		
		liste_detruire_point(resultat->val);
		liste_detruire_maillon(resultat);
		resultat = resultat->suivant ;
		a->taille = a->taille - 1;
	}
	free(a);
}	
void liste_afficher(liste_t *l)
{
	maillon_t *m;
	for(m=l->premier; m!=NULL ;m=m->suivant)
	{
		printf("position x=[%d] y=[%d]\n",m->val->x,m->val->y);
	}
}
/*void liste_ajouter_fin(liste_t *l, point_t x)
{
	maillon_t *m;
	m=(maillon_t*)malloc(sizeof(maillon_t));
	m->val = x;
	m->suivant = NULL;
	if(liste_vide(l))
	{
		l->premier = m;
	}
		else{
			(l->dernier)->suivant = m;
		    }
			l->dernier = m;
}
struct maillon_s *liste_extraire_debut(liste_t *l)
{	
	maillon_t * res = l-> premier;
	l-> premier = res-> suivant;
	l->taille--;
	res->suivant = NULL;
return res;
}




int appartient(liste_t *l, point_t p)
{
	maillon_t *tmp = l->premier;
	while(tmp!=NULL)
	{
		if((tmp->val.x==p.x) && (tmp->val.y==p.y) )
		{
			return 1;
			tmp= tmp->suivant;
		}
			
	}	
	
	return 0;
}*/





	
	






