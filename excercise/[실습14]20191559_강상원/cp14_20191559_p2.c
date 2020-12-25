#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float coef;
    int expon;
} poly;

poly *poly_sum(int n, int m, poly *a, poly *b);

int main(){
    int n, m;
    int i, j;
    scanf("%d%d", &n, &m);
    poly *a, *b;
    a=(poly*)malloc(n*sizeof(poly));
    b=(poly*)malloc(m*sizeof(poly));
    
    for(i=0; i<n; i++)
        scanf("%f%d", &a[i].coef, &a[i].expon);
        
    for(i=0; i<m; i++)
        scanf("%f%d", &b[i].coef, &b[i].expon);
    
    //a[n].coef= 0;
    //b[n].coef= 0;
    a[n].expon= 2000000000;
    b[m].expon= 2000000000;
    
    poly_sum(n, m, a, b);
	
	free(a); free(b);

    return 0;
}

poly *poly_sum(int n, int m, poly *a, poly *b){
    poly* c=(poly*)malloc((n+m)*sizeof(poly));
    int max=0;
   	if (a[n-1].expon>b[m-1].expon) max=a[n-1].expon;
	else max=b[m-1].expon;
    
    int idx1=0, idx2=0;
    for(int i=0; i<n+m; i++){
        c[i].coef=0;
        if (a[idx1].expon<b[idx2].expon){
            c[i].expon=a[idx1].expon;
            c[i].coef+=a[idx1].coef;
            idx1++;
            //printf("idx1\n");
        }
        else if (a[idx1].expon>b[idx2].expon){
            c[i].expon=b[idx2].expon;
            c[i].coef+=b[idx2].coef;
            idx2++;
            //printf("idx2\n");
        }
        else if (a[idx1].expon==b[idx2].expon){
            c[i].expon=a[idx1].expon;
            c[i].coef+=(a[idx1].coef+b[idx2].coef);
            //i++;
            //printf("같다!!!\n");
            idx1++; idx2++;
        }
    }
    for (int i=0; i<n+m; i++){
        if (c[i].coef!=0 && c[i].expon!=max/* && c[i].expon!=0*/)
            printf("%.2fx^%d+", c[i].coef, c[i].expon);
        if (c[i].expon==max){
            printf("%.2fx^%d\n", c[i].coef, c[i].expon);
            return 0;
        }
    }
    printf("\n");

	free(c);
	
    return 0;
}
