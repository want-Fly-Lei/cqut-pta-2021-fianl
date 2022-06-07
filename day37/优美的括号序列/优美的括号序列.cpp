#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string input;

    while (cin >> input) {
        stack<char> st;
        bool perfect = true;
        for (char ch : input) {
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.empty()) {
                    perfect = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }

        if (perfect) {
            perfect = st.empty();
        }
        if (perfect) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
