#include<stdio.h>
#include<string.h>
#define size 101
int main(){
    char str[size];
    int i,len,flag;
    while(gets(str)){
        len = strlen(str);
        while (1){
            flag = 0;
            //防止是奇数个
            if(len %2 != 0) {
                break;
            }
          for(i = 0; i <= len/2; i++){
              if(str[i] != str[len - i - 1]) {
                  flag = 1;
                  break;
              }
          } 
          if(flag) {
              break;
          } else {
              len /= 2;
          }
        }
        printf("%d\n",len);
        memset(str,'\0',size);
    }
    return 0;
}