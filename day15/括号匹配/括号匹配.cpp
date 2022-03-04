#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
    string str;
    int i, n, len, count;
    bool flag;
    while(cin>>str) {
        len = str.size();
        flag = true;
        count = 0;
        n = 0;
        for(i = 0; i < len; i++) {
            if(str[i] == '(') {
                ++count;
            } else {
                --count;
            }
            if(count < 0) {
                flag = false;
                if(count < n) {
                    n = count;
                }
            }
        }
        if(flag && count == 0) {
            printf("Match");
        } else if(flag) {
            printf("%d\n",count);
            cout<<str;
            for(i = 0; i < count; i++) {
                printf(")");
            }
        } else {
            if(n < count) {
                printf("%d\n",count - 2 * n);
                for(i = 0; i > n; i--) {
                    printf("(");
                }
                cout<<str;
                for(i = 0; i > n - count; i--) {
                    printf(")");
                }
            } else {
                printf("%d\n",n - 2 * count);
                for(i = 0; i > count; i--) {
                    printf("(");
                }
                cout<<str;
                for(i = 0; i > count - n; i--) {
                    printf(")");
                }
            }
        }
        printf("\n");
    }
    return 0;
}