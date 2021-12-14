#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define buffer_size 100
int main(){
	char str[buffer_size];
	int i,len,j;
	while(gets(str) != '\0') {
		len = strlen(str);
		for(i = 0; i < len;i++) {
			if(str[i] != ' ') {
				if(str[i] <= 'z' && str[i] >= 'a') {
					str[i] -= 32;
				}
				for(j = i; j < len;j++) {
					if(str[j] == ' ' || j == len - 1) {
						i = j;
						break;
					}
				}
			}
		}
		puts(str);
	}
}
