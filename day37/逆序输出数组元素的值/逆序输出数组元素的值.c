#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d",&n);
    int * arr = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d",arr + i);
    }
    while(--i >= 0) {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}