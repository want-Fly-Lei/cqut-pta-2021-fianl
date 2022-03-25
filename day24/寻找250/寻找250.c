#include<stdio.h>
int main() {
    int i, temp;
    for(i = 0; 1; i++) {
        scanf("%d",&temp);
        if(temp == 250) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}