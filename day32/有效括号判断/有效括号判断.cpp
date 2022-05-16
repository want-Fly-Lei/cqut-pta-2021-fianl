#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    register int i;
    int len = str.size();
    char temp;
    stack<char> st;
    bool flag = false;
    for (i = 0; i < len; i++) {
        temp = str[i];
        switch (temp){
        case '(': {
        }
        case '[': {
        }
        case '{': {
            st.push(temp);
            break;
        }
        case ')': {
            if (st.empty()) { //判断栈是否为空
                flag = true;
            } else if(st.top() != '(') {//判断上一个是否与之对应
                flag = true;
            } else {
                st.pop();//出栈
            }
            break;
        }
        case ']': {
            if (st.empty()) { //判断栈是否为空
                flag = true;
            } else if(st.top() != '[') {//判断上一个是否与之对应
                flag = true;
            } else {
                st.pop();//出栈
            }
            break;
        }
        case '}': {
            if (st.empty()) { //判断栈是否为空
                flag = true;
            } else if(st.top() != '{') {//判断上一个是否与之对应
                flag = true;
            } else {
                st.pop();//出栈
            }
            break;
        }
        default:
            break;
        }
        if (flag) {
            break;
        }
    }
    if (st.empty() && flag == false) {
        puts("True");
    } else {
        puts("False");
    }
    return 0;
}