#include<stdio.h>
#include<string.h>
#define size 1001
int isOk(char * s, int start, int end) {
    int i,j;
    for(i = start,j = end; i < j; i++,j--) {
        if(s[i] != s[j]) {
            return 0;
        }
    }
    return end - start;
}
int main(){
    char str[size];
    gets(str);
    int i,j,k = 0,temp;
    int len = strlen(str);
    for(i = 0; i < len - 1; i++) {
        for(j = i + 1; j < len; j++) {
            temp = isOk(str,i,j);
            if(temp > k) {
                k = temp;
            }
        }
    }
    printf("%d",k+1);
    return 0;
}