#include<stdio.h>
#include<algorithm>
#define SIZE 100
using namespace std;

int arr[SIZE];
int findNum[SIZE];
int main(){
    int n,n1,m,i,j;
	int left,right;
    while(scanf("%d",&n) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        scanf("%d",&n1);
        for(i = 0; i < n1; i++ ) {
            scanf("%d",&findNum[i]);
        }
		for(i = 0; i < n; i++) {
			printf("%d",arr[i]);
			if(i != n - 1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
		for(i = 0; i < n1; i++) {
			left = 0;
			right = n - 1;
			
			while(1){
				if(right < left) {
					printf("0");
					break;
				}
				j = (left + right) / 2;
				if(arr[j] == findNum[i]) {
					printf("%d",j + 1);
					break;
				} else if(arr[j] > findNum[i]) {
					right = j - 1;
				} else {
					left = j + 1;
				}
			}
			if(i != n1 - 1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
    }
    return 0;
}