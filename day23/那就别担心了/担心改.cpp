#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 505;
int n, m, a, b, path[maxn], v[maxn], flag, i , t, to;
vector<int> vec[maxn];
queue<int> que;

int main(){
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b), vec[a].push_back(b);
    }
        
    scanf("%d %d", &a, &b);
    que.push(a);
    v[a] = 1;
    path[a] = 1;

    while (que.size()){
        t = que.front();
        que.pop();
        v[t] = 0;
        if (t == b) {
            continue;
        }
            
        for (i = 0; i < vec[t].size(); i++){
            to = vec[t][i];
            path[to] += path[t];
            if (!v[to]) {
                que.push(to), v[to] = 1;
            }
        }

        path[t] = 0; //防止重复记录
        if (!vec[t].size()) {
            flag = 1;
        } 
    }
    printf("%d %s", path[b], flag ? "No" : "Yes");
}
