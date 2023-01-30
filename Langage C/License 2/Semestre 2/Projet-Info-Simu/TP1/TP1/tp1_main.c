#include <stdio.h>
#include <stdlib.h>

/*============== Exercices ==============*/
void exo1(int nb_it)
{
	//Nous cherchons à implementer la technique du carré moyen 
	//exemple
	// 01 - 5227 - 56
	// Nous gardons donc : 5227
	// 
	// 
	//Méthodes :
	//Première idée : diviser par pas 10 000 afin d'obtenir 01,522756
	//Nous rognons ensuite la partie entière 
	//puis les deux derniers chiffres sans arrondir. Il nous reste donc : 5227
	//Cela sera valable dans tous les cas ne gradans que 4 valeurs 
	// et 9999*9999 nous donnes : 99 980 001 sous la forme : 00 1111 00 ou les 1 sont à garder
	//Méthode Proff division par 100 puis module 10 000


	printf("Quelle est votre graine N0?");
	int graine;
	scanf("%d", &graine);

	for (int i = 0; i < nb_it; i++)
	{
		graine = ((graine*graine) / 100) % 10000;
		printf("Valeur : %04d \n", graine);
	}	
}
//exercice 2
// Pas de code pour cause de modifications légère du code de l'exercice 1
//Nous avons tester les différentes graines de l'enoncé, en prenant nottament un nombre élévé d'iterations.
//Dans notre cas : 70 iterations
//Pour 1324, nous observons bien une convergence vers 0 avec les 70 iterations
//pour la valeur 1301 et 70 itérations nous obtenons 8962 à la dernière itération 
//néanmoins avec 120 iteration nous obtenons des multiples de 100 sur les derniers résultats

//Pour réaliser ces test nous avons remplacer quelques lignes du programmes nottament le nombre d'itteration dans le main. 
// exo1(70); ---> exo1(120²);


void exo3()
{

}

void exo4()
{
	int x;
	x = rand() % 2;
}

/*============== Main ==============*/
int main()
{ 
	exo1(70);
}