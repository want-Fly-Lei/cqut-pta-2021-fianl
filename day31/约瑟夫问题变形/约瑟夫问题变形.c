#include <stdio.h>
#define MAXSIZE 10001

char arr[MAXSIZE];

int main() {
    int n, m;
    register int i, j;
    scanf("%d %d",&n, &m);
    for (i = 1; i <= n; i++) {
        arr[i] = 1;
    }
    int count1 = 0, count2 = 0;
    i = 1;
    while (count1 < n) {
        if (arr[i] != 0) {
            ++count2;
        }
        if (count2 == count1 + m) {
            ++count1;
            arr[i] = 0;
            count2 = 0;
            printf("%d ",i);
        }
        if (i == n) {
            i = 1;
        } else {
            ++i;
        }
    }
    return 0;
}