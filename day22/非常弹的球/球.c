#include<stdio.h>

//根据公式所知cosa * sina 最大时候最大，所以应该是45,位移是v^2 / g
int main() {
	const double a = 9.8, energy = 100,rate = 100;
	double v2,sum = 0;
	int weight,tran;
	scanf("%d %d",&weight,&tran);
	v2 = energy * 2 * rate / weight;
	while(v2 > 0.000001) {
		sum += v2 / a;
		v2 -= v2 * (tran * 1.0 / 100);
	}
	printf("%.3lf\n",sum);
	return 0;
}