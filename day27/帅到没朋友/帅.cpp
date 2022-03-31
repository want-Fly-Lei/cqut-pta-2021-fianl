#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
//如果最后一个超时，请使用c++(clang)版本的那个，不得不说，苹果开发的c牛批

int main() {
	int i, j , m, n, temp;
	scanf("%d",&m);
	vector<int> ve,ve2;
	for(i = 0; i < m; i++) {
		scanf("%d",&n);
		for(j = 0; j < n; j++) {
			scanf("%d",&temp);
			//fuck居然还有一个人一个朋友圈，你发锤子朋友圈
			if(n != 1) {
				ve.push_back(temp);
			}
		}
	}
	sort(ve.begin(),ve.end());
	ve.erase(unique(ve.begin(),ve.end()),ve.end());

	scanf("%d",&m);
	for(i = 0; i < m; i++) {
		scanf("%d",&temp);
		ve2.push_back(temp);
	}

	m = ve2.size();
	for(i = 0; i < m - 1; i++) {
		if(ve2[i] == 0) {
			continue;
		}
		for(j = i + 1; j < m; j++) {
			if(ve2[i] == ve2[j]) {
				ve2[j] = 0;
			}
		}
	}

	m = 0;
	for(i = 0; i < ve2.size();i++) {
		if(ve2[i] == 0) {
			continue;
		}
		n = 0;
		for(j = 0; j < ve.size(); j++) {
			if(ve[j] == ve2[i]) {
				n = 1;
				break;
			}
		}
		if(n == 0) {
			if(m == 0) {
				printf("%05d",ve2[i]);
				m = 1;
			} else {
				printf(" %05d",ve2[i]);
			}
		}
	}
	if(m == 0) {
		printf("No one is handsome\n");
	} else {
		printf("\n");
	}
	return 0;
}