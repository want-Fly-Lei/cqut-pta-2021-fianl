#include <iostream>
#include <stack>

using namespace std;

string str;
stack<int> stk;

int main()
{
    while (cin >> str)
    {

        int resl = 0, resc = 1;
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (c == '(')
                stk.push(i);
            else if (stk.size() && str[stk.top()] == '(')
                stk.pop();
            else
                stk.push(i); //注意，这里进栈的是下标

            int r;
            if (stk.size())
                r = i - stk.top();
            else
                r = i + 1;

            if (r > resl)
                resl = r, resc = 1;
            else if (r == resl && r > 0)
                resc++;
        }

        cout << resl << " " << resc << endl;
    }
    return 0;
}
