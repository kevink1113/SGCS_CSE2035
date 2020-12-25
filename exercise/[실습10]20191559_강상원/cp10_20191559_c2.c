#include <stdio.h>
#include <stdlib.h>
int main() {
    int res, len, inlen, cnt=0, j;
    char arr[1001], sch[101];
    printf("Text : ");
    fgets(arr, sizeof(arr), stdin);
    printf("Word : ");
    scanf("%s", sch);
    for(int i=0; i<1001; i++){
        if (arr[i]=='\0'){
            len=i;
            break;
        }
    }
    for(int i=0; i<101; i++){
        if(sch[i]=='\0'){
            inlen=i;
            break;
        }
    }
    for(int i=1; i<len-inlen; i++){
        res=1;
        if (arr[i-1]==' ' && arr[i+inlen]==' '){
            for(j=i; j<i+inlen; j++){
                if (arr[j]==sch[j-i]) res *= 1;
                else res *= 0;
            }
            if (res==1) cnt++;
        }
    }
    
    res=1;
    for(int i=0; i<inlen; i++){
        if (arr[i]==sch[i]) res *= 1;
        else res *= 0;
    }
    if (res==1) cnt++;
    
    res=1;
    for(int i=len-inlen-1; i<len-1; i++){
        if (arr[i]==sch[i]) res *= 1;
        else res *= 0;
    }
    if (res==1 && len-1!=inlen) cnt++;
    
    printf("Number of '%s' : %d\n", sch, cnt);
    return 0;
}

