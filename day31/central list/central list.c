#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 1024
typedef struct stack {
    int len;
    int arr[MAXSIZE];
}STACK;

int main() {
   STACK st;
   st.len = -1;
   int temp;
   bool flag = false;
   while (scanf("%d,",&temp) == 1) {
       st.arr[++st.len] = temp;
   }
   register int i = 0, len = st.len;

    while (i < len) {
        if (st.arr[i++] != st.arr[len--]) {
            flag = true;
            break;
        }
    }
    if (flag) {
        puts("No");
    } else {
        puts("Yes");
    }
    return 0;
}