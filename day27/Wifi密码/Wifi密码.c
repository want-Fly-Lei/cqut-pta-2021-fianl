#include<stdio.h>
int main() {
    int i, j, m, n;
    const int len = 4;
    char temp[4];
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < len; j++) {
            //scanf("%c-%c",&temp1,&temp2);
            scanf("%s",temp);
            if(temp[2] == 'T') {
                putchar('1' + temp[0] - 'A');
            }
        }
    }
    return 0;
}