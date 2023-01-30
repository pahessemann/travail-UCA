#include <stdio.h>
#include <stdlib.h>
/*=========== Définitions des structures necessaires : =========*/

struct plateau_s														//structure plateau
{
	char** tableau;														// double tableau de carractère (tableau de tableau de char)
	int hauteur;														// valeur entière de stockage de hauteur de plateau
	int longueur;
};
typedef struct plateau_s  plateau_t;

struct point_s
{
	int x;
	int y;
};
typedef struct point_s point_t;


typedef struct maillon_s maillon_t;
struct maillon_s
{
	point_t* val;
	maillon_t* suivant;
};


struct liste_s
{
	maillon_t* premier;
	maillon_t* dernier;
	int taille;
};
typedef struct liste_s liste_t;




struct partie_s														// structure permettant de gérer les différentes informations de la partie
{
	plateau_t* plateau_partie;
	point_t pos_joueur;
	int score;
	liste_t* pos_case_arrivee;
	liste_t* coups;

};
typedef struct partie_s  partie_t;



/* ========= Fonctions liées au plateau de jeux : ================ */

plateau_t* creer_plateau(int h, int l) {
	int i;
	plateau_t* res = NULL;
	res = (plateau_t*)malloc(sizeof(plateau_t));
	res->tableau = (char**)malloc(sizeof(char*) * h);
	for (i = 0; i < h; i++)
	{
		res->tableau[i] = (char*)malloc(sizeof(char) * l);
	}
	res->longueur = l;
	res->hauteur = h;
	return res;
}


void detruire_plateau(plateau_t* det_plat)								//Destruction du plateau
{																		//Libération de la mémoire allouer
	free(det_plat->tableau);											//Appellée en fin de programme
	free(det_plat);
}


char contenu_case(int x, int y, plateau_t* c_case)						// Fonction d'affichage du contenu d'une case
{
	return c_case->tableau[x][y];
}


