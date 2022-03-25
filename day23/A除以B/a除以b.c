#include<stdio.h>
int main() {
    int a, b;
    scanf("%d %d",&a,&b);
    if(b > 0) {
        printf("%d/%d=%.2lf\n",a,b,a * 1.0 / b);
    } else if(b == 0) {
        printf("%d/0=Error\n",a);
    } else {
        printf("%d/(%d)=%.2lf\n",a,b,a * 1.0 / b);
    }
    return 0;
}