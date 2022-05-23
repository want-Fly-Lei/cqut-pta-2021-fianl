#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE 100001

int main() {
    char str[MAXSIZE];
    fgets(str,MAXSIZE,stdin);
    int len = strlen(str);
    //str[len--] = '\0';
    //puts(str);
    register int i, j;
    bool flag = false;
    while(len % 2 == 0) {
        for(i = 0, j = len - 1; i < j; i++, j--) {
            if (str[i] != str[j]) {
                flag = true;
                //printf("%d == %d\n",i, j);
                break;
            }
        }
        if (flag) {
            break;
        }
        len /= 2;
    }
    printf("%d", len);
    return 0;
}