int modifier_case(int x, int y, plateau_t* p, char v)					//Fonction de modification du contenue d'une case
{
	int reussite = 1;
	switch (v) {
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

void afficher_plateau(plateau_t* affic_plat)							//Fonction d'affichage de Tab
{
	int i, j;
	for (i = 0; i < affic_plat->hauteur; i++)
	{
		for (j = 0; j < affic_plat->longueur; j++)
		{

			printf(" %c", affic_plat->tableau[i][j]);

		}
		printf("\n");
	}
}


plateau_t* charger_plateau(const char* fichier)
{
	int i, j;
	plateau_t* res = NULL;
	int h, l;
	char p;
	FILE* f = NULL;
	f = fopen(fichier, "r");
	fscanf(f, "%d %d\n", &h, &l);
	res = creer_plateau(h, l);
	for (i = 0; i < res->hauteur; i++)
	{
		for (j = 0; j < res->longueur; j++)
		{

			fscanf(f, "%c", &res->tableau[i][j]);


		}
		fscanf(f, "%c", &p); /* faire passer la tête de lecture à la ligne suivante */


	}
	fclose(f);
	return res;
}



/*============== Fonctions ==============*/

liste_t* liste_initialiser()
{
	liste_t* l;
	l = (liste_t*)malloc(sizeof(liste_t));
	l->taille = 0;
	l->premier = NULL;
	l->dernier = NULL;
	return l;
}
int liste_vide(liste_t* a)
{
	return(0 == a->taille);
}
int liste_cardinal(liste_t* a)
{
	return(a->taille);
}
void liste_ajouter_debut(liste_t* l, point_t* x)
{
	maillon_t* m;
	m = (maillon_t*)malloc(sizeof(maillon_t));
	m->val = x;
	m->suivant = l->premier;
	l->premier = m;
	l->taille = l->taille + 1;


}
void liste_detruire_maillon(maillon_t* a)
{
	free(a);
}
void liste_detruire_point(point_t* a)
{
	free(a);

}
void liste_detruire(liste_t* a)
{

	maillon_t* resultat;
	resultat = a->premier;


	while (a->taille != 0)
	{

		liste_detruire_point(resultat->val);
		liste_detruire_maillon(resultat);
		resultat = resultat->suivant;
		a->taille = a->taille - 1;
	}
	free(a);
}
void liste_afficher(liste_t* l)
{
	maillon_t* m;
	for (m = l->premier; m != NULL; m = m->suivant)
	{
		printf("position x=[%d] y=[%d]\n", m->val->x, m->val->y);
	}
}



/*===================== Gestion de la partie =====================*/



liste_t* case_arrivee(plateau_t* t)
{	/*int i, j;*/
	int i, j;
	liste_t* k = NULL;
	point_t* pointarrive = NULL;
	k = liste_initialiser();
	/* on commence l'ajout par le dernier element du plateau car la liste ajoute*/
	for (i = 0; i < t->hauteur; i++)
	{
		for (j = 0; j < t->longueur; j++)
		{
			if (t->tableau[i][j] == 'A')
			{
				pointarrive = (point_t*)malloc(sizeof(point_t));;
				pointarrive->x = i;
				pointarrive->y = j;
				liste_ajouter_debut(k, pointarrive);

			}

		}
	}
	return k;
}


point_t creer_position(int a, int b)
{
	point_t res;
	res.x = a;
	res.y = b;
	return res;
}


point_t pos_joueur(plateau_t* t)
{
	int i, j;
	point_t x;
	char c = 'P';
	for (i = 0; i < t->hauteur; i++)
	{
		for (j = 0; j < t->longueur; j++)

			if (t->tableau[i][j] == c)
			{
				x = creer_position(i, j);
				return x;
			}


	}
	return x;
}


/*Création d'une partie*/
partie_t* nouvelle_partie(const char* fichier)
{

	partie_t* res;
	res = (partie_t*)malloc(sizeof(partie_t));
	res->coups = liste_initialiser();
	res->plateau_partie = charger_plateau(fichier);
	res->pos_case_arrivee = case_arrivee(res->plateau_partie);
	res->pos_joueur = pos_joueur(res->plateau_partie);

	return res;
}

/*Destruction d'une partie*/
void detruire_partie(partie_t* p)
{

	liste_detruire(p->coups);
	liste_detruire(p->pos_case_arrivee);
	detruire_plateau(p->plateau_partie);
	free(p);

}

/*Teste si la partie est terminée*/
int partie_terminee(partie_t* t)
{
	char v = 'C';
	liste_t* tmp = t->pos_case_arrivee;
	maillon_t* m;/*variable de boucle */
	m = tmp->premier;
	for (m = tmp->premier; m != NULL; m = m->suivant)
	{

		if (t->plateau_partie->tableau[m->val->x][m->val->y] == v)
		{

		}
		else return 0;
	}

	return 1;
}


int coup_autorise(partie_t* partie, char move)
{
	int x = partie->pos_joueur.x;
	int y = partie->pos_joueur.y;
	if (move == 'g') /* g: deplacement à gauche*/
	{
		/*aller a gauche*/

		if ((partie->pos_joueur.y - 1 >= 0))
		{
			if (partie->plateau_partie->tableau[x][y - 1] != 'M' && partie->plateau_partie->tableau[x][y - 1] != 'A')
			{
				if (partie->plateau_partie->tableau[x][y - 1] == 'C' && (partie->pos_joueur.y - 2 >= 0))
				{
					if (partie->plateau_partie->tableau[x][y - 2] == '.' || partie->plateau_partie->tableau[x][y - 2] == 'A')
						return 2;
				}
				else if (partie->plateau_partie->tableau[x][y - 1] == '.')
					return 2;
			}
			return 0;
		}
		return 0;
	}


	if (move == 'j') /* j : deplacement à droite*/
	{
		/*aller à droite*/

		if ((partie->pos_joueur.y + 1 < partie->plateau_partie->longueur))
		{
			if (partie->plateau_partie->tableau[x][y + 1] != 'M' && partie->plateau_partie->tableau[x][y + 1] != 'A')
			{
				if (partie->plateau_partie->tableau[x][y + 1] == 'C' && (partie->pos_joueur.y + 2 < partie->plateau_partie->longueur))
				{
					if (partie->plateau_partie->tableau[x][y + 2] == '.' || partie->plateau_partie->tableau[x][y + 2] == 'A')
						return 1;
				}
				else if (partie->plateau_partie->tableau[x][y + 1] == '.')
					return 1;
			}
			return 0;
		}
		return 0;
	}
	if (move == 'y') /* y : deplacement  haut*/
	{
		/*aller en haut*/

		if ((partie->pos_joueur.x - 1 >= 0))
		{
			if (partie->plateau_partie->tableau[x - 1][y] != 'M' && partie->plateau_partie->tableau[x - 1][y] != 'A')
			{
				if (partie->plateau_partie->tableau[x - 1][y] == 'C' && (partie->pos_joueur.x - 2 >= 0))
				{
					if (partie->plateau_partie->tableau[x - 2][y] == '.' || partie->plateau_partie->tableau[x - 2][y] == 'A')
						return 3;
				}
				else if (partie->plateau_partie->tableau[x - 1][y] == '.')
					return 3;
			}
			return 0;
		}
		return 0;


	}

	if (move == 'h') /* h : deplacement bas */
	{
		/*aller en bas */


		if ((partie->pos_joueur.x + 1 < partie->plateau_partie->hauteur))
		{
			if (partie->plateau_partie->tableau[x + 1][y] != 'M' && partie->plateau_partie->tableau[x + 1][y] != 'A')
			{
				if (partie->plateau_partie->tableau[x + 1][y] == 'C' && (partie->pos_joueur.x + 2 < partie->plateau_partie->hauteur))
				{
					if (partie->plateau_partie->tableau[x + 2][y] == '.' || partie->plateau_partie->tableau[x + 2][y] == 'A')
						return 4;
				}
				else if (partie->plateau_partie->tableau[x + 1][y] == '.')
					return 4;
			}
			return 0;

		}
		return 0;
	}

	printf("Caractère non reconue \n");
	printf("=     y pour haut       =\n");
	printf("=     g pour gauche     =\n");
	printf("=     j pour droite     =\n");
	printf("=     h pour bas        =\n");
	printf("=     a pour annuler    =\n");
	return 0;
}



void annuler_coup(partie_t* partie, point_t* p, point_t* positionreel, int n, int j)
{
	switch (n)
	{
	case 1: 	partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x][p->y + 1] = '.';
		break;

	case 2:         partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x][p->y + 1] = 'C';
		partie->plateau_partie->tableau[p->x][p->y + 2] = 'A';
		break;

	case 22:        partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x][p->y + 1] = 'C';
		partie->plateau_partie->tableau[p->x][p->y + 2] = '.';
		break;

	case 3:		partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x][p->y - 1] = '.';
		break;

	case 4:		partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x][p->y - 1] = 'C';
		partie->plateau_partie->tableau[p->x][p->y - 2] = 'A';
		break;

	case 44:	partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x][p->y - 1] = 'C';
		partie->plateau_partie->tableau[p->x][p->y - 2] = '.';
		break;

	case 5: 	partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x - 1][p->y] = '.';
		break;

	case 6:		partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x - 1][p->y] = 'C';
		partie->plateau_partie->tableau[p->x - 2][p->y] = 'A';
		break;

	case 66:	partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x - 1][p->y] = 'C';
		partie->plateau_partie->tableau[p->x - 2][p->y] = '.';
		break;

	case 7: 	partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x + 1][p->y] = '.';
		break;

	case 8:		partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x + 1][p->y] = 'C';
		partie->plateau_partie->tableau[p->x + 2][p->y] = 'A';
		break;

	case 88:	partie->plateau_partie->tableau[p->x][p->y] = 'P';
		partie->plateau_partie->tableau[p->x + 1][p->y] = 'C';
		partie->plateau_partie->tableau[p->x + 2][p->y] = '.';
		break;
	default: break;
	}
	/* on fait le contraire de deplacement pour revenire à la position*/
	switch (j)
	{
	case 1: positionreel->y = positionreel->y - 1; break;
	case 2: positionreel->y = positionreel->y + 1; break;
	case 3: positionreel->x = positionreel->x + 1; break;
	case 4: positionreel->x = positionreel->x - 1; break;
	default: break;
	}

}

