#include<stdio.h>
#include<math.h>
int isOk(unsigned int a){//判断是否是素数
    if(a == 1) {
        return 0;
    }
    int i,j;
    j = sqrt(a);
    for( i = 2; i <= j; i++) {
        if(a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isRight(unsigned int a) {//判断是否对称
    unsigned int com1,com2;
   com1 = a;
   com2 = 0;
   while(com1 > 0) {
       com2 = com2 * 10 + com1 % 10;
       com1 /= 10;
   }
    if(com2 == a) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    unsigned int temp;
    while(scanf("%u",&temp) != EOF) {
        if(temp > 99999) {
            printf("No\n");
            continue;
        }
        if(isOk(temp) && isRight(temp)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}