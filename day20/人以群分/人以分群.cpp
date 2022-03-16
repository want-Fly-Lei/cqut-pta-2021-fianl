#include<cstdio>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
int arr[MAXSIZE];
int main() {
    int n, i, sum = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr + n);
    for(i = 0; i < n / 2; i++) {
        sum -= arr[i];
    }
    while(i < n) {
        sum += arr[i++];
    }
    printf("Outgoing #: %d\n", n/2+n%2);
	printf("Introverted #: %d\n", n/2);
	printf("Diff = %d\n", sum);
    return 0;
}