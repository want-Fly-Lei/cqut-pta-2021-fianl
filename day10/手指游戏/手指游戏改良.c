#include <stdio.h>
#include <string.h>
//其实怎么说了这个就是那个多了一个非法输入判定为draw而已真是好恶心，我觉得我那个代码写的贼棒
int main(){
    char *str[25] = {"thumb,thumb","thumb,forefinger", "thumb,middle finger","thumb,third finger","thumb,little finger",
                     "forefinger,thumb","forefinger,forefinger","forefinger,middle finger","forefinger,third finger","forefinger,little finger",
                     "middle finger,thumb","middle finger,forefinger","middle finger,middle finger","middle finger,third finger","middle finger,little finger",
                     "third finger,thumb","third finger,forefinger","third finger,middle finger","third finger,third finger","third finger,little finger",
                     "little finger,thumb","little finger,forefinger","little finger,middle finger","little finger,third finger","little finger,little finger"};
    int arr[25];
    int i,j;
    for(i = 0; i < 25; i++){
        if((i % 6 == 1) || (i == 20)) {
            arr[i] = 1;
        } else if((i % 6 == 5) || (i == 4)) {
            arr[i] = -1;
        } else {
            arr[i] = 0;
        }
    }
    int n;
    scanf("%d\n",&n);
    char temp[40];
    for(i = 0; i < n;i++) {
        memset(temp,'\0',40);
        gets(temp);
    for(j = 0; j < 25; j++) {
        if(strcmp(str[j],temp) == 0) {
            if(arr[j] == 1){
                printf("Win\n");
            } else if (arr[j] == -1){
                printf("Lose\n");
            } else {
                printf("Draw\n");
            }
            break;
        }
    }
    if(j == 25) {
        printf("Draw\n");
    }
    }
    return 0;
}