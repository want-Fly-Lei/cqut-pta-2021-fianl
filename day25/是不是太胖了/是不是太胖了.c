#include<stdio.h>
int main() {
    int weight;
    scanf("%d",&weight);
    weight -= 100;
    printf("%.1lf",weight * 0.9 * 2);
    return 0;
}