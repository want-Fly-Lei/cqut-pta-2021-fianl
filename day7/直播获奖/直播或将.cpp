#include <iostream>
#include <cstdio>
using namespace std;
int a[601] = {0}, n, w;
int main(void)
{
	int p = 0;
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
		p = i * w / 100;
		if (p == 0)
			p++;
		for (int j = 600; j >= 0; j--)
		{
			if (a[j] >= 1)
			{
				p -= a[j];
			}
			if (p <= 0)
			{
				if (i == n)
				{
					printf("%d", j);
					break;
				}
				else
				{
					printf("%d ", j);
					break;
				}
			}
		}
	}
	return 0;
}