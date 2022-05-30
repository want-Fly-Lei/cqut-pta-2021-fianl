#include <stdio.h>

int a[105][105], b[105][105];
int main(){
    int n, k, x, i, j, t;
    int c = 1, sum = 0;
    scanf("%d %d %d",&n, &k, &x);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d",&a[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j % 2 == 0) {
                c = j / 2;
                c = c % k;
                if (c == 0) {
                    c = k;
                }  
                if (c <= k && i + c <= n) {
                    b[i + c][j] = a[i][j];
                }
                for (t = 1; t <= c; t++) {
                    b[t][j] = x;
                }
            } else {
                b[i][j] = a[i][j];
            }
        }
    }

    int f = 0;
    for (i = 1; i <= n; i++) {
        sum = 0;
        for (j = 1; j <= n; j++) {
            sum += b[i][j];
        }

        if (f == 0) {
            printf("%d",sum);
            f = 1;
        } else {
            printf(" %d",sum);
        }
    }
    return 0;
}