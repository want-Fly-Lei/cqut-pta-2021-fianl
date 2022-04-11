#include <bits/stdc++.h>
using namespace std;
vector<int> r[1100]; // r[i]表示第i张照片，里面的元素表示照片中的人
bool sex[1100];
int n, m, k, d, a, b;

void print(int a, int b){
    if (sex[a]) {
        putchar('-');
    }
    printf("%d ",a);
    if (sex[b]) {
        putchar('-');
    }
    printf("%d\n",b);
}

//编号从低到高输出，最大值的编号
void print1(int c, double a[], int k){
    for (int i = 0; i < n; i++){
        if (a[i] == a[k]) {
            print(c, i);
        }   
    }
}

//分别找a,b的亲密度最高的异性。返回值为判断a,b是否为亲密度最高的情侣
bool search(int a, int b, double cn[], int &k){
    int i, j;
    for (i = 0; i < m; i++){
        k = r[i].size();
        for (j = 0; j < k; j++){
            if (r[i][j] == a) {
                break;
            }
        }

        if (j >= k) {
            continue; //照片中没有a
        }
            
        for (j = 0; j < k; j++){
            if (sex[r[i][j]] ^ sex[a]) {
                cn[r[i][j]] += 1.0 / k;
            }  
        }
    }

    k = 0;
    double maxx = -1;
    for (i = 0; i < n; i++)
        if (cn[i] > maxx){
            maxx = cn[i];
            k = i;
        }
    if (cn[b] == cn[k]) {
        return 1;
    }
    return 0;
}

int main(){
    char s[10];
    scanf("%d %d",&n,&m);
    int i, j;
    for (i = 0; i < m; i++){
        scanf("%d",&k);
        for (j = 0; j < k; j++){
            scanf("%s",s);
            int t = abs(atoi(s));
            if (s[0] == '-') {
                sex[t] = 1; //如果为女性将对应标号的Sex[]置为1
            } 
            r[i].push_back(t);
        }
    }

    scanf("%s",s);
    a = abs(atoi(s));
    if (s[0] == '-') {
        sex[a] = 1;
    }
        
    scanf("%s",s);
    b = abs(atoi(s));
    if (s[0] == '-') {
        sex[b] = 1;
    }
        
    int c, d, e, f;                      // c,d表示最大值在亲密度ca,cb数组中的位置（即函数中的k，注意k是引用，所以c,d的值会跟着变化）
    double ca[1100] = {}, cb[1100] = {}; // ca存储与a的异性的亲密度，cb是与b的异性的亲密度
    e = search(a, b, ca, c);
    f = search(b, a, cb, d);
    if (e && f) {
        print(a, b);
    } else {
        print1(a, ca, c);
        print1(b, cb, d);
    }
    return 0;
}
