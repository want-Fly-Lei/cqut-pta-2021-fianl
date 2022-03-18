#include<cstdio>
#include<algorithm>
#include<malloc.h>
using namespace std;

int main() {
	int i, j, m, n, k, sum, temp, min, max;
	scanf("%d %d %d",&n, &k, &m);
	int sli[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &min);
		max = sum = min;
		for( j = 1; j < k; j++) {
			scanf("%d", &temp);
			if(temp > max) {
				max = temp;
			} else if (min > temp ){
				min = temp;
			}
			sum += temp;
		}
		sli[i] = sum - min - max;
	}
    temp = k - 2;
	sort(sli,sli + n);
	for(i = n - m; i < n-1; i++){
		printf("%.3lf ", sli[i] * 1.0 / temp);
	}
	printf("%.3lf\n", sli[i] * 1.0 / temp);
    return 0;
}
