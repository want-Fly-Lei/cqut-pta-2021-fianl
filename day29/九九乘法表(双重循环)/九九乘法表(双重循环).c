#include<stdio.h>

int main() {
    int n, i, j;
    scanf("%d",&n);
    if (n < 1 || n > 9) {
        puts("INPUT ERROR.");
    } else {
        for (i = 1; i <= n; i++) {
            for (j = 1; j < i; j++) {
                printf("%dX%d=%d\t",i, j, i * j);
            }
            printf("%dX%d=%d\n",i, j, i * j);
        }
    }
    return 0;
}