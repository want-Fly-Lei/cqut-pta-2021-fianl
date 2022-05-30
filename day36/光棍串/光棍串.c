#include <stdio.h>
#include <string.h>
#define LEN 6
#define MAXSIZE 52
char chs[MAXSIZE];

int main() {
    int n, i, j, k, len, count;
    scanf("%d\n",&n);
    for (i = 0; i < n; i++) {
        fgets(chs,MAXSIZE,stdin);
        len = strlen(chs);
        if (chs[len - 1] == '\n') {
            chs[--len] = '\0';
        }
        count = 0;
        for (j = 0; j < len - LEN + 1; j++) {//记得遍历的时候加一个1，不然出错
            if (count == LEN) {
                break;
            } else if(chs[j] != '1') {
                continue;
            }
            for (k = j; j < len; k++) {
                if (chs[k] == '1') {
                    ++count;
                } else if (chs[k] != ' ') {
                    count = 0;
                    j = k;
                    break;
                }
                
                if (count == LEN) {
                    break;
                }
            }
            
        }
        if (count == LEN) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}