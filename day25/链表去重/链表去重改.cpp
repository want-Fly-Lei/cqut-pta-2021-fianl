#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef double db;
typedef long long LL;
typedef vector<int> VI;
const int inf = 2e9;
const LL INF = 8e18;
const int maxn = 1e6;
const int maxN = 1e5;
int hashTable[maxN] = {0};
struct node{
    int data, next;
} v[maxn], del[maxn];

int main(){
    int now, n, next, data, start, last, dlast, dstart;
    cin >> start >> n;
    for (int i = 0; i < n; i++){
        cin >> now >> data >> next;
        v[now].data = data;
        v[now].next = next;
    }
    int cnt = 0, sum = 0; // cnt统计重复的个数
    now = start;

    while (now != -1){
        sum++;
        int tmp = abs(v[now].data);
        if (!hashTable[tmp]){
            hashTable[tmp] = 1;
            last = now; //就是这个！！！应该写这里！！
        } else {
            cnt++;
            del[now].data = v[now].data;
            if (cnt > 1)
                del[dlast].next = now;
            else
                dstart = now;
            dlast = now;
            v[last].next = v[now].next;
        }
        // last = now;
        now = v[now].next;
    }
    now = start;
    for (int i = 1; i <= (sum - cnt); i++){
        printf("%05d %d ", now, v[now].data);
        if (i == (sum - cnt))
            printf("-1");
        else
            printf("%05d", v[now].next);
        now = v[now].next;
        printf("\n");
    }
    now = dstart;
    for (int i = 1; i <= cnt; i++){
        printf("%05d %d ", now, del[now].data);
        if (i == cnt)
            printf("-1");
        else
            printf("%05d", del[now].next);
        now = del[now].next;
        printf("\n");
    }
    return 0;
}
