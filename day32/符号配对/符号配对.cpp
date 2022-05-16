#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXSIZE 500000

int main() {
    char a[MAXSIZE] = {0};
    int stack[205] = {0};
    int h = 0, n, i, flag;
    while (true) {
        cin.getline(a, MAXSIZE);
        if (strcmp(a, ".") == 0) {
            break;
        }
            
        n = strlen(a);
        flag = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == '{' || a[i] == '(' || a[i] == '[') {
                stack[h] = a[i];
                ++h;
            } else if (a[i] == '/' && i + 1 < n && a[i + 1] == '*') {
                stack[h++] = a[i];
                stack[h++] = a[++i];
            } else if (a[i] == '}' || a[i] == ')' || a[i] == ']')  {
                if (h == 0) {
                    puts("NO");
                    printf("?-%c", a[i]);
                    flag = 1;
                    return 0;
                } else {
                    if (a[i] == '}' && stack[h - 1] != '{') {
                        puts("NO");
                        if (stack[h - 1] == '*') {
                            puts("/*-?");
                        } else {
                            printf("%c-?", stack[h - 1]);
                        }
                        flag = 1;
                        return 0;
                    } else if (stack[h - 1] != '(' && a[i] == ')') {
                        puts("NO");
                        if (stack[h - 1] == '*') {
                            puts("/*-?");
                        } else {
                            printf("%c-?", stack[h - 1]);
                        }
                            
                        flag = 1;
                        return 0;
                    } else if (stack[h - 1] != '[' && a[i] == ']') {
                        puts("NO");
                        if (stack[h - 1] == '*') {
                            puts("/*-?");
                        } else {
                            printf("%c-?", stack[h - 1]);
                        }
                            
                        flag = 1;
                        return 0;
                    }
                }
                --h;
            } else if (a[i] == '*' && i + 1 < n && a[i + 1] == '/') {
                if (h == 0) {
                    puts("NO");
                    puts("?-*/");
                    flag = 1;
                    return 0;
                } else if (stack[h - 1] != '*') {
                    puts("NO");
                    printf("%c-?", stack[h - 1]);
                    flag = 1;
                    return 0;
                }
                h = h - 2;
                ++i;
            }
        }
    }

    if (h != 0) {
        puts("NO");
        if (stack[h - 1] == '*') {
            puts("/*-?");
        } else {
            printf("%c-?", stack[h - 1]);
        }
            
        return 0;
    } else {
        puts("YES");
    }
        
    return 0;
}
