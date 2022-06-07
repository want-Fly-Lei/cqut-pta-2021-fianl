#include <stdio.h>
#include <malloc.h>

int main() {
    int n, i, k;
    scanf("%d",&n);
    int * arr = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d",arr + i);
    }

    for (i = 0; i < n; i++) {
        for (k = i; k < n; k++) {
            printf("%d ",arr[k]);
        }
        for (k = 0; k < i; k++) {
            printf("%d ",arr[k]);
        }
        putchar('\n');
    }

    free(arr);
    return 0;
}