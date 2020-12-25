#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int max, val, carry;
    int i, ml, nl;
	char *mbuf=(char *)malloc(100*sizeof(char));
	char *nbuf=(char *)malloc(100*sizeof(char));
	int *m=(int *)malloc(100*sizeof(int));
	int *n=(int *)malloc(100*sizeof(int));
	int *s=(int *)malloc(100*sizeof(int));

	for (int i=0; i<100; i++){
		m[i]=0;
		n[i]=0;
		s[i]=0;
	}

	int p, q;
    scanf("%d %d", &p, &q);
    scanf("%s",mbuf);
    scanf("%s",nbuf);
 
    ml=strlen(mbuf);
    nl=strlen(nbuf);
    for(i=0;i<ml;i+=1)
        m[ml-i-1]=mbuf[i]-'0';

    for(i=0;i<nl;i+=1)
        n[nl-i-1]=nbuf[i]-'0';
    max=ml;

    if(nl>ml) max=nl;
    carry=0;

    for(i=0;i<max;i+=1) {
        val=m[i]+n[i]+carry;
        carry=val/10;
        s[i]=val%10;
    }

    if(carry>0) {
        s[max]=carry;
        max+=1;
    }

    for(i=0;i<max;i+=1)
        printf("%d",s[max-i-1]);
	printf("\n");
	free(mbuf); free(nbuf); free(m); free(n); free(s);

    return 0;
}

