#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{						//家庭成员结构体
	int parent = 10000; //该家庭成员的超父辈编号
	set<int> child;
	double t = 0;
	double sum = 0;
};

int n;
Node ns[10000];

//比较器
bool cmp(Node a, Node b){
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	}
	return *a.child.begin() < *b.child.begin();
}

int main(){
	scanf("%d",&n);
	int iv[n + 1];
	memset(iv, 0, sizeof(int) * (n + 1));
	vector<int> tv;
	set<int> vs;
	set<int>::iterator it, jt;
	int tid, k, i, j;

	for (i = 1; i <= n; ++i){
		tv.clear();
		vs.clear();
		for (j = 0; j < 3; ++j){
			scanf("%d",&tid);
			if (tid != -1) {
				tv.push_back(tid);
			}
		}

		scanf("%d",&k);
		while (k--){
			scanf("%d",&tid);
			tv.push_back(tid);
		}
		
		scanf("%lf %lf",&ns[i].t,&ns[i].sum);

		for (j = 0; j < tv.size(); ++j){
			if (ns[tv[j]].parent != 10000){
				vs.insert(ns[tv[j]].parent);
			}
			ns[i].child.insert(tv[j]);
		}

		//合并家庭
		if (!vs.empty()){
			for (it = vs.begin(); it != vs.end(); ++it){
				ns[i].child.insert(ns[*it].child.begin(), ns[*it].child.end());
				ns[i].t += ns[*it].t;
				ns[i].sum += ns[*it].sum;
				ns[*it].child.clear();
				iv[*it] = 0;
			}
		}
		iv[i] = i; //独立家庭的下标

		//指定每个家庭成员的父辈parent为i
		for (it = ns[i].child.begin(); it != ns[i].child.end(); ++it){
			ns[*it].parent = i;
		}
	}

	int count = 0;
	vector<Node> nv;
	for (i = 1; i <= n; ++i){
		if (iv[i]){
			ns[i].t /= ns[i].child.size();
			ns[i].sum /= ns[i].child.size();
			++count;
			nv.push_back(ns[i]);
		}
	}

	sort(nv.begin(), nv.end(), cmp);
	printf("%d\n",nv.size());
	k = 0;
	vector<Node>::iterator nt;
	for (nt = nv.begin(); nt != nv.end(); ++nt){
		printf("%04d %d %.3lf %.3lf", *((*nt).child.begin()), (*nt).child.size(), (*nt).t, (*nt).sum);
		if (k++ != count - 1) {
			putchar('\n');
		}
	}
	return 0;
}