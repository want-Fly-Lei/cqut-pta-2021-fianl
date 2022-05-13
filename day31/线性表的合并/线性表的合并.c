#include <stdio.h>
#define MAXSIZE 10001
#define MY_NUM -100//定义成一个特殊的数字就行了
int main() {
    int m, n, temp;
    register i, j;
    int arr[MAXSIZE];
    scanf("%d",&m);
    while (i < m ) {
        scanf("%d",&arr[i++]);
    }
    scanf("%d",&n);
    n += m;
    while (i < n) {
        scanf("%d",&arr[i++]);
    }
    for (i = 0; i < n -1; i++) {
        if (arr[i] == MY_NUM) {
            continue;
        }
        
        for (j = i + 1; j < n; j++) {
            if(arr[j] != MY_NUM && arr[i] == arr[j]) {
                arr[j] = MY_NUM;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] != MY_NUM) {
           printf("%d ",arr[i]); 
        }
    }
    return 0;
}