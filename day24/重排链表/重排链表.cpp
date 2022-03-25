#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int x;
    int next;
    int adr;
};

node a[100005];
int n, i, j, cur;
node tmp[100005];
node ans[100005];

int main(){
    int start = 0;
    scanf("%d%d", &start, &n);
    for (i = 0; i < n; i++){
        int adr, x, next;
        scanf("%d%d%d", &adr, &x, &next);
        a[adr].x = x;
        a[adr].next = next;
        a[adr].adr = adr;
    }

    cur = start;
    j = 0;
    while (cur != -1){
        tmp[j] = a[cur];
        cur = a[cur].next;
        ++j;
        if (j >= n) {
            break;
        }
            
    }
    int findcnt = j;
    i = 0;
    j = findcnt - 1;
    int k = 0;
    while (i < j){
        ans[k++] = tmp[j--];
        ans[k++] = tmp[i++];
    }

    if (i == j){
        ans[k++] = tmp[i];
    }

    for (int i = 0; i < findcnt - 1; i++){
        ans[i].next = ans[i + 1].adr;
    }
    ans[findcnt - 1].next = -1;
    for (int i = 0; i < findcnt; i++){
        if (i != findcnt - 1) {
            printf("%05d %d %05d\n", ans[i].adr, ans[i].x, ans[i].next);
        } else {
            printf("%05d %d %d\n", ans[i].adr, ans[i].x, -1);
        }
    }

    return 0;
}