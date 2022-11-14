#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* fibo(int n) {
	int* t = (int*) malloc(n * sizeof(int));
	if (t!=NULL) {
		t[0] = t[1] = 1;
		for(int i=2; i<n; i++)
			t[i] = t[i-1] + t[i-2];
	}
	return t;
}

bool est_permut(int t[], int n) {
	int effectif[n];
	for(int i=0; i<n; i++)
		effectif[i] = 0;
	for(int i=0; i<n; i++)
		if (t[i]>=0 && t[i]<n) effectif[ t[i] ]++;
	for(int i=0; i<n; i++)
		if (effectif[i] != 1) return false;
	return true;
}

int** pascal(int n) {
	int** t = (int**) malloc(n * sizeof(int*));
	if (t == NULL) return NULL;
	for(int i=0; i<n; i++) {
		t[i] = (int*) malloc(n * sizeof(int));
		if (t[i] == NULL) return NULL;
		t[i][0] = t[i][i] = 1;
		for(int j=1; j<i; j++)
			t[i][j] = t[i-1][j-1] + t[i-1][j];
	}
	return t;
}

int main() {
	int** t = pascal(4);
}
