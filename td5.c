#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EcritFichier(FILE * fich_lect, char * nom_fich_ecrit, int nb_lignes) {
	FILE *fich_ecr = fopen(nom_fich_ecrit,"w");
	int i;
	char s[1024];
	char *ret;
	int code_retour = 0;
	if (fich_ecr == NULL) {
		code_retour = 2;
	}
	for (i=0;code_retour == 0 && i<nb_lignes;i++) {
		ret = fgets(s, sizeof(s), fich_lect);
		if (ret == NULL) {
			code_retour = 1;
		} else {
			fputs(s, fich_ecr);
		}
	}
	fclose(fich_ecr);
	return(code_retour);
}

int main(int argc, char *argv[]) {
	if (argc == 4) {
		char *nom_fich_lect = argv[1];
		char *nom_fich_ecr = argv[2];
		int nb_lignes = atoi(argv[3]);
		FILE *fich_lect = fopen(nom_fich_lect,"r");
		if (fich_lect == NULL) {
			return 1;
		}
		int ret = EcritFichier(fich_lect, nom_fich_ecr, nb_lignes);
		printf("Code retour : %d\n",ret);
		fclose(fich_lect);
		return 0;
	} else {
		fprintf(stderr,"usage : %s nom_fich_lect nom_fich_ecr nb_lignes\n", argv[0]);
		return 2;
	}
}