void modif_pos_joueur(partie_t* partie, point_t* p, int n, int* c)
{
	switch (n)
	{
	case 1: if (partie->plateau_partie->tableau[p->x][p->y + 1] == '.')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x][p->y + 1] = 'P';
		*c = 1;
	}
		  else if (partie->plateau_partie->tableau[p->x][p->y + 1] == 'C')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x][p->y + 1] = 'P';
		if (partie->plateau_partie->tableau[p->x][p->y + 2] == 'A')
			*c = 2;
		else if (partie->plateau_partie->tableau[p->x][p->y + 2] == '.')
			*c = 22;
		partie->plateau_partie->tableau[p->x][p->y + 2] = 'C';
	} break;
	case 2: if (partie->plateau_partie->tableau[p->x][p->y - 1] == '.')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x][p->y - 1] = 'P';
		*c = 3;
	}
		  else if (partie->plateau_partie->tableau[p->x][p->y - 1] == 'C')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x][p->y - 1] = 'P';
		if (partie->plateau_partie->tableau[p->x][p->y - 2] == 'A')
			*c = 4;
		else if (partie->plateau_partie->tableau[p->x][p->y - 2] == '.')
			*c = 44;
		partie->plateau_partie->tableau[p->x][p->y - 2] = 'C';
	} break;
	case 3: if (partie->plateau_partie->tableau[p->x - 1][p->y] == '.')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x - 1][p->y] = 'P';
		*c = 5;
	}
		  else if (partie->plateau_partie->tableau[p->x - 1][p->y] == 'C')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x - 1][p->y] = 'P';
		if (partie->plateau_partie->tableau[p->x - 2][p->y] == 'A')
			*c = 6;
		else if (partie->plateau_partie->tableau[p->x - 2][p->y] == '.')
			*c = 66;
		partie->plateau_partie->tableau[p->x - 2][p->y] = 'C';
	} break;
	case 4: if (partie->plateau_partie->tableau[p->x + 1][p->y] == '.')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		*c = 7;
		partie->plateau_partie->tableau[p->x + 1][p->y] = 'P';
	}
		  else if (partie->plateau_partie->tableau[p->x + 1][p->y] == 'C')
	{
		partie->plateau_partie->tableau[p->x][p->y] = '.';
		partie->plateau_partie->tableau[p->x + 1][p->y] = 'P';
		if (partie->plateau_partie->tableau[p->x + 2][p->y] == 'A')
			*c = 8;
		else if (partie->plateau_partie->tableau[p->x + 2][p->y] == '.')
			*c = 88;
		partie->plateau_partie->tableau[p->x + 2][p->y] = 'C';
	} break;
	default: break;
	}
}
/* avance le point p dans une direction en fonction de la valeur de n*/
/* exple: n=1 avance p à droite d'une case*/
/* exple: n=2 avance p à gauche d'une case*/

