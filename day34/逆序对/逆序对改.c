#include <stdio.h>

long long n;                    
#define maxn 1000005 
long long a[maxn], r[maxn];     
long long ans = 0;

void msort(int s, int t) { 
    if (s == t) {
        return;
    }
        
    int mid = (s + t) >> 1;           
    msort(s, mid), msort(mid + 1, t); 
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) {
        if (a[i] <= a[j]) {
            r[k++] = a[i++];
        } else {
            r[k++] = a[j++];
            ans += mid - i + 1; 
        }
    }

    while (i <= mid) {
        r[k++] = a[i++];
    }
        
    while (j <= t) {
         r[k++] = a[j++];
    }
       
    for (i = s; i <= t; i++) {
        a[i] = r[i];
    }
        
    return;
}

int main() {
    scanf("%lld", &n);
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    msort(0, n - 1);
    printf("%lld", ans);
}