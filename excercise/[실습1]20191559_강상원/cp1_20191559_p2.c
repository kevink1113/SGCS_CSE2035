#include <stdio.h>
void swap(int* a, int* b)
{
    int ptr;
    ptr=(*a); (*a)=(*b); (*b)=ptr;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}

