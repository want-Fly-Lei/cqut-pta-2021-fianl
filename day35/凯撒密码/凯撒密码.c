#include <stdio.h>
#include <string.h>
#define MAXSIZE 51

int main() {
    int n, i;
    scanf("%d\n",&n);
    char chs[MAXSIZE];
    fgets(chs,MAXSIZE,stdin);
    int len = strlen(chs);
    if (chs[len - 1] == '\n') {
        chs[--len] = '\0';
    }
    n %= 26;
    register char temp;
    for (i = 0; i < len; i++) {
        temp = chs[i] + n;
        if (temp > 'z') {
            temp -= 26;
        }
        putchar(temp);
    }
    return 0;
}