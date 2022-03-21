#include<stdio.h>
//我无法理解，就是根据go语言改成c的风格，逻辑，变量一个都没有变
int main() {
	int i, j, year, n, w, temp;
	scanf("%d %d",&year,&n);
	const int max = 10000,length = 4;
	int sli[length];
	for (i = year; i < max; i++) {
		temp = i;
		for (j = 0; j < length; j++) {
			sli[j] = temp % 10;
			temp /= 10;
		}

		temp = length;
		for (j = 0; j < length - 1; j++) {
			for (w = j + 1; w < length; w++) {
				if (sli[w] == sli[j]) {
					--temp;
					break;
				}
			}
		}

		if (temp == n) {
			break;
		}
	}
	
	printf("%d %04d",i - year,i);
    return 0;
}