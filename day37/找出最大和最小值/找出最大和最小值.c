#include <stdio.h>

int main() {
    int n, i, min, max, temp;
    scanf("%d",&n);
    scanf("%d",&temp);
    max = min = temp;
    while(--n) {
        scanf("%d",&temp);
        if (temp > max) {
            max = temp;
        } else if (temp < min) {
            min = temp;
        }
    }
    printf("%d\n%d",max,min);
    return 0;
}