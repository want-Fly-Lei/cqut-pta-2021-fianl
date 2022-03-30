#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct People{
	int father;
	int rank;
	vector<int> son;
} a[100005];

int FindRank(int x){
	queue<People> P;
	P.push(a[x]);
	People Q;
	int i;
	while (!P.empty()){ //当队列空了的时候Q 就辈分最小的
		Q = P.front();
		P.pop();
		for (i = 0; i < Q.son.size(); i++){
			a[Q.son[i]].rank = Q.rank + 1; //他的儿子的辈分加一
			P.push(a[Q.son[i]]);		   //再把他的儿子放入队列，待会儿还是进行son.rank+1
		}
	}
	return Q.rank;
}

int main(){
	int t, temp, i, j;
	scanf("%d", &t);
	for (i = 1; i <= t; i++){
		scanf("%d", &a[i].father);
		if (a[i].father != -1){
			//都有父亲节点
			a[a[i].father].son.push_back(i); //将数据进行整合
		} else{
			temp = i;
			a[i].rank = 1; //找到了最老最老的祖先节点
		}
	}

	int max = FindRank(temp); //从祖先节点开始，找最小的辈分数
	temp = 0;
	printf("%d\n", max);
	for (i = 1; i <= t; i++){
		if (a[i].rank == max){
			if (temp != 0){
				putchar(' ');
			}
			printf("%d", i);
			temp++;
		}
	}
	putchar('\n');
	return 0;
}