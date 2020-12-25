#include<stdio.h>
#include <string.h>
int main(){
    char arr[1001];
    char fn[1001];
    int i, len, beforelen;
    printf("Path : ");
    scanf("%s", arr);
    
    len=strlen(arr);
    for(i=len; i>=0; i--){
        if(arr[i]=='/')
            break;
    }
    beforelen=i;
    
    printf("File name : ");
    scanf("%s", fn);
    
    strcpy(arr+beforelen+1, fn);
    
    printf("New path : %s\n", arr);
    
    return 0;
}
