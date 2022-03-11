#include<stdio.h>
const int MAX = 100000;
struct Point {
	long long x, y;
	bool judge(Point a, Point b) {
		return (b.y - a.y)*(x - b.x) >= (b.x - a.x)*(y - b.y);
	}
}points[MAX];
bool build[MAX];
int runningarry[MAX];
int main() {
	int n;
	scanf("%d", &n);
	int i, pre = 0;
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", &points[i].x, &points[i].y);
		build[i] = false;
		while (pre >= 2 && points[i].judge(points[runningarry[pre - 2]], points[runningarry[pre - 1]])) pre--;
		build[runningarry[pre - 1]] = true;
		runningarry[pre++] = i;
	}
	int count = 0;
	for (i = 1; i < n; i++) if (build[i]) count++;
	printf("%d\n", count);
	return 0;
}