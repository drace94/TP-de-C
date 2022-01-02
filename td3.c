#include <stdio.h>

#define MAXNOTES 8

struct fiche {
	char nom[16];
	int annee;
	int notes[MAXNOTES];
	int nb;
};

void SaisirFiche(struct fiche *etud) {
	scanf("%s",etud->nom); // etud->nom pareil que (*etud).nom
	scanf("%d", &etud->annee);
	scanf("%d", &etud->nb);
	// Verifier nb >= 0 et <= MAXNOTES
	for (int i = 0; i < etud->nb;i++) {
		scanf("%d",&etud->notes[i]);
	}
}

void AfficherFiche(struct fiche etud) { //préférable d'utiliser d'utiliser un pointeur
	printf("nom : %s (%d)\n", etud.nom, etud.annee);
	for (int i = 0;i< etud.nb;i++) {
		printf("%d : %d\n",i,etud.notes[i]);
	}
}

float moyenne(struct fiche etud) {
	int i;
	float cumul;
	for (i = 0;i<etud.nb;i++) {
		cumul += (float)(etud.notes[i]);
	}
	if etud.nb > 0 {
		return cumul/((float)etud.nb);
	}
	else {
		return(0);
		printf("Aucune note");
	};
}

int main() {
	struct fiche f;
	SaisirFiche(&f);
	AfficherFiche(f);
	printf("Moyenne : %f\n",moyenne(f));
	return(0);
}
