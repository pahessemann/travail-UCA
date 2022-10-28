#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// #include "HESSEMANN_TP1_Prog_Avancée.h"

/*
typedef struct Element Element ;
struct Element
{
    Element* next ; //Element suivant
    Element* prev ; // Element precédent
    int val ; // valeur stockée
};



typedef struct Liste Liste ;
struct Liste
{
    int nb_elements ; //longueur
    Element* head ; //tête
    Element* tail ; // queue
} ;


Liste vide()
{
    Liste l;
    l.head = NULL;
    l.tail = NULL;
    l.nb_elements = 0;
    return l;
};

int longueur_liste(Liste l)    
{                              
    return l.nb_elements;      
}

int longueur2(Liste 1)
{
    int n=0;
    for(Element* p=l.head ; p!=NULL ; p=p->next)
    {
        n++;
    }
    return 0; 
}
*/






float** creatab2D(int ligne, int colonne)
{
    float** Tableau = NULL;

    Tableau = malloc(sizeof(float*) * ligne);

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

void remplissage_tab(float** tab, int nbc, int nbl)
{
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            printf("Donnez la valeur de la case %d, %d \n", i, j);
            scanf("%f", &tab[i][j]);
        }

    }
}

void AfficheTab(float** tab, int nbc, int nbl)
{
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            printf("%f \t", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

float** rota_tab (float** tab,  int nbc, int nbl)
{
    float** tab2;
    tab2 = creatab2D(nbc, nbl);
    for (int i = 0 ; i< nbc ; i++ )
    {
        for (int j=0 ; j<nbl ; j++ )
        {
            tab2[i][j] = tab[nbl-1-j][i];
        }
    }
    return tab2;
}

float** triangle_pascal (int n)
{
    float** tab;
    tab = creatab2D(n , n);
    tab [0][0]=1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i==j || j==0)
                {
                    tab[i][j] = 1;
                }
           
                else
                {
                    tab[i][j] = tab[i-1][j-1]+tab[i-1][j];
                }
                
        }
        printf("\n");
    }
    return tab;
}


int main ()
 {
    int nbligne;
    int nbcolonnes;
    
    printf("Donnez un nombre de lignes : \n");
    scanf("%d", &nbligne);
    printf("Donnez un nombre de colonnes : \n");
    scanf("%d", &nbcolonnes);
    
    

    float** A;
    float** B;
    float** pascal;

    
    A = creatab2D(nbligne, nbcolonnes);
    AfficheTab(A, nbcolonnes, nbligne);
    remplissage_tab(A, nbcolonnes, nbligne);
    AfficheTab(A, nbcolonnes, nbligne);
    
    B = rota_tab (A, nbcolonnes , nbligne);
    AfficheTab(B, nbligne, nbcolonnes);
    
    
    
    printf("Combien de lignes du triange de pascal voulez vous? \n");
    int n = 0;
    scanf("%d", &n);
    pascal=triangle_pascal(n);
    AfficheTab(pascal, n, n);
    return 0;
 }