#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float real;
	float imag;
} complex;

complex *multiple(complex *a, complex *b);

int main(){
	complex a1, b1;

	complex* a=&a1;
	complex* b=&b1;

	scanf("%f%f%f%f", &a1.real, &a1.imag, &b1.real, &b1.imag);

	complex* res;
	res=multiple(a,b);

	printf("%.2f + (%.2f)i\n", res->real, res->imag);

	return 0;
}

complex *multiple(complex *a, complex *b){
	complex result;
	complex *res=&result;
	result.real= (a->real*b->real)-(a->imag*b->imag);
	result.imag= (a->real*b->imag)+(a->imag*b->real);
    return res;
}
