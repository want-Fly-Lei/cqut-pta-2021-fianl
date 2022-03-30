#include <bits/stdc++.h>
using namespace std;
int n, m[105], nw = 0, Max, pre = -1;
int tbl[105][11][11];

int main(){
    scanf("%d", &n);
    int i, j ,k;
    for (i = 1; i <= n; ++i){
        scanf("%d", &m[i]);
        if (m[i] >= Max) {
            Max = m[i];
        } 
    }

    for (i = 1; i <= Max; ++i) {
        for (j = 1; j <= 10; ++j) {
            for (k = 1; k <= n; ++k){
                if (m[k] >= i){
                    if (pre == k) {
                        nw += 2;
                    } else {
                        ++nw;
                    }
                    tbl[k][i][j] = nw;
                    pre = k;
                }
            }
        }
    }

    for (i = 1; i <= n; ++i){
        printf("#%d\n", i);
        for (j = 1; j <= m[i]; ++j){
            for (k = 1; k <= 10; ++k)
                if (k == 1) {
                    printf("%d", tbl[i][j][k]);
                } else {
                    printf(" %d", tbl[i][j][k]);
                } 
            printf("\n");
        }
    }
    return 0;
}