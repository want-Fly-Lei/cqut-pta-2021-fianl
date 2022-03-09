//实在不想自己写了，直接抄了
#include<stdio.h>
#include<stack>
using namespace std;
 
const int MAX = 1000000;
int mapl[500][500];
int mapt[500][500];
int vis[500];
int pre[500];
int dis[500];
int tim[500];
int n;
 
void init() {
	int i;
	for (i = 0; i<n; i++) {
		vis[i] = false;
		dis[i] = MAX;
		tim[i] = MAX;
	}
}
 
void dijkstraForTime(int source, int dest) {
	init();
	int i;
	int u = source;
	tim[u] = 0;
	dis[u] = 0;
	while (u != dest) {
		vis[u] = true;
		int tempt, templ;
		for (i = 0; i<n; i++) {
			if (vis[i])continue;
			tempt = mapt[u][i] + tim[u];
			templ = mapl[u][i] + dis[u];
			if (tempt<tim[i]) {
				tim[i] = tempt;
				dis[i] = templ;
				pre[i] = u;
			}
			else if (tim[i] != MAX&&tempt == tim[i]) {
				if (templ<dis[i]) {
					dis[i] = templ;
					pre[i] = u;
				}
			}
		}
		tempt = MAX;
		for (i = 0; i<n; i++) {
			if (!vis[i] && tempt>tim[i]) {
				tempt = tim[i];
				u = i;
			}
		}
	}
}
 
void dijkstraForLength(int source, int dest) {
	init();
	int i;
	int u = source;
	tim[u] = 1;
	dis[u] = 0;
	while (u != dest) {
		vis[u] = true;
		int tempt, templ;
		for (i = 0; i<n; i++) {
			if (vis[i])continue;
			tempt = 1 + tim[u];
			templ = mapl[u][i] + dis[u];
			if (templ<dis[i]) {
				tim[i] = tempt;
				dis[i] = templ;
				pre[i] = u;
			}
			else if (dis[i] != MAX&&templ == dis[i]) {
				if (tempt<tim[i]) {
					tim[i] = tempt;
					pre[i] = u;
				}
			}
		}
		templ = MAX;
		for (i = 0; i<n; i++) {
			if (!vis[i] && templ>dis[i]) {
				templ = dis[i];
				u = i;
			}
		}
	}
}
 
void getroad(int source, int dest, stack<int>& citys, int* pre) {
	int u = dest;
	while (u != source) {
		citys.push(u);
		u = pre[u];
	}
	citys.push(source);
}
 
bool judge(stack<int> a, stack<int> b) {
	int len1 = a.size();
	int len2 = b.size();
	if (len1 != len2) return false;
	while (len1--) {
		if (a.top() != b.top()) return false;
		a.pop();
		b.pop();
	}
	return true;
}
 
int main() {
	int m;
	scanf("%d%d", &n, &m);
	int i;
	for (i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			mapl[i][j] = MAX;
			mapt[i][j] = MAX;
		}
	int v1, v2, style, length, time;
	for (i = 0; i<m; i++) {
		scanf("%d%d%d%d%d", &v1, &v2, &style, &length, &time);
		mapl[v1][v2] = length;
		mapt[v1][v2] = time;
		if (!style) {
			mapl[v2][v1] = length;
			mapt[v2][v1] = time;
		}
	}
	int source, dest, mintime, mindis;
	scanf("%d%d", &source, &dest);
	dijkstraForTime(source, dest);
	mintime = tim[dest];
	stack<int> troad;
	getroad(source, dest, troad, pre);
	dijkstraForLength(source, dest);
	mindis = dis[dest];
	stack<int> lroad;
	getroad(source, dest, lroad, pre);
	if (judge(lroad, troad))
	{
		printf("Time = %d; Distance = %d: %d", mintime, mindis, lroad.top());
		lroad.pop();
		while (!lroad.empty()) {
			printf(" => %d", lroad.top());
			lroad.pop();
		}
	}
	else {
		printf("Time = %d: %d", mintime, troad.top());
		troad.pop();
		while (!troad.empty()) {
			printf(" => %d", troad.top());
			troad.pop();
		}
		printf("\n");
		printf("Distance = %d: %d", mindis, lroad.top());
		lroad.pop();
		while (!lroad.empty()) {
			printf(" => %d", lroad.top());
			lroad.pop();
		}
	}
	printf("\n");
	return 0;
}