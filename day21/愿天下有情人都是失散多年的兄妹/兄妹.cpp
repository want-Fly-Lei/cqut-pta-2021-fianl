#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int vis[MAX],flag;
struct man{
    int dad,mom;
    char sex;
    man():dad(-1),mom(-1){}
}a[MAX];

void dfs(int x,int d){
    if(d>5)return;
    vis[x]=1;
    if(a[x].dad!=-1)dfs(a[x].dad,d+1);
    if(a[x].mom!=-1)dfs(a[x].mom,d+1);
} 

void jud(int x,int d){
    if(d>5)return;
    if(!vis[x]){
        if(a[x].dad!=-1)jud(a[x].dad,d+1);
        if(a[x].mom!=-1)jud(a[x].mom,d+1);
    } else {
        flag=1;
        return;
    }
}

int main(){
    int n,i,id,x,y,k;
    char sex;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>id;
        scanf(" %c%d%d",&a[id].sex,&a[id].dad,&a[id].mom);
        a[a[id].dad].sex='M';
        a[a[id].mom].sex='F'; 
    }
    cin>>k;
    while(k--){
        cin>>x>>y;
        if(a[x].sex==a[y].sex) {
            printf("Never Mind\n");
        } else {
            memset(vis,0,sizeof(vis));
            flag=0;
            dfs(x,1);
            jud(y,1);
            if(flag) {
                printf("No\n");
            } else {
                printf("Yes\n");
            }
        }
    }
    return 0;
}