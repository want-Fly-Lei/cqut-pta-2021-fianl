#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <stack>
#define STACK_INIT_SIZE 105
#define STACKINCREMENT 2
#define WRONGS "ILLEGAL"

typedef char SElemType;
using namespace std;

static char priority[8] = {8};

void priorityInit() {
    priority['#'] = 8;
    priority['+'] = 5;
    priority['-'] = 5;
    priority['*'] = 4;
    priority['/'] = 4;
    priority['^'] = 3;
    priority['('] = 1;
    priority[')'] = 1;
}

SElemType Precede(SElemType t1, SElemType t2) {
    SElemType f;
    switch (t2) {
    case '+':{
        if (t1 == '(' || t1 == '='){
            f = '<';
        }
        else
        {
            f = '>';
        }
        break;
    }

    case '-':{
        if (t1 == '(' || t1 == '='){
            f = '<';
        } else {
            f = '>';
        }
        break;
    }
    case '*': {
        if (t1 == '*' || t1 == '/' || t1 == ')' || t1 == '^') {
            f = '>';
        } else {
            f = '<';
        }
        break;
    }    
    case '/': {
        if (t1 == '*' || t1 == '/' || t1 == ')' || t1 == '^') {
            f = '>';
        } else {
            f = '<';
        }
        break;
        }
    case '^': {
        if (t1 == ')' || t1 == '^') {
            f = '>';
        } else {
            f = '<';
        }
        break;
    }   

    case '(': {
        if (t1 == ')') {
            puts("ERROR1");
            exit(EXIT_FAILURE);
        }
        else {
            f = '<';
        }   
        break;
    }
        
    case ')': {
        switch (t1) {
        case '(': {
            f = '=';
            break;
        }
        case '=': {
            puts("ERROR2");
            exit(EXIT_FAILURE);
        }
        default:
            f = '>';
        }
        break;
    }
        
    case '=': {
        switch (t1) {
        case '=': {
            f = '=';
            break;
        }
        case '(': {
            puts("ERROR2");
            exit(EXIT_FAILURE);
        } 
        default:
            f = '>';
        }
        }
    }
    return f;
}

int Operate(int a, char o, int b) {
    switch (o) {
    case '+': {
        return a + b;
    }    
    case '-': {
        return a - b;
    }  
    case '*': {
        return a * b;
    }
    case '/': {
        if (b == 0) {
            puts(WRONGS);
            exit(EXIT_SUCCESS);
        }
        return a / b;
    }
    case '^': {
        return pow(a, b);
    }
    default:
        puts("ERROR!");
        break;
    }
}

int Calculate(stack<int> &N, stack<char> &O, char *a) {
    int len = strlen(a), i = 0, temp = 0, x = 0, y = 0;
    char op;
    a[len] = '=';
    O.push('=');
    char ch = O.top();
    while (ch != '=' || a[i] != '=') {
        if (a[i] >= '0' && a[i] <= '9') {
            temp = a[i++] - '0';
            while (a[i] >= '0' && a[i] <= '9') {
                temp = temp * 10 + a[i++] - '0';
            }
            N.push(temp);
        } else {
            switch (Precede(ch, a[i])) {
            case '<': {
                O.push(a[i]); // 栈顶元素优先权低
                i++;
                break;
            }
                
            case '=': {
                ch = O.top();
                O.pop(); // 脱括号并接收下一字符
                ++i;
                break;
            }
                
            case '>': {
                op = O.top();
                O.pop(); // 退栈并将运算结果入栈
                y = N.top();
                N.pop();
                x = N.top();
                N.pop();
                N.push(Operate(x, op, y));
            }
            }
        }
        ch = O.top();
    }

    return N.top();
}

int main() {
    stack<int> Num;
    stack<char> Op;
    char ciallo[105];
    scanf("%[^\n]", &ciallo);
    printf("%d",Calculate(Num, Op, ciallo));
    return 0;
}
