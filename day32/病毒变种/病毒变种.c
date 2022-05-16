#include <stdio.h>
#include <string.h>
#define N 501

int main() {
    char a[N], tmp;
    int n, i, j, len, k;
    scanf("%d\n", &n);
    for (k = 0; k < n; k++) {
        fgets(a,N,stdin);
        len = strlen(a);
        if (a[len - 1] == '\n') {
            a[--len] = '\0';
        }
        printf("%s ", a);
        for (j = 0; j < len - 1; j++) {
            tmp = a[0];
            strcpy(&a[0], &a[1]);
            a[len - 1] = tmp;
            printf("%s ", a);
        }
        putchar('\n');
    }
    return 0;
}