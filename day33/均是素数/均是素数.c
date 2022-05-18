#include <stdio.h>
#include<stdbool.h>
int m, n, p, q, r;
int a[1000];
int arr[3];
int count, cnt;

bool isPrime(int i) { 
    if (i == 1) {
        return false;
    }
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    scanf("%d%d", &m, &n);
    int i, j, q;
    for (i = m; i <= n; i++) { 
        if (isPrime(i) == 1) {
            a[count] = i;
            ++count;
        }
    }

    for (i = 0; i < count - 2; i++) {
        for (j = i + 1; j < count - 1; j++) {
            for (q = j + 1; q < count; q++) {
                arr[0] = a[i] * a[j] + a[q];
                arr[1] = a[i] * a[q] + a[j];
                arr[2] = a[j] * a[q] + a[i];
                if (isPrime(arr[0]) && isPrime(arr[1]) && isPrime(arr[2])) {
                    ++cnt;
                }
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
