#include <stdio.h>
#include <ctype.h>


int main() {
    int flag, i;
    int arr[200];
    int len = 0;
    char str[101];
    while(scanf("%s",str) != EOF) {
        if(isdigit(str[0])) {
            if(sscanf(str,"%d",&arr[len]) == 1) {
                ++len;
            }
        }
    }

    flag = 1;
    for (i = 0; i < len - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        puts("True");
    } else {
        puts("False");
    }
    return 0;
}