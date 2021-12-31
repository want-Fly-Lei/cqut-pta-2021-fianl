#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 101
#define size 1001

void getLow(char * a){//תСд
	int len = strlen(a);
	int i;
	for(i = 0; i < len; i++) {
		if(a[i] >= 'A' && a[i] <= 'Z') {
			a[i] += 32;
		}
	}
}

int main(){
	int t,n,i,j,count,k;
	scanf("%d",&t);
	char str[size][MAXSIZE];
	for(i = 0; i < t;i++){
		scanf("%d\n",&n);
		count = 0;
		for(j = 0; j < n; j++){
			memset(str[j],'\0',MAXSIZE);
			gets(str[j]);
			getLow(str[j]);
		}
		for(j = 0; j < n - 1; j++){
			if(str[j][0] == '\0') {
				continue;
			}
			for( k = j + 1; k < n; k++) {
				if(!strcmp(str[j],str[k])) {
					str[k][0] = '\0';
				}
			}
		}
		for(j = 0; j < n; j++) {
			if(str[j][0] != '\0'){
				++count;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}