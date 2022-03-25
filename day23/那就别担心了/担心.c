#include<stdio.h>
int i, m, n, temp1, temp2, count;
int sli[500][500] = {0};
int flag = 1;
//final test will over time
void getRote(int t1) {
	int hereFlag = 0;
	for(int i = 0; i < m; i++) {
		if (sli[t1][i] == 1) {
			if(i == temp2) {
				++count;
			} else {
				getRote(i);
			}
			hereFlag = 1;
		}
	}

	if (!hereFlag) {
		flag = 0;
	}
}

int main() {
	scanf("%d %d",&m, &n);
// 	for(i = 0; i < m; i++) {
// 		for(int j = 0; j < m; j++) {
//             sli[i][j] = 0;
//         }
// 	}
	for (i = 0; i < n; i++) {
		scanf("%d %d",&temp1, &temp2);
		sli[temp1-1][temp2-1] = 1;
	}
	scanf("%d %d",&temp1, &temp2);
    --temp2;
	getRote(temp1-1);

	if (flag) {
		printf("%d Yes\n",count);
	} else {
		printf("%d No\n",count);
	}
}
