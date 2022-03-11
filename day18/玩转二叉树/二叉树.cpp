#include<bits/stdc++.h>
using namespace std;
struct Node{ int l;int r;}a[1000];
int pre[1000],mid[1000],n;
int build(int ml,int mr,int pl,int pr){
	if(ml>mr)return 0;//如果不正常返回0，也就是叶节点的下一个结点	
	int root=pre[pl],p1,num,index=ml;
	while(mid[index]!=pre[pl])index++;
	num=index-ml;
	a[root].l=build(ml,index-1,pl+1,pl+num);
	a[root].r=build(index+1,mr,pl+num+1,pr);
	return root;
}
void bfs(int root){
	queue<int> ans;
	vector<int> res;
	ans.push(root);
	while(!ans.empty()){
		int t=ans.front();ans.pop();	
		if(t==0)break;//发生了错误 
		res.push_back(t); 
		if(a[t].r!=0)ans.push(a[t].r);
		if(a[t].l!=0)ans.push(a[t].l);
	}
	cout<<res[0];
	for(int i=1;i<res.size();i++)cout<<" "<<res[i];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mid[i];
	for(int i=1;i<=n;i++)cin>>pre[i];
	int root=build(1,n,1,n);
	bfs(root);	
	return 0;
}