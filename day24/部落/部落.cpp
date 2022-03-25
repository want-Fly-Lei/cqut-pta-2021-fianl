#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
int n, k;
int f[10001], vis[10001];
set<int> ss;
set<int> aa;
set<int>::iterator it;

int find(int x){
    if (vis[x] == x){
        return x;
    } else{
        vis[x] = find(vis[x]);
        return vis[x];
    }
}

void merge(int a, int b){
    int p = find(a);
    int q = find(b);
    if (p == q){
        return;
    } else{
        vis[q] = p;
    }
}

int main(){
    scanf("%d",&n);
    for (int i = 1; i <= 10000; i++){
        vis[i] = i;
    }
    int m, s;

    while (n--){
        scanf("%d %d",&k,&m);
        ss.insert(m);
        for (int i = 1; i < k; i++){
            scanf("%d",&s);
            ss.insert(s);
            merge(m, s);
        }
    }

    for (it = ss.begin(); it != ss.end(); it++){
        int bb = find(*it);
        aa.insert(bb);
    }

    printf("%d %d\n",ss.size(), aa.size());
    int l;
    scanf("%d",&l);
    while (l--){
        int a, b;
        scanf("%d %d",&a, &b);
        if (find(a) == find(b)){
            printf("Y\n");
        } else{
            printf("N\n");
        }
    }
    return 0;
}
