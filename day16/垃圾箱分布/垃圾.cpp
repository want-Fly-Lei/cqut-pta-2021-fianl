#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,s,tot;
int first[10005],dis[10005];
struct TT
{
    int to,nxt,len;
} edge[20005];
struct T
{
    int a,c;
    bool operator <(const T &x)const
    {
        return c>x.c;
    }
} p,x;
void add(int x,int y,int z)
{
    edge[++tot].nxt=first[x];
    first[x]=tot;
    edge[tot].to=y,edge[tot].len=z;
}
int la(string s)
{
    int x=0;
    if(s[0]!='G')
    {
        for(int i=0; s[i]; i++)x=x*10+s[i]-'0';
    }
    else
    {
        for(int i=1; s[i]; i++)x=x*10+s[i]-'0';
        x+=n;
    }
    return x;
}
int main()
{
    int m,k,ds;
    cin>>n>>m>>k>>ds;
    string s1,s2;
    for (int i=1,u,v,w; i <= k; i++)
    {
        cin>>s1>>s2>>w;
        u=la(s1),v=la(s2);
        add(u,v,w),add(v,u,w);
    }
    int ans_max=-1,ans_id=0,ans_sum=0;
    for(int i=1; i<=m; i++)
    {
        int s=i+n;
        memset(dis,INF,sizeof dis);
        priority_queue<T>q;
        q.push({s,0}),dis[s]=0;
        while(!q.empty())
        {
            p=q.top(),q.pop();
            for(int u=first[p.a],to; u; u=edge[u].nxt)
            {
                to=edge[u].to;
                if(dis[to]>p.c+edge[u].len)
                    dis[to]=p.c+edge[u].len,x.a=to,x.c=dis[to],q.push(x);
            }
        }
        int tmi=INF,tma=-1,sum=0;
        for(int j=1; j<=n; j++)tmi=min(tmi,dis[j]),tma=max(tma,dis[j]),sum+=dis[j];
        if(tma<=ds&&tmi>ans_max)ans_max=tmi,ans_id=i,ans_sum=sum;
        else if(tma<=ds&&tmi==ans_max&&sum<ans_sum)ans_id=i,ans_sum=sum;
    }
    if(ans_id)
    {
        cout<<"G"<<ans_id<<"\n";
        printf("%.1f %.1f",ans_max*1.,ans_sum*1./n);
    }
    else cout<<"No Solution";
    return 0;
}
