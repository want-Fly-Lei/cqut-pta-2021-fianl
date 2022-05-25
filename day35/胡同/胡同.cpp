#include <cstdio>
#include <stack>
using namespace std;
#define MAXSIZE 10
int n;
int ans;
int outputLink[11];

typedef struct Stack {
	int data[MAXSIZE];
	int top;
};

void dfs(int x, int inputLink[], Stack input, Stack output) {
	if (output.top == n - 1) {
		int judge = 1;
		for (int i = 0; i <= output.top; i++) {
			if (outputLink[i] != output.data[i]) {
				judge = 0;
				break;
			}
		}

		if (judge) {
			ans = 1;
		}
		return;
	}

	if (x <= n - 1) {
		input.data[++input.top] = inputLink[x++];
		dfs(x, inputLink, input, output);
		--x;
		--input.top;
	}

	if (input.top >= 0) {
		output.data[++output.top] = input.data[input.top--];
		dfs(x, inputLink, input, output);
		--output.top;
		++input.top;
	}
}

int main() {
	int T, i;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		int inputLink[n];
		for (i = 0; i < n; i++) {
			scanf("%d",&inputLink[i]);
		}

		for (i = 0; i < n; i++) {
			scanf("%d",&outputLink[i]);
		}

		Stack input;
		input.top = -1;
		Stack output;
		output.top = -1;
		ans = 0;
		dfs(0, inputLink, input, output);

		if (ans) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
}
