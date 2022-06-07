#include <stdio.h>
#include <malloc.h>

int main() {
    int n, m;
    scanf("%d %d",&n, &m);
    n *= m;
    int *arr1 = (int *)calloc(n, sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    for (m = 0; m < n; m++) {
        scanf("%d", arr1 + m);
    }

    for (m = 0; m < n; m++) {
        scanf("%d",arr2 + m);
    }

    for (m = 0; m < n; m++) {
        if(arr1[m] != arr2[m]) {
            puts("No");
            m = 0;
            break;
        }
    }
    if (m != 0) {
        puts("Yes");
    }
    free(arr1);
    free(arr2);
    return 0;
}