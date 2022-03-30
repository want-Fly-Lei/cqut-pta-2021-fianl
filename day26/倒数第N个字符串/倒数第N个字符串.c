#include<stdio.h>

#define SIZE 26
int main() {
    long i, j, m, n;
    scanf("%ld %ld",&m,&n);
    unsigned long long sum = 1;
    for(i = 0; i < m; i++) {
        sum = sum * SIZE;
    }
    sum -= n;
    char str[40];
    str[m] = '\0';
    while(m > 0) {
        str[--m] =  sum % SIZE + 'a';
        sum /= SIZE;
    }
    
    puts(str);
    return 0;
}