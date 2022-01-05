#include<cstdio>
using namespace std;
int n;
int a[1005],up[1005],dw[1005];
int ans=0;
int max(int a,int b){
    return a > b ? a:b;
}
int max(int a, int b,int c) {
    if(a >= b && a >= c) {
        return a;
    } else if(b >= c){
        return b;
    }
    return c;
}
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }  
    for(i=n;i>=1;i--){
        up[i]=dw[i]=1;
        for(j=i+1;j<=n;j++){
            if(a[j]>a[i])
                up[i]=max(up[i],dw[j]+1);
            else if(a[j]<a[i])
                dw[i]=max(dw[i],up[j]+1);
        }
        ans=max(ans,max(up[i],dw[i]));
    }
    printf("%d\n",ans);
    return 0;
}
