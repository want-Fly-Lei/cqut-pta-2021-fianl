#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 402
int arr[MAXSIZE][MAXSIZE];
int  n, m, x, y;

bool isOk(int x1, int y1) {
    if (x1 > n || x1 <= 0 || y1 <= 0 || y1 > m) {
        return false;
    }
    return true;
}

void findRoad(int num1, int num2) {
    int temp = arr[num1][num2] + 1;
    int nowX, nowY;

    //上2右1
    nowX = num1 - 2, nowY = num2 + 1;
    if (nowX > 0 && nowY <= m) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //上1右2
    nowX = num1 - 1, nowY = num2 + 2;
    if ( nowX > 0 && nowY <= m) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //下1右2
    nowX = num1 + 1, nowY = num2 + 2;
    if (nowX <= n && nowY <= m) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //下2右1
    nowX = num1 + 2, nowY = num2 + 1;
    if (nowX <= n && nowY <= m) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //下2左1
    nowX = num1 + 2, nowY = num2 - 1;
     if (nowX <= n && nowY > 0) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //下1左2
    nowX = num1 + 1, nowY = num2 - 2;
     if (nowX <= n && nowY > 0) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //上1左2
    nowX = num1 - 1, nowY = num2 - 2;
     if (nowX > 0 && nowY > 0) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }

    //上2左1
    nowX = num1 - 2, nowY = num2 - 1;
     if (nowX > 0 && nowY > 0) {
        if (arr[nowX][nowY] == -1) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        } else if (arr[nowX][nowY] > temp) {
            arr[nowX][nowY] = temp;
            findRoad(nowX, nowY);
        }
    }
}

int main() {
    register int i, j;
    
    scanf("%d %d %d %d",&n,&m,&x, &y);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            arr[i][j] = -1;
        }
    }
    arr[x][y] = 0;
    findRoad(x,y);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%-5d",arr[i][j]);
        }
        putchar('\n');
    }
    return 0;
}