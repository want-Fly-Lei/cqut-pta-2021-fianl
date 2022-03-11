#include <cstdio>  
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxen=11000;
const int inf=0x3f3f3f3f;
int n,m,k,vis[maxen],sum[maxen];
int main(void){
    vector<int> v[11000];
    scanf("%d %d %d",&n,&m,&k);
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);  //加入能听到其回音的山头 
        v[b].push_back(a);
    }
    int p,t;
    for(int i=0;i<k;++i){
        queue<int>q;  
        int minn=inf,maxx=0;        //minn记录最远山头的坐标，maxx存最远能传几座山 
        memset(vis,0,sizeof(vis));  // 
        memset(sum,0,sizeof(sum));
        scanf("%d",&p);
        q.push(p);
        vis[p]=1;  //标记访问 
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(sum[top]>maxx){   
                maxx=sum[top];
                minn=inf;
            }
            //如果能走更远就更新maxx，然后minn也要更新，因为可能有另外的路径与现有最远路径相同长 
            if(top!=p){
            minn=min(minn,top);//更新最小标号 
            }
            for(int j=0;j<v[top].size();++j){
                t=v[top][j]; //能到哪座山 ； 
                if(vis[t]==0){ //判断该山是否被走过； 
                    q.push(t);//未走过就加入队列 
                    vis[t]=1; //标记走过 
                    sum[t]=sum[top]+1;//步数加一 
                }
            }
        }
            if(minn==inf){
            printf("0\n");
           }
            else
            printf("%d\n",minn);
    }
      return 0;
}