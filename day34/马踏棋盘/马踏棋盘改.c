#include <stdio.h>

int n, m, x, y, ans[401][401];
int mv[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

struct node {
    int x, y, step;
} que[1000001];

int main() {
    scanf("%d %d %d %d",&n, &m,&x, &y);
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            ans[i][j] = -1;
        }
    }
    
    int head = 0, tail = 1;
    que[head].x = x;
    que[head].y = y;
    que[head].step = 0;
    ans[x][y] = 0;
    while (head < tail) {
        int x, y;
        for (i = 0; i < 8; i++) {
            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            if (x > 0 && y > 0 && x <= n && y <= m && ans[x][y] == -1) {
                que[tail].x = x;
                que[tail].y = y;
                que[tail].step = que[head].step + 1;
                ans[x][y] = que[tail++].step;
            }
        }
        ++head;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%-5d",ans[i][j]);
        }
        putchar('\n');
    }
}
