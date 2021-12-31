#include <stdio.h>
#define MAXN 100

int main(void) {
    int n, m, num[MAXN * 2], i, temp;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    m %= n;
    for (i = n + m - 1; i > m - 1; i--) {
        num[i] = num[i - m];
    }
    for (i = 0; i <= m - 1; i++) {
        num[i] = num[n + i];
    }
    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", num[i]);
        }
        else {
            printf(" %d", num[i]);
        }
    }
    printf("\n");

    return 0;
}
