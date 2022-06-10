#include <stdio.h>

int main() {
    int temp;
    int count = 0;
    while(scanf("%d",&temp) != EOF) {
        if (temp % 2 == 0) {
            ++count;
            if (count == 1) {
                printf("%d",temp);
            } else {
               printf(" %d",temp); 
            }
            
        }
    }
    if (count == 0) {
        puts("None");
    }
    return 0;
}