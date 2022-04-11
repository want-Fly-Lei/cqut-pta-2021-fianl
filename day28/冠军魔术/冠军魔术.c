#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b, x, sum;
    scanf("%d%d", &a, &b);
    if (b % 2 == 0) { //通过奇偶判断最后是硬币还是纸牌
        x = 0;
    } else{
        x = 1;
    }
    sum = a * pow(2, b / 2); //无论最后是纸牌还是硬币，数量都是一样的
    printf("%d %d\n", x, sum);
    return 0;
}
