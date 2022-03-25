#include <set>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (auto i = a; i <= b; ++i)
#define bep(i, a, b) for (auto i = a; i >= b; --i)
#define lowbit(x) (x & (-x))
#define ch() getchar()
#define x first
#define y second
#define pc(x) putchar(x)
using namespace std;

template <typename T>
void read(T &x){
    static char c;
    static int f;
    for (c = ch(), f = 1; c < '0' || c > '9'; c = ch()) {
        if (c == '-') {
            f = -f;
        }
    }
       
            
    for (x = 0; c >= '0' && c <= '9'; c = ch()) {
        x = x * 10 + (c & 15);
    } 
    x *= f;
}

//好家伙，泛型编程
template <typename T>

void write(T x){
    static char q[65];
    int cnt = 0;
    if (x < 0) {
        pc('-'), x = -x;
    }
        
    q[++cnt] = x % 10, x /= 10;
    while (x) {
        q[++cnt] = x % 10, x /= 10;
    }
        
    while (cnt) {
        pc(q[cnt--] + '0');
    }
        
}

const int N = 1e5 + 10, inf = 0x7fffffff;
int n, q;
int se[N];
pair<int, int> p[N];

int sum[N << 2], lazy[N << 2];

void build(int l, int r, int p){
    if (l == r){
        sum[p] = se[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    sum[p] = min(sum[p << 1], sum[p << 1 | 1]);
    return ;
}

void add(int l, int r, int s, int t, int p, int k){
    if (s <= l and r <= t){
        sum[p] += k;
        lazy[p] += k;
        return;
    }
    if (lazy[p] and l < r){
        sum[p << 1] += lazy[p], sum[p << 1 | 1] += lazy[p], lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        lazy[p] = 0;
    }
    int mid = l + r >> 1;
    if (s <= mid) {
        add(l, mid, s, t, p << 1, k);
    }
        
    if (t > mid) {
        add(mid + 1, r, s, t, p << 1 | 1, k);
    }
        
    sum[p] = min(sum[p << 1], sum[p << 1 | 1]);
}

int query(int l, int r, int s, int t, int p){
    if (s <= l and r <= t){
        return sum[p];
    }
    if (lazy[p] and l < r){
        sum[p << 1] += lazy[p], sum[p << 1 | 1] += lazy[p], lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        lazy[p] = 0;
    }
    int mid = l + r >> 1;
    int ans = inf;
    if (s <= mid) {
        ans = query(l, mid, s, t, p << 1);
    }
        
    if (t > mid) {
        ans = min(query(mid + 1, r, s, t, p << 1 | 1), ans);
    }
        
    return ans;
}

void work(){
    ll ans = 0ll;
    rep(i, 1, q){
        int l = p[i].y + 1, r = p[i].x;
        int t = query(1, n - 1, l, r, 1);
        add(1, n - 1, l, r, 1, -t);
        ans += 1ll * t;
    }
    write(ans);
    pc('\n');
}

void solve(){
    read(n);
    read(q);
    rep(i, 1, n - 1){
        read(se[i]);
    }
    build(1, n - 1, 1);
    rep(i, 1, q){
        int u, v;
        read(u);
        read(v);
        if (u > v) {
            swap(u, v);
        }
            
        p[i] = {v, u};
    }
    sort(p + 1, p + 1 + q);
    work();
}
signed main(){
    solve();
    return 0;
}
