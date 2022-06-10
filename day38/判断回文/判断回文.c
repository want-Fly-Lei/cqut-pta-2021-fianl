#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 10001

int main() {
    char arr[MAXSIZE];
    fgets(arr,MAXSIZE,stdin);
    register int len = strlen(arr) - 1;
    register int i = 0;
    bool  flag = true;
    while (i < len) {
        if (arr[i++] != arr[len--]) {
            flag = false;
            break;
        }
    }
    fputs(arr,stdout);
    if (flag) {
        fputs("是回文。",stdout);
    } else {
        fputs("不是回文。",stdout);
    }
    return 0;
}