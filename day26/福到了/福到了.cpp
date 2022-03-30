#include<stdio.h>
#include<stdbool.h>

using namespace std;
int main() {
    char temp;
    int n, i, j;
    scanf("%c %d",&temp,&n);
    char arr[n][n];
    getchar();
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(getchar() != ' ') {
                arr[i][j] = temp;
            } else {
                arr[i][j] = ' ';
            }
        }
        getchar();
    }

    bool flag = true;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            if(arr[i][j] != arr[n -i - 1][n - j - 1]) {
                flag = false;
                break;
            }
        }
        if(flag == false) {
            break;
        }
    }

    if(flag) {
        printf("bu yong dao le\n");
    }

    for(i = n - 1; i >= 0; i--) {
        for(j = n -1; j >= 0; j--) {
            putchar(arr[i][j]);
        }
        putchar('\n');
    }
    return 0;
}