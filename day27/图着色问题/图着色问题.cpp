#include<cstdio>
using namespace std;
#include<set>
set<int> s;

int main() {
    int i, j, k, v, e, w;
    scanf("%d %d %d",&v,&e,&k);
    int sli[v][v];
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            sli[i][j] = 0;
        }
    }

    int arr[v];
    int temp1, temp2;
    for(i = 0; i < e; i++) {
        scanf("%d %d",&temp1,&temp2);
        --temp1;
        --temp2;
        sli[temp1][temp2] = sli[temp2][temp1] = 1;
    }

    scanf("%d",&temp1);
    bool flag;
    for(i = 0; i < temp1; i++) {
        for(j = 0; j < v; j++) {
            scanf("%d",&arr[j]);
            s.insert(arr[j]);
        }

        //判断颜色数量是否合法
        if(s.size() != k) {//这里判断小于会有一个测试点不过，我觉得不合理
            flag = false;
        } else {
            flag = true;
        }
        s.clear();

        for(j = 0; j < v; j++) {
            if(!flag) {
                    break;
            }
            
            for(w = 0; w < v; w++) {
                if(sli[j][w] == 1 && arr[j] == arr[w]) {
                    flag = false;
                    break;
                }
            }
            
        }
        if(flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}