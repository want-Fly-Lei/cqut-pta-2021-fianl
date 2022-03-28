#include "bits/stdc++.h"
using namespace std;
map<int, int> ans;
int a[1020];
int vis[1020];

int find(int u){
    return u == a[u] ? u : a[u] = find(a[u]);
}

bool cmp(int p, int k){
    return p > k;
}

const int limit = 1e3 + 10;

int main(){
    int n, i, j, id, num, id2;
    scanf("%d",&n);
    for (int i = 1; i <= limit; i++) {
        a[i] = i;
    }
        
    for (i = 1; i <= n; i++){
        scanf("%d:", &num);
        scanf("%d",&id);
        id = find(id);
        vis[id]++;

        for (j = 1; j < num; j++){
            scanf("%d",&id2);
            id2 = find(id2);
            a[id2] = id;
            vis[id] += vis[id2];
            vis[id2] = 0;
        }
    }

    vector<int> ans2;
    for (int i = 1; i <= limit; i++) {
        if (vis[i]) {
            ans2.push_back(vis[i]);
        }
    }
        
            
    sort(ans2.begin(), ans2.end(), cmp);
    j = 1;
    printf("%d\n",ans2.size());
    for (int u : ans2){
        if (j != ans2.size()) {
            printf("%d ",u);
        } else {
            printf("%d",u);
        }    
        ++j;
    }
    return 0;
}