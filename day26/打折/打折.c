#include<stdio.h>
int main() {
    int price,discount;
    scanf("%d %d",&price,&discount);
    printf("%.2lf",price * discount / 10.0);
    return 0;
}