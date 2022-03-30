#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include <algorithm>
using namespace std;
int n, g, k;

struct node{
    string id;
    int grade;
} f[10001];

bool cmp(node a, node b){
    if (a.grade == b.grade){
        return a.id < b.id;
    }
    return a.grade > b.grade;
}

int main(){
    scanf("%d %d %d", &n, &g, &k);
    int sum = 0, i;
    for (i = 1; i <= n; i++){
        cin >> f[i].id >> f[i].grade;
        if (f[i].grade >= g){
            sum += 50;
        } else if (f[i].grade >= 60){
            sum += 20;
        }
    }

    printf("%d\n",sum);
    sort(f + 1, f + 1 + n, cmp);
    int cnt = 0, m = 1;
    for (i = 1; i <= n; i++){
        if (f[i].grade != f[i - 1].grade){
            cnt += m;
            if (cnt > k){
                break;
            }
            m = 1;
            cout << cnt << " " << f[i].id << " " << f[i].grade << endl;
        } else{
            ++m;
            cout << cnt << " " << f[i].id << " " << f[i].grade << endl;
        }
    }
    return 0;
}
