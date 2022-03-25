#include<stdio.h>
int main() {
    int year,month,day;
    scanf("%d-%d-%d",&month,&day,&year);
    printf("%04d-%02d-%02d\n",year,month,day);
    return 0;
}