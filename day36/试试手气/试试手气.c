#include <stdio.h>

int main() {
    int a[7] = {0}; 
    int b[7];
    int n;
    register int i, j;
    for (i = 0; i < 6; i++) {
        scanf("%d",&b[i]);
        a[i] = b[i];
    }
    
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            if (i == 0) {
                if (b[j] != 6) {
                    b[j] = 6; 
                } else {
                    --b[j]; 
                }
            } else if (i != 0)  {
                if (b[j] - 1 == a[j])  {
                    b[j] = b[j] - 2; 
                } else {
                    --b[j]; 
                }
            }
        }
    }

    for (i = 0; i < 6; i++) {
        if (i < 5) {
            printf("%d ",b[i]);
        } else {
            printf("%d\n",b[i]);
        }
    }
    return 0;
}
