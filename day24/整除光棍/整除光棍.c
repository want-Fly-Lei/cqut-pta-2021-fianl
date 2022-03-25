#include<stdio.h>

int main() {
    int num, i, count = 0;
    scanf("%d",&num);
    int temp = 1;
    while(temp < num) {
        temp = temp * 10 +1;
        ++count;
    }
    //就像做除法那样就行了
    while(++count) {
        printf("%d",temp / num);
        temp %= num;
        if(temp == 0) {
            printf(" %d\n",count);
            break;
        }
        temp = temp * 10 +1;
    }
    return 0;
}