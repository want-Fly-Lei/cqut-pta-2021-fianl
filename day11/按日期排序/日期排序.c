#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 101
#define s 10

int isSwap(char* si,char* sj){
    char tempa[8],tempb[8];
    int i;
    //你这日期格式，我tm一直以为是日/月/年，结果是月/日/年，害得我一直出错，我*****
   for(i = 0; i < 4; i++) {
      tempa[i] = si[6 + i];
      tempb[i] = sj[6 + i];
   }

   for(;i < 6;i++) {
       tempa[i] = si[i - 4];
       tempb[i] = sj[i - 4];
   }
   for( ; i < 8; i++) {
       tempa[i] = si[i -3];
       tempb[i] = sj[i - 3];
   }
   //strcmp作为比较不靠谱
//    if(strcmp(tempa,tempb) > 0) {
//        return 1;
//    } else {
//        return 0;
//    }
    for(i = 0; i < 8; i++) {
        if(tempa[i] > tempb[i]){
            return 1;
        } else if(tempa[i] < tempb[i]) {
            return 0;
        }
    }
    return 0;
}

int main(){
    char str[SIZE][s];
    char temp;
    int len = 0;
   while(gets(str[len])) {
       //puts(str[len]);
       ++len;
   }
   int i,j,k;
   for(i = 0; i < len - 1; i++) {
       for(j = i + 1; j < len; j++) {
           if(isSwap(&str[i][0],&str[j][0])) {
               for(k = 0; k < s; k++) {
                   if((k == 2) && (k == 5)){
                       continue;
                   }
                   temp = str[i][k];
                   str[i][k] = str[j][k];
                   str[j][k] = temp;
               }
           }
       }
   }
   for(i = 0; i < len; i++){
       for(j = 0; j < s; j++){
           printf("%c",str[i][j]);
       }
       printf("\n");
   }
    return 0;
}