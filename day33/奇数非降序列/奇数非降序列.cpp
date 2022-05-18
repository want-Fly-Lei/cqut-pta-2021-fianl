#include <cstdio>
#include<algorithm>
using namespace std;

int main() {
    int n, i, temp, len = 0;
    scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d",&temp);
        if (temp % 2 == 1) {
            arr[len++] = temp;
        }
    }

    sort(arr,arr + len);
    for (i = 0; i < len - 1; i++) {
        printf("%d,",arr[i]);
    }
    printf("%d",arr[i]);
    return 0;
}