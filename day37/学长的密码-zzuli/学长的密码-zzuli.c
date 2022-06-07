#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 102

int myFgets(char * ch) {
    fgets(ch,MAXSIZE,stdin);
    int len = strlen(ch);

    if (ch[len - 1] == '\n') {
        ch[--len] = '\0';
    }
    return len;
}

int main() {
    int n, m, i, j, k, len1, len2, count;
    bool flag;
    scanf("%d\n",&n);
    char chs1[MAXSIZE], chs2[MAXSIZE];
    for (i = 0; i < n; i++) {
        len1 = myFgets(chs1);
        scanf("%d\n",&m);
        count = 0;

        for (j = 0; j < m; j++) {
            len2 = myFgets(chs2);
            if (len1 != len2) {
                continue;;
            }

            flag = true;
            for (k = 0; k < len1; k++) {
                if (chs1[k] != '*'  && chs1[k] != chs2[k]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ++count;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}