#i#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float* creatab1D(int n)                               //Cette fonction va permettre la creation du vecteur nul pour la résolution de Jacobi et Gauss Seidel
{
    float* tab;

    tab = malloc(n * sizeof(float));
    if (tab == NULL)                                                // On vérifie si l'allocation a marché ou non
    {
        exit(0);                                                    // On arrête tout
    }

    for (int i = 0; i < n; i++)
    {
        tab[i] = 0;                                                 // On affiche vecteur pour vérification
    }



    for (int i = 0; i < n; i++)
    {
        printf("%f \t", tab[i]);                                    // On libère la mémoire allouée avec malloc, on n'en a plus besoin
    }
    return tab;
}



void affiche_tab(float* tab, int n)                     //affiche_tab (float **tab, int nbc , int nbl)
{                                                                   //Fonction qui affiche le tab qu'on lui donne
    for (int i = 0; i < n; i++)                                   //Les param�tres sont un tableau "tab" allou� dynamiquement, et sont nombre de lignes et colonnes "nbc"et "nbl"
    {                                                               // Une Double boucle for qui affiche chaque valeur de notre matrice
        printf("%f \t", tab[i]);
        printf("\n");
    }
}


int choix_usa(int choix)
{
    int colonne;
    if (choix = 1)
    {
        colonne = 20;
        return colonne;
    }
    else if (choix = 2)
    {
        colonne = 21;
        return colonne;
    }
    else if (choix = 3)
    {
        colonne = 11;
        return colonne;
    }
    else if (choix = 4)
    {
        colonne = 7;
        return colonne;
    }
    else
    {
        printf("Choix invalide");
        return 0;
    }
}

int main()
{
    int nb_colonne;
    int choix_tab;
    printf("Quel Exercice voulez vous?");
    scanf("%d", &choix_tab);

    nb_colonne = choix_usa(choix_tab);
    printf("Votre choix est : %d \ Et vous avez %d colonnes.\n ", choix_tab, nb_colonne);


    float* tab_x;
    float* tab_y;
    tab_x = creatab1D(nb_colonne);
    tab_y = creatab1D(nb_colonne);

    printf("Tableau des X : \n");
    affiche_tab(tab_x, nb_colonne);
    printf("tableau des Y : \n");
    affiche_tab(tab_y, nb_colonne);



    free(tab_x);
    free(tab_y);



    return 0;
}