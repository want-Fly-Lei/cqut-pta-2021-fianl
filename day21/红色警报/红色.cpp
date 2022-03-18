#include<bits/stdc++.h>
using namespace std;

int n,m,k,t1,t2,cnt,cnt1;
int a[505][505],vis[505];
queue<int> q;

void bfs(int p){
    q.push(p);
    while(!q.empty()){
        int nw=q.front();
        q.pop();
        for(int i=0;i<n;++i)
            if(!vis[i]&&a[nw][i]){
                vis[i]=1;
                q.push(i);
            }
    }
}

int getc(){
    int res=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;++i)
        if(!vis[i]){
            vis[i]=1;
            ++res;
            bfs(i);
        }
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&t1,&t2);
        a[t1][t2]=a[t2][t1]=1;
    }
    cnt=getc();
    scanf("%d",&k);
    for(int i=1;i<=k;++i){
        scanf("%d",&t1);
        for(int j=0;j<n;++j)
            a[t1][j]=a[j][t1]=0;
        cnt1=getc();
        if(cnt1>cnt+1)
            printf("Red Alert: City %d is lost!\n",t1);
        else
            printf("City %d is lost.\n",t1);
        if(i==n)
            printf("Game Over.\n");
        cnt=cnt1;
    }
    return 0;
}