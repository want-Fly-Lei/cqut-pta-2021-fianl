#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define N  1000010

unsigned int dp[N];

int main() {
    string s;
    unsigned int i, t, maxlen, cnt;
    while (getline(cin,s)) {
        maxlen = 0, cnt = 1;
        stack<unsigned int> stk;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (stk.size()) {
                t = stk.top();
                stk.pop();

                if (t > 0) {
                    dp[i] = dp[t - 1];
                }
                    
                dp[i] += i - t + 1;

                if (dp[i] == maxlen) {
                    ++cnt;
                } else if (dp[i] > maxlen) {
                    maxlen = dp[i], cnt = 1;
                }
            }
        }
        printf("%u %u\n",maxlen, cnt);
    }
}
