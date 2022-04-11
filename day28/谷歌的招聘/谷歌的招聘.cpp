#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
int l, k, x, i;

bool cheek(int x){
    if (x <= 1) {
        return false;
    }
        
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1, s2;
    scanf("%d%d", &l, &k);
    cin >> s1;
    for (i = 0; i <= l - k; i++) {
        s2 = s1.substr(i, k);
        x = stoi(s2);
        if (cheek(x)) {
            cout << s2 << endl; //注意：题上说前导0也需要输出，所以输出一个x的话会不过，所以必须输出字符串s2
            return 0;
        }
    }
    puts("404");
    return 0;
}