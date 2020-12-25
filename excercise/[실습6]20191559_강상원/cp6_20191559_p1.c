#include <stdio.h>
int main(void){
        int i, num, l=0, m=0, r=1;
        scanf("%d", &num);

        for(i=0; i <=num; i++){
                printf("%d ", l);
                m=l+r;
                l=r;
                r=m;
        }
        printf("\n");

        return 0;
}
