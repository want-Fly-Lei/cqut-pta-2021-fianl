#include <iostream>
#include<cstdio>
#include <vector>
#include <math.h>
using namespace std;

vector<int> dai[100000];
int bei[100000];
double Z, r;

double dfs(int x, int t){
    double s = 0;
    if (dai[x].size() == 0) {
        s += bei[x] * Z * pow(1 - r / 100.0, t);
    } else {
        for (int i = 0; i < dai[x].size(); i++) {
            s += dfs(dai[x][i], t + 1);
        } 
    }   
    return s;
}

int main(){
    int num1, ren, i, j;
    scanf("%d %lf %lf",&num1,&Z,&r);
    int num2;
    for (i = 0; i < num1; i++){
        scanf("%d",&num2);
        if (num2 == 0) {
            scanf("%d",&bei[i]);
        } else{
            for (j = 0; j < num2; j++){
                scanf("%d",&ren);
                dai[i].push_back(ren);
            }
        }
    }
    printf("%lld\n",(long long)dfs(0,0));
}