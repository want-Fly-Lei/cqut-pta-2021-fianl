#include "bits/stdc++.h"
#define PII pair<int, int>
#define rep(i, z, n) for (int i = z; i <= n; i++)
#define per(i, n, z) for (int i = n; i >= z; i--)
#define ll long long
#define db double
#define vi vector<int>
#define debug(x) cerr << "!!!" << x << endl;
using namespace std;

inline ll read(){
    ll s, r;
    r = 1;
    s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') {
            r = -1;
        }  
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9'){
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
    }
    return s * r;
}

inline void write(ll x){
    if (x < 0) {
        putchar('-'), x = -x;
    }    
    if (x > 9) {
        write(x / 10);
    }
        
    putchar(x % 10 + '0');
}

const int inf = 1e9 + 10;

struct node{
    int u;
    int v;
    int w;
} e[111111];

int a[1100], n, m;
int cnt;

bool cmp(node a, node b){
    return a.w < b.w;
}

int find(int u){
    return u == a[u] ? u : a[u] = find(a[u]);
}

int main(){
    n = read();
    m = read();
    int i;
    for (i = 1; i <= n; i++) {
        a[i] = i;
    }
        
    for (i = 1; i <= m; i++){
        int u, v, w;
        u = read();
        v = read();
        w = read();
        e[cnt].u = u;
        e[cnt].v = v;
        e[cnt].w = w;
        cnt++;
        e[cnt].u = v;
        e[cnt].v = u;
        e[cnt].w = w;
        cnt++;
    }

    sort(e, e + cnt, cmp);
    int cnt1 = 0;
    int ans = 0;
    for (i = 1; i <= cnt; i++){
        int sx = e[i].u;
        int sy = e[i].v;
        if (find(sx) != find(sy)){
            a[find(sx)] = find(sy);
            cnt1++;
            ans += e[i].w;
        }

        if (cnt1 == n - 1) {
            break;
        }    
    }

    if (cnt1 < n - 1) {
        printf("-1\n");
    } else {
        printf("%d",ans);
    }
        
    return 0;
}