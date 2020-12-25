#include <stdio.h>
#include <stdlib.h> 
void lcs(const char * const sa, const char * const sb, char ** const beg, char ** const end) {
 	int apos, bpos, len;
    *beg = 0;
    *end = 0;
    len = 0;
 
    for (apos = 0; *(sa+apos) != 0; ++apos) {
        for (bpos = 0; *(sb+bpos) != 0; ++bpos) {
            if (*(sa+apos) == *(sb+bpos)) {
                len = 1;
                while (*(sa+apos+len) != 0 && *(sb+bpos+len) != 0 && *(sa+apos+len) == *(sb+bpos+len)) 
                    len++;
            }
 
            if (len > *end - *beg) {
                *beg = sa + apos;
                *end = *beg + len;
                len = 0;
            }
        }
    }

}
 
int main() {
	char* s1=(char*)malloc(1000*sizeof(char));
	char* s2=(char*)malloc(1000*sizeof(char));
	int al, bl;
	scanf("%d %d", &al, &bl);
	scanf("%s", s1);
	scanf("%s", s2);
    char *beg, *end, *it;
 
    lcs(s1, s2, &beg, &end);
 	printf("Longest Common Substring = ");
    for (it = beg; it != end; it++)
        putchar(*it);
    printf("\n");
	free(s1); free(s2);

    return 0;
}
