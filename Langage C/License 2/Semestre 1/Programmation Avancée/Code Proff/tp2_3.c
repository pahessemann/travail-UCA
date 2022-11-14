#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp1_3.h"

Liste vide() {
	Liste l;
	l.head_ = NULL;
	l.tail_ = NULL;
	l.nb_elements_ = 0;
	return l;
}

Liste ajout_fin(int v, Liste l) {
	Element* fin = malloc(sizeof(Element));
	fin->prev_ = l.tail_;
	fin->next_ = NULL;
	fin->val_ = v;
	if (l.tail_) l.tail_->next_ = fin;
	else l.head_ = fin;
	l.tail_ = fin;
	l.nb_elements_++;
	return l;
}

void ecrit_flux(FILE* f, Liste l) {
	fprintf(f, "list: [%i]", l.nb_elements_);
	for(Element* p=l.head_; p!=NULL; p=p->next_) {
		if (p != l.head_)
			fprintf(f, ",");
		fprintf(f, " %i", p->val_);
	}
	fprintf(f, "\n");
}

Liste lit_flux(FILE* f) {
	Liste l = vide();
	int n, r = fscanf(f, "list: [%i]", &n);
	for(int i=0; i<n; i++) {
		int v, r = fscanf(f, " %i,", &v);
		l = ajout_fin(v, l);
	}
	return l;
}

int main() {
 	Liste l1 = lit_flux(stdin);
	ecrit_flux(stdout, l1);
}
