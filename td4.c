#include <stdio.h>
#include <stdlib.h>

#define print printf

struct Cellule{
	int valeur;
	struct Cellule* suivante;
};
struct File {
	struct Cellule* premiere;
	struct Cellule* derniere;
};

void creer_vide(struct File * f) {
	f->premiere=NULL;
	f->derniere=NULL;
}

void ajouter (struct File * f, int i) {
	if (f->premiere==NULL && f->derniere==NULL) {
		f->premiere = malloc(sizeof(struct Cellule));
		f->derniere = malloc(sizeof(struct Cellule));
		f->premiere->valeur=i;
		f->premiere->suivante = NULL;
		f->derniere=f->premiere;
	} else {
		struct Cellule* nouvelle_cell;
		nouvelle_cell = malloc(sizeof(struct Cellule));
		nouvelle_cell->valeur=i;
		nouvelle_cell->suivante=NULL;
		f->derniere->suivante=nouvelle_cell;
		f->derniere=nouvelle_cell;
	}
}

void retirer (struct File* f) {
	if (f->premiere==NULL) {
		print("Je peux pas retirer, la liste est vide\n");
	} else {
		struct Cellule* ancienne_cell = f->premiere;
		f->premiere = f->premiere->suivante;
		free(ancienne_cell);
	}
}

void afficher_premier_element(struct File* f) {
	if (f->premiere==NULL) {
		print("Pas de premier element\n");
	} else {
		print("Le premier element est %d\n",f->premiere->valeur);
	}
}

void afficher_dernier_element(struct File* f) {
	if (f->derniere!=NULL) {
		print("Le dernier element est %d\n",f->derniere->valeur);
	} else {
		print("Pas de dernier element\n");
	}
}

int file_vide(struct File* f) {
	if (f->premiere==NULL) {
		print("File vide\n");
		return(1);
	} else {
		print("File pas vide\n");
		return(0);
	}
}

int nombre_element(struct File* f) {
	int i = 0;
	struct Cellule* cell_tampon = f->premiere;
	while (cell_tampon != NULL) {
		i++;
		cell_tampon = cell_tampon->suivante;
	}
	free(cell_tampon);
	return(i);
}

int main(void) {
	struct File f;
	creer_vide(&f);
	file_vide(&f);
	ajouter (&f,1);
	ajouter (&f,5);
	ajouter (&f,3);
	ajouter (&f,4);
	print("la file contient %d element(s) \n",nombre_element(&f));
	retirer(&f);
	retirer(&f);
	print("la file contient %d element(s) \n",nombre_element(&f));
	file_vide(&f);
	afficher_premier_element(&f);
	afficher_dernier_element(&f);
	return(0);
}
