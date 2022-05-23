#include <stdio.h>
#define MAXN 10005
int a[MAXN];
int b[MAXN];
int l, r, k;
unsigned long long ans = 0;

int Merge(int low, int mid, int high) {
	l = k = low;
	r = mid + 1;
	while (l <= mid && r <= high) {
		if (a[l] > a[r]) {
			b[k++] = a[r++];
			ans += (mid - l + 1);
		} else {
			b[k++] = a[l++];
		}
			
	}

	while (l <= mid) {
		b[k++] = a[l++];
	}
		
	while (r <= high) {
		b[k++] = a[r++];
	}
		
	int i;
	for (i = low; i <= high; i++) {
		a[i] = b[i];
	}
}

int mergesort(int low, int high) {
	if (low >= high) {
		return 0;
	}
		
	int mid = (low + high) / 2;
	mergesort(low, mid);
	mergesort(mid + 1, high);
	Merge(low, mid, high);
}

int main() {
	int n, i;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	mergesort(0, n - 1);
	printf("%llu",ans);
	return 0;
}