#include <stdio.h>
#define MAXSIZE 101
int arr[MAXSIZE];

int main() {
    int m, n;
    scanf("%d %d",&m, &n);
    n %= m;
    register int i;
    for (i = 0; i < m; i++) {
        scanf("%d",&arr[i]);
    }
    if (n == 0) {
        --m;
        for (i = 0; i < m; i++) {
            printf("%d ",arr[i]);
        }
        printf("%d",arr[i]);
    } else {
        for (i = n; i < m; i++) {
            printf("%d ",arr[i]);
        }
        --n;
        for (i = 0; i < n; i++) {
            printf("%d ",arr[i]);
        }
        printf("%d",arr[i]);
    }

    
    return 0;
}