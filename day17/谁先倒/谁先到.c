#include<stdio.h>
int main(){
    int AMaxCount,AGuess,ANum,BMaxCount,BGuess,BNum;
    scanf("%d %d",&AMaxCount,&BMaxCount);
    int tempA = AMaxCount, tempB = BMaxCount;
    int i, n;
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        if(AMaxCount < 0 || BMaxCount < 0) {
            continue;
        }
        scanf("%d %d %d %d",&AGuess,&ANum,&BGuess,&BNum);
        if(ANum == BNum) {

        }else if(AGuess + BGuess == ANum) {
            --AMaxCount;
        } else if(AGuess + BGuess == BNum) {
            --BMaxCount;
        }
    }
    if(AMaxCount >= 0) {
        printf("B\n%d\n",tempA - AMaxCount);
    } else {
        printf("A\n%d\n",tempB - BMaxCount);
    }
    return 0;
}