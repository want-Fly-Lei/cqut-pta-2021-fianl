#include<stdio.h>
#include<stdlib.h>
long long a[1000000];//保存要求的这么多项
int i;

void pell(){
	a[1] = 1;
	a[2] = 2;
	for (i = 3; i <= 1000000; i++) {
		a[i] = 2 * a[i - 1] + a[i - 2];
		a[i] %= 32767;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int * k = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++){
		scanf("%d", &k[i]);
	}
	pell();

	for (i = 0; i < n; i++) {
        printf("%lld\n", a[k[i]]);
    }
	free(k);
	return 0;
}