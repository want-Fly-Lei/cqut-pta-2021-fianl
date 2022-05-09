#include <iostream>
#include <string>
#include<cstdio>
#include <map>
using namespace std;
const int MAXN = 100010;
map<string, int> mp;
string str[MAXN];
int i, j, k;
 
int main(void) {
    int n, s;
    scanf("%d %d",&n, &s);
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }
        
    for (i = 1; i <= n / s; i++) {
        for (j = 1; j <= s; j ++ ) {
            cin >> mp[str[i * s - j]];
        }
    }
        
    scanf("%d",&k);
    string num;
    while ( k-- ) {
        cin >> num;
        if ( mp.count(num) )  {
            cout << mp[num] << endl;
        } else {
            puts("Wrong Number");
        }
    }
    
    return 0;
}