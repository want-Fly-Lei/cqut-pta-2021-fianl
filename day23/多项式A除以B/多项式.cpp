#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int b[N], i, j;
double a[N], c[N], d[N];

int main(){
    int n, m, f1, n1 = 0, n2 = 0, x, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &x);
        scanf("%lf", &a[x]);
        if (!i) {
            f1 = x;
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d %lf", &b[i], &d[i]);
    }
        
    for (i = f1; i >= b[0]; i--){
        t = i - b[0];
        c[t] = a[i] / d[0];
        for (j = 0; m > j; j++) {
            a[t + b[j]] = a[t + b[j]] - c[t] * d[j];
        }
            
    }

    for (i = f1; i >= 0; i--){
        if (fabs(a[i]) >= 0.05) {
            n2++;
        }
        if (fabs(c[i]) >= 0.05) {
            n1++;
        }   
    }

    printf("%d", n1);
    for (i = f1; i >= 0; i--) {
        if (fabs(c[i]) >= 0.05) {
            printf(" %d %.1f", i, c[i]);
        }
    }
    
    if (n1 == 0) {
        printf(" 0 0.0");
    }
        
    printf("\n");
    printf("%d", n2);
    for (i = f1; i >= 0; i--) {
        if (fabs(a[i]) >= 0.05) {
            printf(" %d %.1f", i, a[i]);
        }
    }
        
    if (n2 == 0) {
        printf(" 0 0.0");
    }
    return 0;
}
