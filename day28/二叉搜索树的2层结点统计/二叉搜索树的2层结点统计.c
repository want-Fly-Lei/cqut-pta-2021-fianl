#include <string.h>
#include<stdio.h>

#define N 1010
#define INF 0x3f3f3f3f

int l[N], r[N], val[N], n;
int cnt[N], max_depth;

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

void dfs(int root, int u, int depth) {
    if (val[u] <= val[root]) {
        if (l[root] == INF) {
            l[root] = u;
            cnt[depth + 1]++;
            max_depth = max(max_depth, depth + 1);
        } else {
            dfs(l[root], u, depth + 1);
        }
    } else {
        if (r[root] == INF) {
            r[root] = u;
            cnt[depth + 1]++;
            max_depth = max(max_depth, depth + 1);
        } else {
            dfs(r[root], u, depth + 1);
        }
    }
}

int main() {
    scanf("%d",&n);
    memset(l, 0x3f, sizeof l), memset(r, 0x3f, sizeof r);

    if (n == 1) {
        puts("1");
        return 0;
    }
    int i, x;
    for (i = 0; i < n; i++) {
        scanf("%d",&x);
        if (!i) {
            val[0] = x;
        } else {
            val[i] = x;
            dfs(0, i, 0);
        }
    }
    printf("%d\n",cnt[max_depth] + cnt[max_depth - 1]);
    
    return 0;
}