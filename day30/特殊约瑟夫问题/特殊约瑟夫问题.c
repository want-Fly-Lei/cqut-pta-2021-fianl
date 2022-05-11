#include<stdio.h>
int arr[1001];
int main() {
    int n, m, k;
    register int i, temp;
    scanf("%d %d %d", &n, &m, &k);
 
    int flag = -1;  
 
    for (i = 0; i <= n; i++) {
        arr[i] = 1;
    }
    
    arr[0] = n;
 
    for (; arr[0];flag *= -1) {
        if (flag == -1) {
            temp = m - 1;
        } else {
            temp = k - 1;
        }

        while (temp) {
            i += flag;
            if (i < 1) {
                i = n;  
            } else if (i > n) {
                i = 1;
            }
 
            temp -= arr[i];
        }
        printf("%d ", i);
        arr[0]--;
        arr[i] = 0;
    }
    return 0;
}