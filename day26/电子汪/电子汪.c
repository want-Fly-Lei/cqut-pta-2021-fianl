#include<stdio.h>
char * wang = "Wang!";
int main() {
    int num1, num2;
    scanf("%d %d",&num1,&num2);
    num2 += num1;
    for(num1 = 0; num1 < num2; num1++) {
        fputs(wang,stdout);
    }
    return 0;
}