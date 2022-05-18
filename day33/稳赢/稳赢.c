#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * ch[3] = {"ChuiZi\n", "Bu\n", "JianDao\n"};
const int len = 3;
char temp[10];

int main(){
    int i, j, k;
    scanf("%d",&k);
    ++k;
    for(i = 0; 1 ; i++) {
        fgets(temp,10,stdin);
        if(strcmp(temp,"End\n") == 0) {
            break;
        } else {
            for(j = 0; j < len; j++) {
                if(strcmp(ch[j],temp) == 0) {
                    if(i != 0 && i % k == 0) {
                        fputs(temp,stdout);
                    } else {
                        fputs(ch[(j + 1) % len],stdout);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}