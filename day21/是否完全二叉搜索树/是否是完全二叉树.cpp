#include <bits/stdc++.h>
using namespace std;
int const N = 2100000;
int a[N], n;
void insert(int pos, int val){
    if (a[pos] == 0){
        a[pos] = val;
    } else{
        if (val > a[pos]){
            insert(2 * pos, val);
        } else{
            insert(2 * pos + 1, val);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        insert(1, tmp);
    }
    bool flag = true;
    int cnt = 0;
    for (int i = 1; i < N; i++){
        if (a[i]){
            printf("%d%c", a[i], ++cnt != n ? ' ' : '\n');
            if (i > n){
                flag = false;
            }
        }
    }

    if (flag){
        printf("YES\n");
    } else{
        printf("NO\n");
    }
    return 0;
}