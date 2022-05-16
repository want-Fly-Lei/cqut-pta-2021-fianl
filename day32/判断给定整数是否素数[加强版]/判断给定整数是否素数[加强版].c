#include <stdio.h>
#include <math.h>
char * ok = " is prime number.";
char * no =  " is not prime number.";

int main() {
    int num;
    scanf("%d",&num);
    printf("%d",num);
    if (num < 2) {
        puts(no);
        return 0;
    }
    register int i, len = sqrt(num);
    for (i = 2; i <= len; i++) {
        if (num % i == 0) {
            puts(no);
            return 0;
        }
    }
    puts(ok);
    return 0;
}