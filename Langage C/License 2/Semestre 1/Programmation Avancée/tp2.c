#include <stdio.h>
#include <stdlib.h>


void copy(FILE* doc1 , FILE* doc2)
{
	char ch	;
	while ((ch = getc(doc1)) != EOF)
	{
		putc(ch, doc2);
	}
	fclose(doc1);
	fclose(doc2);


}

void supression_voyelle(FILE* doc1, FILE* doc2)
{
	char ch;
	fseek(doc1, 0, SEEK_SET);
	while ((ch = getc(doc1)) != EOF)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ||
			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y') 
		{
			printf("\n %c est une voyelle.\n", ch);
		}
		else 
		{
			printf("\n %c est une consonne.\n", ch);
			putc(ch, doc2);
		}
	}
	fclose(doc1);
	fclose(doc2);
}

int main()
{
	FILE* copie = fopen("doc1.txt", "r");
	FILE* colle = fopen("doc2.txt", "w" );
	FILE* sans_voyelle = fopen("doc3.txt", "w+");
	
	if (copie == NULL)
	{
		perror("Problème d'ouverture fichier 1");
		exit(-1);
	}
	if (colle == NULL)
	{
		perror("Problème d'ouverture fichier 2");
		exit(-1);
	}
	if (sans_voyelle == NULL)
	{
		perror("Problème d'ouverture fichier 2");
		exit(-1);
	}

	//copy(copie, colle);
	supression_voyelle(copie, sans_voyelle);

	printf("Fin de programme"); //Section afin d'avoir l'affichage dans l'executable jusqu'à la fin du programme
	int fin_prog;
	scanf("%d", &fin_prog);

	return 0;
}