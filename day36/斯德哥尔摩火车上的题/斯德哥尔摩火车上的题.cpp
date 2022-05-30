#include <iostream>
#include <string>
using namespace std;

string fun(string a) {
    string s = "";
    for (int i = 1; i < a.length(); i++) {
        if (a[i] % 2 == a[i - 1] % 2) {
            s += max(a[i], a[i - 1]);
        }
    }
    return s;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string c1 = fun(s1);
    string c2 = fun(s2);
    if (c1 == c2) {
         cout << c1;
    } else {
        cout << c1 << endl << c2;
    }
    return 0;
}