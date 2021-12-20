#include<stdio.h>
#include<string.h>
int main(){
int n,i;
scanf("%d\n",&n);
char ch1[80] = "\0";
char ch2[80];
int len1 = 0;
int len2;
for(i = 0; i < n; i++) {
    gets(ch2);
    len2 = strlen(ch2);
    if(len2 > len1) {
        len1 = len2;
        strcpy(ch1,ch2);
    }
}
//傻逼is：后面有一个空格，真foolish
printf("The longest is: %s",ch1);
return 0;
}
