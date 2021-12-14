#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,t,i,j,conut = 0;
    int * m = (int *)malloc(sizeof(int) * 1000000);
    while(scanf("%d",&n),n!=0){
        scanf("%d",&t);
        j = t;
        if(n > 1) {
            for(i = 1; i < n; i++) {
                scanf("%d",&t);
                j ^= t;
            }
        }
    m[conut++] = j;
    }
    for(i = 0; i < conut; i++) {
        printf("%d\n",m[i]);
    }
    free(m);
    return 0;
}