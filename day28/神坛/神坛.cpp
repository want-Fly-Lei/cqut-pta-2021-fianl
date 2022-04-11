#include <stdio.h>
#include<algorithm>
using namespace std;
#define N 5005
#define ll long long

struct T{
    ll x, y;
} p[N], c[N];

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lld %lld",&p[i].x, &p[i].y);
    }
        
    ll ans = 1e18;
    for (i = 0; i < n; i++){
        k = 0;
        for (j = 0; j < n; j++) {
            if (i != j) {
                c[k].x = p[j].x - p[i].x, c[k++].y = p[j].y - p[i].y;
            }   
        }
            
        sort(c, c + k,
             [](T a, T b)
             {
                 return b.y * a.x > b.x * a.y;
             });
        for (j = 1; j < k; j++) {
            ans = min(ans, abs(c[j].y * c[j - 1].x - c[j].x * c[j - 1].y));
        }
            
    }
    printf("%.3f\n", ans / 2.0);
    return 0;
}