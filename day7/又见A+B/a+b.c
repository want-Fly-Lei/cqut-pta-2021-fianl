#include<stdio.h>
#include<string.h>
int main(){
    char * str[21] = { "zero","one","two","three","four","five","six","seven",
"eight","nine","ten" ,"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
    int i, j;
    char s1[6], s2[6];
    int temp;
    while(scanf("%s %s",s1,s2) != EOF) {
        for(j = 0; j < 11; j++) {
            if(!strcmp(s1,str[j])) {
                break;
            }
        }
        for(i = 0; i < 11; i++) {
            if(!strcmp(s2,str[i])) {
                break;
            }
        }
        printf("%s\n",str[i + j]);
    }
    return 0;
}