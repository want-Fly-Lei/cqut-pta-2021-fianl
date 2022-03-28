#include<stdio.h>
#include<string.h>
#define SIZE 40
char zhijin[SIZE], num1[SIZE], num2[SIZE], res[SIZE];
int main() {
    scanf("%s %s %s",zhijin,num1, num2);
    int len1 = strlen(num1), len2 = strlen(num2), len3 = strlen(zhijin);
    int i, temp1, temp2, temp3, temp4 = 0;

    int len = len1 > len2 ? len1 : len2;
    --len1;
    --len2;
    --len3;
    
    for(i = 0; i < len; i++) {
        if(len3 < 0 || zhijin[len3] == '0') {
            temp3 = 10;
        } else {
            temp3 = zhijin[len3] - '0';
        }
        --len3;
        if(len1 >= 0) {
            temp1 = num1[len1] - '0';
        } else {
            temp1 = 0;
        }
        --len1;
        if(len2 >= 0) {
            temp2 = num2[len2] - '0';
        } else {
            temp2 = 0;
        }
        --len2;
        if(temp1 + temp2 + temp4 >= temp3) {
            res[i] = temp1 + temp2 + temp4 - temp3 + '0';
            temp4 = (temp1 + temp2 + temp4) / temp3;
            //考虑是否进位
            if(i == len - 1) {
                res[len] = temp4 + '0';
                res[len + 1] = '\0';
            }
        } else {
            res[i] = temp1 + temp2 + temp4 + '0';
            temp4 = 0;
        }
    }
    len = strlen(res);
    //删除多余开头多余的
    for(i = len - 1; i >= 0; i--) {
        if(res[i] == '0') {
            --len;
        } else {
            break;
        }
    }
    //防止结果是0不输出
    if( len == 0) {
        putchar('0');
    } else {
        for(i = len - 1; i >= 0; i--) {
            putchar(res[i]);
        }
    }
    
    putchar('\n');
    return 0;
}