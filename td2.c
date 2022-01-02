#include <stdio.h>

void Permute(int &a,int &b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int * a;
	int * b;
	*a = 4;
	*b = 6;
	printf("Avant la permutation : a=%d et b=%d",*a,*b);
	Permute(&a , &b);
	printf("Après la permutation : a=%d et b=%d",*a,*b);
	return (0);
}
