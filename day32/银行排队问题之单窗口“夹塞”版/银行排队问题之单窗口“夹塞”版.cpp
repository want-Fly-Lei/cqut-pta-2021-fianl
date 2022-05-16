#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <cctype>
#include <vector>
#include <algorithm>
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 10000 + 7;

int n, m, L, sum;
struct node {
    string name;
    int t, p, len;
} a[maxn];

bool vis[maxn];
vector<string> vec;
map<string, int> mp;

void init() {
    memset(vis, false, sizeof vis);
    sum = 0;
    scanf("%d %d", &n, &m);
    int i, j;
    string s;
    for (i = 1; i <= m; ++i) {
        scanf("%d", &L);
        for (j = 0; j < L; ++j) {
            cin >> s;
            mp[s] = i;
        }
    }

    int cnt = m + 1;
    for (i = 0; i < n; ++i) {
        cin >> a[i].name;
        if (mp[a[i].name] == 0) {
            mp[a[i].name] = cnt++;
        }
        scanf("%d %d", &a[i].t, &a[i].p);
        if (a[i].p > 60) {
            a[i].p = 60;
        }
    }
}

void work(int pos, int id) {
    for (int i = pos + 1; i < n; ++i) {
        if (!vis[i]) {
            if (mp[a[i].name] == id) {
                if (a[i].t <= sum) {
                    vis[i] = true;
                    a[i].len = sum - a[i].t;
                    sum += a[i].p;
                    vec.push_back(a[i].name);
                } else {
                    return;
                }   
            }
        }
    }
}

void solve(){
    int i;
    for (i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            if (a[i].t > sum) {
                sum = a[i].t;
            }
            a[i].len = sum - a[i].t;
            sum += a[i].p;
            vec.push_back(a[i].name);
            work(i, mp[a[i].name]);
        }
    }

    for (i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
        
    sum = 0;
    for (i = 0; i < n; ++i) {
        sum += a[i].len;
    }
    printf("%.1lf\n", 1.0 * sum / n);
}

int main() {
    init();
    solve();
    return 0;
}