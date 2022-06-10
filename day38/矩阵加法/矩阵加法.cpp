#include <stdio.h>

int main() {
    int m, n, i, j, temp;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d",&temp);
            printf("%d ", temp + arr[i][j]);
        }
        putchar('\n');
    }
    return 0;
}