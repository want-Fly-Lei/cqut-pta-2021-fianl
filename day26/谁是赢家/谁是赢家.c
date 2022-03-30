#include<stdio.h>
#define SIZE 3
int main() {
    int palyer1, player2;
    scanf("%d %d",&palyer1,&player2);
    int flag1 = 0,flag2 = 0, i, temp;
    for(i = 0; i < SIZE; i++) {
        scanf("%d",&temp);
        if(temp == 0) {
            ++flag1;
        } else {
            ++flag2;
        }
    }
    if(flag1 == 0) {
        printf("The winner is b: %d + 3",player2);
    } else if(flag2 == 0) {
        printf("The winner is a: %d + 3",palyer1);
    } else {
        if(flag1 + palyer1 > flag2 + player2) {
            printf("The winner is a: %d + %d",palyer1,flag1);
        } else {
            printf("The winner is b: %d + %d",player2,flag2);
        }
    }
    return 0;
}