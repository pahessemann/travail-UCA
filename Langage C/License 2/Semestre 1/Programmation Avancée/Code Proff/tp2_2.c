#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {
  if (argc!=3) {
    fprintf(stderr, "\nFormat : %s <nom> <k>\n\n", argv[0]);
    return EXIT_FAILURE;
  }

	char k = atoi(argv[2]);
	FILE* f = fopen(argv[1],"r+");
	
	if (f == NULL) {
		fprintf(stderr, "Le fichier n'a pas pu être ouvert\n");
    return EXIT_FAILURE;
	}
	
	int ch;
	while((ch = fgetc(f)) != EOF) {
		fseek(f, -1, SEEK_CUR);
		fputc(ch+k, f);
	}
	
	fclose(f);
}
