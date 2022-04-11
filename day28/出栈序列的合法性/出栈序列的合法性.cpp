#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int contrast(int *out, int M, int N) {
    int In[1002] = {0}, top = 0;
    int i, j = 0;
    for (i = 0; i < N; i++) {
        if (In[top] < out[i]) {
            while (In[top] < out[i]) {
                In[++top] = ++j;
            }
            if (top > M) {
                return 0;
            }
            --top;
        } else if (out[i] < In[top]) {
            return 0;
        } else {
            --top;
        }
    }
    return 1;
}

int main() {
    int M, N, i, j, K;
    int Out[1001] = {0};
    scanf("%d %d %d", &M, &N, &K);
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &Out[j]);
        }

        if (contrast(Out, M, N)) {
            puts("YES");
        } else {
            puts("NO");
        }  
    }

    return 0;
}