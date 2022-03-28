#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct arr{
    int index,count,money;
}ARR;

bool cmp(ARR a1, ARR a2) {
    if (a2.money < a1.money) {
        return true;
    } else if(a2.money == a1.money) {
        if(a1.count > a2.count) {
            return true;
        } else if(a1.count == a2.count) {
            return a1.index < a2.index;
        }
        return false;
    }
    return false;
}

int main(){
    int n, m, i, j;
    scanf("%d",&n);
    ARR A[n];
    for(i = 0; i < n; i++) {
        A[i].index = i + 1;
        A[i].money = A[i].count = 0;
    }
    int index, money;
    for(i = 0; i < n; i++) {
        scanf("%d",&m);
        for(j = 0; j < m; j++) {
            scanf("%d %d",&index,&money);
            A[i].money -= money;
            A[index - 1].money += money;
            A[index - 1].count++;
        }
    }
    sort(A,A + n,cmp);
    for(i = 0; i < n; i++) {
        printf("%d %.2lf\n",A[i].index,A[i].money * 0.01);
    }
    return 0;
}