#include<stdio.h>

struct complex
{
    float real;
    float imag;
} complex;

struct complex add(struct complex n1, struct complex n2);
void ShowData(struct complex c);

int main(void)
{
    struct complex c1, c2;
    
    scanf("%f %f", &c1.real, &c1.imag);
    scanf("%f %f", &c2.real, &c2.imag);

    ShowData(add(c1, c2));

    return 0;
}

struct complex add(struct complex c1, struct complex c2)
{
    struct complex temp;
    temp.real=c1.real+c2.real;
    temp.imag=c1.imag+c2.imag;
    return temp;
}

void ShowData(struct complex c)
{
    printf("Sum = %f + %fi\n", c.real, c.imag);
}

