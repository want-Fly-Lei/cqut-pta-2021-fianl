#include <stdio.h>

int main() {
    int n, m, temp;
    register int i, j, res;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&m);
        res = 0;
        for (j = 0; j < m; j++) {
            scanf("%d",&temp);
            res += temp;
        }
        printf("%d\n",res);
    }
    return 0;
}