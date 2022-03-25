#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, vis[N][N], sx, sy, ex, ey;
double s[N][N], d[N][N], mi;
const double PI = sqrt(2) - 1;
int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};

struct T{
    int x, y;
} a, b, p;

int cross(T a, T b, T p){
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

void spfa(){
    memset(vis, 0, sizeof vis), memset(d, 0x7f, sizeof d);
    a = {sx, sy}, b = {ex, ey};
    d[sx][sy] = s[sx][sy];
    queue<T> Q;
    Q.push(a);
    while (!Q.empty()){
        int x = Q.front().x, y = Q.front().y;
        Q.pop();
        vis[x][y] = 0;

        for (int i = 0; i < 8; i++){
            double w = 0;
            p.x = x + dir[i][0], p.y = y + dir[i][1];
            if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) {
                continue;
            }
            if (cross(a, b, p) > 0 || p.x == ex && p.y == ey){
                w = s[p.x][p.y];
                if (i > 3) {
                    w = w + (s[x][y] + s[p.x][p.y]) * PI;
                }
                    
                if (d[p.x][p.y] > d[x][y] + w){
                    d[p.x][p.y] = d[x][y] + w;
                    if (!vis[p.x][p.y]) {
                        Q.push(p), vis[p.x][p.y] = 1;
                    }    
                }
            }
        }
    }
    mi += d[ex][ey];
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf",&s[i][j]);
        }
    }
        
    scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
    mi = -s[ex][ey] - s[sx][sy];
    spfa();
    swap(ex, sx), swap(ey, sy);
    spfa();
    printf("%.2f", mi);
    return 0;
}
