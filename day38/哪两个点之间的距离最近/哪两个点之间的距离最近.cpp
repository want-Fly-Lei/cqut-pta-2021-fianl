#include <stdio.h>
#include <math.h>

typedef struct point{
    double x, y;
}Point;


int main() {
    int n, i, j;
    scanf("%d",&n);
    Point p[n];
    for (i = 0; i < n; i++) {
        scanf("%lf %lf",&p[i].x, &p[i].y);
    }
    double distant = 99999999, temp;
    int min1 = 0, min2 = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            temp = pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2);
            if (temp < distant) {
                min1 = i;
                min2 = j;
                distant = temp;
            }
        }
    }
    if (p[min1].x + p[min1].y  > p[min2].x + p[min2].y) {
        min1 ^= min2;
        min2 ^= min1;
        min1 ^= min2;
    }
    printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf",p[min1].x, p[min1].y, p[min2].x, p[min2].y, sqrt(distant));
    return 0;
}