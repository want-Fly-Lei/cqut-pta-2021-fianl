#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int num1, num2, len;
    char str[11];
    scanf("%d %d",&num1,&num2);
    if(num1 == 0 || num2 == 0) {
        putchar('0');
        return 0;
    }
    
    sprintf(str,"%lld",(long long)num1 * num2);
    len = strlen(str);
    int flag = 1;
    for(num1 = len -1; num1 >= 0; num1--) {
        if(flag == 1 && str[num1] == '0') {
            
        } else {
           flag = 0;
           putchar(str[num1]); 
        }
        
    }
    return 0;
}