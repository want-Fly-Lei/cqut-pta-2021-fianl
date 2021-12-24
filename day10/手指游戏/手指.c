#include<stdio.h>
#include<string.h>
#define SIZE 21
int main(){
    char * finger[5] = {"thumb","forefinger","middle finger","third finger","little finger"};
    int T;
    scanf("%d\n",&T);
    int i,index,j;
    char son[SIZE],father[SIZE];
    char temp;
    for(i = 0; i < T; i++) {
        //清空字符串
        memset(son,'\0',SIZE);
        memset(father,'\0',SIZE);
        index = 0;
        temp = getchar();
        while(temp != ',') {
                son[index] = temp;
            ++index;
            temp = getchar();
        }
        index = 0;
        temp = getchar();
        while(temp != '\n') {
                 father[index] = temp;
            ++index;
            temp = getchar();
        }
        for( j = 0; j < 5; j++) {
            if(strcmp(finger[j],son) == 0) {
                if( strcmp(finger[(j + 1) % 5],father) == 0) {
                    printf("Win\n");
                } else if(strcmp(finger[(j + 4) % 5],father) == 0) {
                    printf("Lose\n");
                } else {
                    printf("Draw\n");
                }
                break;
            }
        }
        printf("Draw\n");
    }
    return 0;
}