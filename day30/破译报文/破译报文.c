#include <stdio.h>
#include <string.h>
#define MAXSIZE 10001

int main() {
    char str[MAXSIZE];
    fgets(str,MAXSIZE,stdin);
    int len = strlen(str) - 1;
    int i, j , k;
    int maxLen = 1;
    //减去maxlen是为了减少那些不必要的遍历
    for (i = 0; i < len - 1 - maxLen; i++) {
        for (j = i + 1; j < len - maxLen; j++) {
            k = 0;
            while(str[i + k] == str[j + k]) {
                ++k;
            }
            if (k > maxLen) {
                maxLen = k;
            }
        }
    }
    printf("%d",maxLen);
    return 0;
}