void deplacement(int n, point_t* p)
{
	switch (n)
	{
	case 1: p->y = p->y + 1; break;
	case 2: p->y = p->y - 1; break;
	case 3: p->x = p->x - 1; break;
	case 4: p->x = p->x + 1; break;
	default: break;
	}
}




/*Déplacement du joueurs*/
void jouer_coup(partie_t* p, point_t* s)
{
	char choix;
	int cond = 0;
	int coup = 0;/*permettra de savoir comment annuler le coup sur l'affichage*/
	point_t positionavant;/* on sauvegarde la position du joueur */
	/*positionavant=(point_t*)malloc(sizeof(point_t));*/
		 /*  */
	while (partie_terminee(p) == 0)
	{
		/* controle du caractère saisir par le joueur*/
		/*printf("===== JOUER UN COUP =====\n");
		printf("=                       =\n");
		printf("=     y pour haut       =\n");
		printf("=     g pour gauche     =\n");
		printf("=     j pour droite     =\n");
		printf("=     h pour bas        =\n");
		printf("=     a pour annuler    =\n");
		printf("=                       =\n");
		printf("=========================\n");*/
		printf("============= JOUER UN COUP ==========\n");
		printf("=                                    =\n");
		printf("=     y -> Haut: g -> Gauche: j-> Droite: h-> Bas   =\n");
		printf("======================================\n");
		scanf(" %c", &choix);
		printf("======================================\n");

		if ((choix == 'a') && (coup != 0) && (cond != 0))
		{
			annuler_coup(p, &positionavant, s, coup, cond);
			afficher_plateau(p->plateau_partie);
		}
		else
		{
			cond = coup_autorise(p, choix);

			if (cond != 0)
			{
				/* modification de position du joueur au niveau affichage*/
				modif_pos_joueur(p, s, cond, &coup);

				positionavant.x = s->x;
				positionavant.y = s->y;
				/*modifie position du joueur au niveau coordornnée*/
				deplacement(cond, s);
				/*printf("position après joueur: x[%d] , y=[%d]\n",p->pos_joueur.x,p->pos_joueur.y);*/
				afficher_plateau(p->plateau_partie);


			}
			else
			{
				printf(" deplacement impossible ... \n");
				afficher_plateau(p->plateau_partie);

			}
		}
		p->score++;
	}
	printf(" Partie Terminée votre SCORE: %d\n", p->score);

	

}







/*================= Main de notre code ================*/

int main()
{
	partie_t* k = NULL;
	k = nouvelle_partie("partie_1.map");
		afficher_plateau(k->plateau_partie);
	jouer_coup(k, &k->pos_joueur);
	detruire_partie(k);

	return EXIT_SUCCESS;
}