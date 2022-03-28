#include<stdio.h>
char * state[] = {"You are wan mei!","You are tai shou le!","You are tai pang le!"};
int main() {
    int n, i;
    scanf("%d",&n);
    int weight, height;
    int standard;
    for(i = 0; i < n; i++) {
       scanf("%d %d",&height,&weight);
        standard = (height - 100) * 9 * 2;
        weight *= 100;
        if(weight <= standard * 9) {
            printf("%s\n",state[1]);
        } else if(weight >= standard * 11) {
            printf("%s\n",state[2]);
        } else {
            printf("%s\n",state[0]);
        }
    }
    return 0;
}