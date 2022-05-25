#include <stdio.h>
#define MAXSIZE 100024
int arr1[MAXSIZE], arr2[MAXSIZE];
int i, j;

int main() {
    int n1, n2;
    scanf("%d",&n1);

    for (i = 0; i < n1; i++) {
        scanf("%d",&arr1[i]);
    }

    scanf("%d",&n2);
    for (i = 0; i < n2; i++) {
        scanf("%d",&arr2[i]);
    }

    int len = n1 + n2;
    int index1 = 0, index2 = 0;
    for (i = 0; i < len; i++) {
        if (index1 >= n1) {
            printf("%d ",arr2[index2++]);
        }else if (index2 >= n2) {
            printf("%d ",arr1[index1++]);
        } else {
            if (arr1[index1] > arr2[index2]) {
                printf("%d ",arr2[index2++]);
            } else {
                printf("%d ",arr1[index1++]);
            }
        }
    }
    return 0;
}