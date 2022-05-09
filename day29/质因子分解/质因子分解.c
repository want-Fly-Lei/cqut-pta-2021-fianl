#include<stdio.h>
#include<math.h>
 
int isPrime(int n) {
    int flag = 1;
    int i;
    for(i=2; i<=sqrt(n); i++) {
        if(n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    int n, temp_n;
    int i, j;
    scanf("%d", &n);
    temp_n = n;
    i = 2;
    printf("%d=",n);
    while(1){
        if(isPrime(i) && (temp_n % i == 0)) {
            temp_n /= i;
            if(temp_n == 1) {
                printf("%d\n", i);
                break;
            }else {
                printf("%d*",i);
            } 
        }else  {
            ++i;
        }
    }
    return 0;
}