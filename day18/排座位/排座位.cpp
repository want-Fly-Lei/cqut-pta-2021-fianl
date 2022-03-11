#include<bits/stdc++.h>
using namespace std;

int root[105],is[105][105],n,m,k;

int getr(int kk){
    if(root[kk]==kk) return kk;
    else return root[kk]=getr(root[kk]);
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        root[i]=i;
    int a,b,c;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        if(c==1){
            int ar=getr(a),br=getr(b);
            if(ar!=br)
                root[br]=ar;
        }
        else
            is[a][b]=is[b][a]=1;
    }
    while(k--){
        scanf("%d%d",&a,&b);
        int ar=getr(a),br=getr(b);
        if(ar==br&&!is[a][b]) printf("No problem\n");
        else if(ar==br&&is[a][b]) printf("OK but...\n");
        else if(ar!=br&&!is[a][b]) printf("OK\n");
        else printf("No way\n");
    }
    return 0;
}