#include<stdio.h>
#include <ctype.h>
#include <string.h>
#define maxsize 101

int main() {
    char chs[101];
    fgets(chs,maxsize,stdin);
    int len = strlen(chs);
    int i;
    for (i = 0; i < len; i++) {
        if (isdigit(chs[i])) {
            putchar(chs[i]);
        }
    }
    return 0;
}