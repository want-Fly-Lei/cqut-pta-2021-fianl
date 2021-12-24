#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#include<stdlib.h>
#define SIZE 128
//注意如果是10000不行，必须要10^4 + 1才行不然有两个测试过不去
#define MAX 10001
int main(){
    //还有估计是bug把，malloc出来的第二个输入莫名多了一个空格，就很奇怪，bug把
    // char *cha = (char *)malloc(sizeof(char) * MAX);
    // char *chb = (char *)malloc(sizeof(char) * MAX);
    char cha[MAX],chb[MAX];
    gets(cha);
    gets(chb);
    int judge[SIZE];
    memset(judge,0,SIZE);
    int i,len;
    len = strlen(chb);
    for(i = 0; i < len;i++) {
        judge[chb[i]] = 1;
    }
    len = strlen(cha);
    for(i = 0; i < len; i++) {
        if(judge[cha[i]] == 0) {
            printf("%c",cha[i]);
        }
    }
    // free(cha);
    // free(chb);
    return 0;
}