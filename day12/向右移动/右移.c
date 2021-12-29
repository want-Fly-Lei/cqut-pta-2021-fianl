#include<stdio.h>
#include<string.h>
int main(){
	long long n,i;
    
	scanf("%lld ",&n);
	
    char ch[1001];
	
    gets(ch);
	long long len = strlen(ch);
     n %= len;//注意这一句话不能省略，不然如果n大于len就不行了
	for(i = 0; i < len; i++) {
		printf("%c",ch[(len + i - n) % len]);
	}
	return 0;
}