#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float** creatab2D(int ligne, int colonne)                               //Fonction qui permet de crée et d'alloué un Tableau a deux dimensions
{                                                                       // En paramètre on recoit le nombre de lignes et de colonnes
    float** Tableau = NULL;                                             // le malloc alloue la mémoire nécessaire par rapport au type de variable utilisé et le nombre de ligne
    Tableau = malloc(sizeof(float*) * ligne);                           // en cas d'erreur de l'allocations le programme s'arrête

    if (Tableau == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < ligne; i++)
    {
        Tableau[i] = malloc(sizeof(float) * colonne);

        if (Tableau[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(Tableau[j]);
            }
            free(Tableau);
            return NULL;
        }
    }
    return Tableau;
}


float* creatab1D(float* tab, int n)                               //Cette fonction va permettre la creation du vecteur nul pour la résolution de Jacobi et Gauss Seidel
{
    printf("Création du Vecteur null de résolution ! \n");
    tab = malloc(n * sizeof(float));
    if (tab == NULL)                                                // On vérifie si l'allocation a marché ou non
    {
        exit(0);                                                    // On arrête tout
    }

    for (int i = 0; i < n; i++)
    {
        tab[i = 0];                                                 // On affiche vecteur pour vérification
    }



    for (int i = 0; i < n; i++)
    {
        printf("%f \n", tab[i]);                                    // On libère la mémoire allouée avec malloc, on n'en a plus besoin
    }
}


void affiche_matrice(float** tab, int nbc, int nbl)                 //affiche_matrice (float **tab, int nbc , int nbl)
{                                                                   //Fonction qui affiche la matrice qu'on lui donne
    for (int i = 0; i < nbl; i++)                                   //Les paramètres sont un tableau "tab" alloué dynamiquement, et sont nombre de lignes et colonnes "nbc"et "nbl"
    {                                                               // Une Double boucle for qui affiche chaque valeur de notre matrice
        for (int j = 0; j < nbc; j++)
        {
            printf("%f \t", tab[i][j]);
        }
        printf("\n");
    }
}


void affiche_vecteur(float* tab, int n)
{
    printf("Voici le vecteur souhaité : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%f", tab[i]);
    }
}


void remplissage_matrice(float** tab, int nbc, int nbl)                     //remplissage_matrice (float **tab, int nbc , int nbl)
{                                                                           //Les paramètres sont un tableau "tab" alloué dynamiquement, et sont nombre de lignes et colonnes "nbc"et "nbl"
    for (int i = 0; i < nbl; i++)                                           // Pour chaque itérations du double for on demande a l'utilisateur une valeur avec le scanf
    {                                                                       // On stock la valeur dans la matrice
        for (int j = 0; j < nbc; j++)
        {
            printf("Donnez la valeur de la case %d, %d \n", i, j);
            scanf("%f", &tab[i][j]);
        }

    }
}


float* creat_vect(float* tab, int ligne)
{
    printf("Création du Vecteur de résolution !\n");
    tab = malloc(ligne * sizeof(float));
    if (tab == NULL)                                           // On vérifie si l'allocation a marché ou non
    {
        exit(0);                                                // On arrête tout
    }

    for (int i = 0; i < ligne; i++)                             // On demande la valeur des cases
    {
        printf("Valeur de la case numero %d ? \n ", i + 1);
        scanf("%f", &tab[i]);
    }

    for (int i = 0; i < ligne; i++)
    {
        printf("%f \n", tab[i]);                                 // On affiche vecteur pour vérification
    }
}

float choix_matrice(float** A, int nb)
{
    int mat;
    nb = 3;
    printf("Voici les matrices disponibles : \n");
    printf("1 - ...\n");
    printf("2 - ...\n");
    printf("3 - ...\n");
    printf("4 - ...\n");
    printf("5 - ...\n");
    printf("6 - ...\n");
    printf("7 - Matrice personnalisée\n");

    printf("Néanmoins seule la matrice personnalisée fonctionne correctement. Veuillez nous excuser.");
    printf("Quelle matrice voulez vous?\n");
    scanf("%d", &mat);

    if (mat > 4)
    {
        printf("Donnez un nombre au système: \n");
        scanf("%d", &nb);

    }

    A = creatab2D(nb, nb);
    printf("Matrice nulle poure vérification : \n");
    affiche_matrice(A, nb, nb);

    switch (mat) {

    case 1:
        printf("Matrice 1\n");
        A[0][0] = 3;
        A[0][1] = 0;
        A[0][2] = 4;
        A[1][0] = 7;
        A[1][1] = 4;
        A[1][2] = 2;
        A[2][0] = -1;
        A[2][1] = 1;
        A[2][2] = 2;


        break;

    case 2:
        printf("Matrice 2\n");
        A[0][0] = -3,
            A[0][1] = 3,
            A[0][2] = 6,
            A[1][0] = -4,
            A[1][1] = 7,
            A[1][2] = 8,
            A[2][0] = 5,
            A[2][1] = 7,
            A[2][2] = -9;
        break;

    case 3:

        printf("Matrice 3\n");
        A[0][0] = 4,
            A[0][1] = 1,
            A[0][2] = 1,
            A[1][0] = 2,
            A[1][1] = -9,
            A[1][2] = 0,
            A[2][0] = 0,
            A[2][1] = -8,
            A[2][2] = 6;
        break;

    case 4:

        printf("Matrice 4\n");
        A[0][0] = 7,
            A[0][1] = 6,
            A[0][2] = 9,
            A[1][0] = 4,
            A[1][1] = 5,
            A[1][2] = -4,
            A[2][0] = -7,
            A[2][1] = -3,
            A[2][2] = 8;
        break;

    case 7:


        printf("Matrice personnalisée \n");


        remplissage_matrice(A, nb, nb);
        printf("Affichage de la matrice pour vérification : \n ");
        affiche_matrice(A, nb, nb);
        break;

    default:

        printf("invalide\n");
    }

    printf("La matrice choisie est : \n ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f \t", A[i][j]);                     //Double for qui affiche chaque valeur de notre matrice
        }
        printf("\n");

    }
    return nb;
}


