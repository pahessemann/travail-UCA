﻿#include <stdio.h>
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

void remplissage_matrice_exo(float* tab,float* tab2, int d)
{


switch(d)
{

    case 1:
    
    printf("cas 1 densité de l'eau\n");
    tab[0] = 0;
    tab[1] = 2;
    tab[2] = 4;
    tab[3] = 6;
    tab[4] = 8;
    tab[5] = 10;
    tab[6] = 12;
    tab[7] = 14;
    tab[8] = 16;
    tab[9] = 18;
    tab[10] = 20;
    tab[11] = 22;
    tab[12] = 24;
    tab[13] = 26;
    tab[14] = 28;
    tab[15] = 30;
    tab[16] = 32;
    tab[17] = 34;
    tab[18] = 36;
    tab[19] = 38;


    tab2[0] = 0.99987;
    tab2[1] = 0.99997;
    tab2[2] = 1.0;
    tab2[3] = 0.99997;
    tab2[4] = 0.99988;
    tab2[5] = 0.99973;
    tab2[6] = 0.99953;
    tab2[7] = 0.99927;
    tab2[8] = 0.99897;
    tab2[9] = 0.99846;
    tab2[10] = 0.99805;
    tab2[11] = 0.999751;
    tab2[12] = 0.99705;
    tab2[13] = 0.99650;
    tab2[14] = 0.99664;
    tab2[15] = 0.99533;
    tab2[16] = 0.99472;
    tab2[17] = 0.99472;
    tab2[18] = 0.99333;
    tab2[19] = 0.99326;
    
    


    break;
/*
    case 2:
    printf("cas 2 dépense mensuelles\n");
    tab[0][0] = 752;
    tab[0][1] = 855;
    tab[0][2] = 871;
    tab[0][3] = 734;
    tab[0][4] = 610;
    tab[0][5] = 582;
    tab[0][6] = 921;
    tab[0][7] = 492;
    tab[0][8] = 569;
    tab[0][9] = 462;
    tab[0][10] = 907;
    tab[0][11] = 643;
    tab[0][12] = 862;
    tab[0][13] = 524;
    tab[0][14] = 679;
    tab[0][15] = 902;
    tab[0][16] = 918;
    tab[0][17] = 928;
    tab[0][18] = 875;
    tab[0][19] = 809;
    tab[0][20] = 894;

    tab[1][0] = 85;
    tab[1][1] = 83;
    tab[1][2] = 162;
    tab[1][3] = 79;
    tab[1][4] = 81;
    tab[1][5] = 83;
    tab[1][6] = 281;
    tab[1][7] = 81;
    tab[1][8] = 81;
    tab[1][9] = 80;
    tab[1][10] = 243;
    tab[1][11] = 84;
    tab[1][12] = 84;
    tab[1][13] = 82;
    tab[1][14] = 80;
    tab[1][15] = 226;
    tab[1][16] = 260;
    tab[1][17] = 82;
    tab[1][18] = 186;
    tab[1][19] = 77;
    tab[1][20] = 223;

    break;

    case 4:
    printf("cas 4 loi de Pareto\n");
    nbcolonne=20;
    creatab2d(2,6);
    break;
*/
    default:
    printf("erreur\n");
    break;
}
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
    if (choix == 1)
    {
        colonne = 20;
        return colonne;
    }
    else if (choix == 2)
    {
        colonne = 21;
        return colonne;
    }
    else if (choix == 3)
    {
        colonne = 11;
        return colonne;
    }
    else if (choix == 4)
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
    printf("Votre choix est : %d \n Et vous avez %d colonnes.\n ", choix_tab, nb_colonne);


    float* tab_x;
    float* tab_y;
    tab_x = creatab1D(nb_colonne);
    tab_y = creatab1D(nb_colonne);

    printf("Tableau des X : \n");
    affiche_tab(tab_x, nb_colonne);
    printf("tableau des Y : \n");
    affiche_tab(tab_y, nb_colonne);
    remplissage_matrice_exo(tab_x,tab_y, choix_tab);
    affiche_tab(tab_x, nb_colonne);

affiche_tab(tab_y, nb_colonne);
    
    printf("Simple demande donner un entier :");
    int je_sers_a_conclure_programme ;
    scanf("%d", &je_sers_a_conclure_programme); 

    free(tab_x);
    free(tab_y);



    return 0;
}