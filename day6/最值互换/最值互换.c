#include<stdio.h>
#define SIZE 400
int main(){
	int m,n,i,minidex,maxindex,temp;
	int arr[SIZE];
	
	while(scanf("%d %d",&m,&n) != EOF) {
		minidex = maxindex = 0;
		scanf("%d",&arr[0]);
			
		for(i = 1; i < m * n; i++) {
			scanf("%d",&temp);
			if(temp > arr[maxindex]) {
				maxindex = i;
			} if(temp < arr[minidex]) {
				minidex = i;
			}
			arr[i] = temp;
		}
		if(minidex != maxindex) {
			arr[maxindex] ^= arr[minidex];
			arr[minidex] ^= arr[maxindex];
			arr[maxindex] ^= arr[minidex];
		}
		for(i = 0; i < m * n; i++) {
			printf("%d",arr[i]);
			if(i % n != n - 1) {
				printf(" ");
			} else  {
				printf("\n");
			}
		}
	}
	return 0;
}