float* meth_gauss(float** tab, int nbc, int nbl, float* vecteur)          //meth_gauss (float **tab, int nbc , int nbl, float **vecteur)
{                                                                       //Les paramètres sont un tableau "tab" alloué dynamiquement, et sont nombre de lignes et colonnes "nbc"et "nbl" et une liste alloué dynamiquement "vecteur"
    for (int k = 1; k < nbl - 1; k++)                                   //l'algorithme simple de gauss selon le modèle donné dans le cours
    {
        for (int i = k + 1; i < nbl; i++)
        {
            float pivot;
            pivot = (tab[i][k]) / (tab[k][k]);
            printf("Pivot = %f", pivot);
            for (int j = k; j < nbl; j++)
            {
                tab[i][j] = tab[i][j] - (pivot * tab[k][j]);
            }
            vecteur[i] = vecteur[i] - (pivot * vecteur[k]);
        }

    }
    affiche_matrice(tab, nbc, nbl);
    affiche_vecteur(tab, nbc);  //à vérifier
    return tab;
}


double jacobi(float** tab, int n, float* vect)
{
    printf("Méthode de Jacobi");
    int nb_it;
    printf("Combien d'itération souhaitez vous? \n");
    scanf("%d", &nb_it);

    float coord[n];     //tableau a remplir de 0
    float COORD[n];  //tableau a remplir de 0
    float epsilon;
    for (int i = 0; i < nb_it - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            for (int k = 0; k < n - 1; k++)
            {

                coord[j] = coord[j] + (tab[j][k] * coord[k]);

            }
            coord[j] = 1 / tab[j][j] * (coord[j] + vect[j]);

        }
    }


    for (int i = 0; i < nb_it - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            for (int k = 0; k < n - 1; k++)
            {

                COORD[j] = COORD[j] + tab[j][k] * coord[j];

            }
            epsilon = epsilon + COORD[j] * COORD[j];
        }


    }
    epsilon = sqrt(epsilon);




    return epsilon, COORD[n];
}

struct val_meth_gauss_seidel
{
    int variable_x;
    int variable_y;
    int autreVariable_z;
};

typedef struct val_meth_gauss_seidel val_seidel;


float* meth_gauss_seidel(float* vect_nul, float* vecteur_s, float** matrice, int n)
{
    printf("Méthode de Gauss-Seidel \n");
    int nb_it;
    printf("Combien d'itération souhaitez vous? \n");
    scanf("%d", &nb_it);

    for (int i = 0; i < nb_it - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vect_nul[j] = vecteur_s[j];
            for (int k = 0; k < n; k++)
            {
                if (k = j)
                {

                }

                else
                {
                    vect_nul[j] = vect_nul[j] + matrice[j][k] * vect_nul[k];
                }
            }
            vect_nul[j] = vect_nul[j] * (1 / matrice[j][j]);
        }
    }
    return vect_nul;

}


int main()
{
    float** A;
    int nb_sys;
    nb_sys = choix_matrice(A, nb_sys);

    float* b;
    creat_vect(b, nb_sys);

    float* gauss;                                               //Création d'un  vecteur pour y déposer les valeurs de la résolution
    creat_vect(gauss, nb_sys);


    float* gauss_seidel;                                        //Création d'un  vecteur pour y déposer les valeurs de la résolution
    creat_vect(gauss_seidel, nb_sys);

    gauss = meth_gauss(A, nb_sys, nb_sys, b);
    affiche_vecteur(gauss, nb_sys);

    float* vect_nul;
    creatab1D(vect_nul, nb_sys);                                //permet de génerer un vecteur nul nécessaire à la résolution de Gauss-seidel à la première itération


    jacobi(A , nb_sys, b);

    gauss_seidel = meth_gauss_seidel(vect_nul, b, A, nb_sys);
    affiche_vecteur(gauss_seidel, nb_sys);
    return 0;
}

/*
    Int Main avant choix de matrices
    Back-Up de secour
    Necessité de retaper matrice à la main

    int nbligne;
    int nbcolonnes;
    int nbcolonnesvect = 1;

    printf("Donnez un nombre de lignes : \n");
    scanf("%d", &nbligne);
    printf("Donnez un nombre de colonnes : \n");
    scanf("%d", &nbcolonnes);

    float** A;
    A = creatab2D(nbligne, nbcolonnes);
    affiche_matrice(A, nbcolonnes, nbligne);
    remplissage_matrice(A, nbcolonnes, nbligne);
    affiche_matrice(A, nbcolonnes, nbligne);
*/