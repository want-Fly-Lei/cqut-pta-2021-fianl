#include<stdio.h>
#include<string.h>
#include<math.h>

int isOk(long long num){
    if(num < 2) {
        return 0;
    }
    int i;
    for(i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int L,K;
    scanf("%d %d\n",&L,&K);
    int i,j;
    char str[1001];
    gets(str);
    long long sum;
    for(i = 0; i <= L - K; i++) {
        sum = str[i] - '0';
        for(j = i + 1; j < i + K;j++) {
            sum = sum * 10 + str[j] - '0';
        }
        if(isOk(sum)) {
            //printf("%lld",sum);
            for(j = i; j < i + K; j++) {
                printf("%c",str[j]);
            }
            return 0;
        }
    }
    printf("404");
    return 0;
}