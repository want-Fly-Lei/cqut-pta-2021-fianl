#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#define MAXSIZE 1024
#define YES puts("Yes");
#define NO puts("No");

//我真的觉得你为什么要用中文的（）麻烦，而且在liunx编码还是utf-8，真烦,这可恶的编码

typedef struct stack {
    char chs[MAXSIZE];
    int top;
}STACK;

int main() {
    int n, i, j, len;
    wchar_t str[MAXSIZE];
    scanf("%d\n",&n);
    STACK st;
    bool flag;
    wchar_t wch;
    for (i = 0; i < n; i++) {
        //fgets(str,MAXSIZE,stdin);
        //len = strlen(str) - 1;
        wch = getwchar();
        len = 0;
        while(wch != '\n') {
            str[len++] = wch;
            wch = getwchar();
        }
        if (len % 2 != 0) {
            NO
            continue;
        }
        st.top = -1;
        //puts(str);
        flag = false;
        for (j = 0; j < len; j++) {
            switch (str[j]) {
            case '{' : {
                st.chs[++st.top] = (char)1;
                break;
            }
            case '[' : {
                st.chs[++st.top] = (char)2;
                break;
            }   
            // case '(': {
            //     st.chs[++st.top] = (char)3;
            //     break;
            // }
            case '（': {
                st.chs[++st.top] = (char)4;
                break;
            }
            case '}' : {
                if (st.chs[st.top--] != 1 || st.top < -1) {
                    flag = true;
                }
                break;
            }
            case ']' : {
                if (st.chs[st.top--] != 2 || st.top < -1) {
                    flag = true;
                }
                break;
            }
            // case ')': {
            //     if (st.chs[st.top--] != 3 || st.top < -1) {
            //         flag = true;
            //     }
            //     break;
            // }
            case '）': {
                if (st.chs[st.top--] != 4 || st.top < -1) {
                    flag = true;
                }
                break;
            }
//            default: {
//                NO
//                break;
//            }
            }
        }
        if (!flag && st.top == -1) {
            YES
        } else {
            NO
        }
    }
    
    return 0;
}
