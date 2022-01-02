#include <stdio.h>
#include <string.h>

struct S1 {
	int a;
	char *ch;
};

struct S2 {
	int a;
	char ch[40];
};

int main(void) {
	struct S1 v11, v12;
	struct S2 v21, v22;

	v11.a = 3;
	// v11.ch = "HULK"; //en lecture seule
	v11.ch = strdup("Hulk");
	// strdup === malloc puis un strcpy
	v21.a = 5;
	strcpy(v21.ch,"Gruik");

	v12 = v11;
	// v12.a = v11.a
	// v12.ch = v11.ch <- pointeur copié mais pas la zone pointée
	v22 = v21;

	printf("v11: %d %s\n", v11.a, v11.ch);
	printf("v12: %d %s\n", v12.a, v12.ch);
	printf("v21: %d %s\n", v21.a, v21.ch);
	printf("v22: %d %s\n", v22.a, v22.ch);

	strcpy(v11.ch,"OOF");
	strcpy(v21.ch,"YAIE");

	printf("v11: %d %s\n",v11.a, v11.ch);
	printf("v12: %d %s\n",v12.a, v12.ch);
	printf("v21: %d %s\n",v21.a, v21.ch);
	printf("v22: %d %s\n",v22.a, v22.ch);
	return(0);
}
