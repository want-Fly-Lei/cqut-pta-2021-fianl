#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;

struct jj{
    int v, com, next, wi;
} w[1000000];
int h[10000], numw = 0;

void inser(int u, int v, int com, int wi){
    w[numw].v = v;
    w[numw].wi = wi;   //记录长度
    w[numw].com = com; //记录公司
    w[numw].next = h[u];
    h[u] = numw++;
}

void spfa(int s, int t){
    int i, v[10000], dis[10000][2], pre[10000][2], pos, a[10000][2], top = 0;
    queue<int> q;
    for (i = 0; 10000 > i; i++) {
        v[i] = 0;
        dis[i][0] = dis[i][1] = 1e9 + 7; // dis数组dis[i][0]是经停站数量，dis[i][1]是中转站数量
        pre[i][0] = -1;                  // pre数组pre[i][0]是该最短路上一个车站的编号，pre[i][1]是当前车站所属公司编号
    }

    dis[s][0] = dis[s][1] = 0;
    q.push(s);
    while (q.empty() == false){
        s = q.front();
        q.pop();
        v[s] = 0;
        for (i = h[s]; i != -1; i = w[i].next){
            pos = w[i].v;
            if (dis[pos][0] > dis[s][0] + w[i].wi) {//经停站数量更新
                dis[pos][0] = dis[s][0] + w[i].wi;
                dis[pos][1] = dis[s][1] + 1;
                pre[pos][0] = s;
                pre[pos][1] = w[i].com;
                if (v[pos] == 0){
                    v[pos] = 1;
                    q.push(pos);
                }
            } else if (dis[pos][0] == dis[s][0] + w[i].wi && dis[pos][1] > dis[s][1] + 1) {//中转站数量更新
                dis[pos][1] = dis[s][1] + 1;
                pre[pos][0] = s;
                pre[pos][1] = w[i].com;

                if (v[pos] == 0){
                    v[pos] = 1;
                    q.push(pos);
                }
            }
        }
    }
    if (dis[t][0] == 1000000007) {//不存在最短路，无法到达
        printf("Sorry, no line is available.\n");
    } else {
        printf("%d\n", dis[t][0]);
        a[top][0] = t; //取出路径

        while (pre[t][0] != -1){
            ++top;
            a[top][1] = pre[t][1];
            t = pre[t][0];
            a[top][0] = t;
        }

        for (i = top; i >= 1; i--){
            printf("Go by the line of company #%d from %04d to %04d.\n", a[i][1], a[i][0], a[i - 1][0]);
        }
    }
}
int main(){
    int n, k, i, i1, i2, s, t, a[100];
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    numw = 0;
    for (i = 1; n >= i; i++){
        scanf("%d", &k);
        for (i1 = 0; k > i1; i1++){
            scanf("%d", &a[i1]);
        }

        for (i1 = 0; k > i1; i1++) {//同一个公司车站两两建边
            for (i2 = 0; k > i2; i2++) {
                if (i1 != i2) {
                    inser(a[i1], a[i2], i, abs(i1 - i2));
                }
            }
        }
    }

    scanf("%d", &n);
    for (i = 1; n >= i; i++) {
        scanf("%d %d", &s, &t);
        spfa(s, t);
    }
    return 0;
}