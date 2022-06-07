#include <cstdio>
#include <vector>
using namespace std;
vector<int> b;

int f1(int n) {
    if (n == 9) {
        return 1;
    }
    int x;
    while (n > 10) {
        x = n % 10;
        if (x == 9) {
            return 1;
        }
        n /= 10;
    }

    if (n == 9) {
        return 1;
    }
        
    return 0;
}

int f2(int n) {
    if (n == 7) {
        return 1;
    }
        
    int x;
    while (n > 10) {
        x = n % 10;
        if (x == 7) {
            return 1;
        }
        n /= 10;
    }

    if (n == 7) {
        return 1;
    }
        
    return 0;
}

int main() {
    int n, m;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        b.push_back(i);
    }
       
    int cnt = 0;
    vector<int>::iterator ij = b.end();
    vector<int>::iterator it = b.begin();
    while (b.size()) {
        ++cnt;

        if (cnt % 9 == 0 && f2(cnt) == 0 && cnt % 7 != 0) {
            printf("%d",*it);
            if (b.size() != 1) {
                 putchar(' ');
            }
               
            b.erase(it);
            if (it == b.end()) {
                it = b.begin();
            }
                
            continue;
        } else if (f1(cnt) == 1 && f2(cnt) == 0 && cnt % 7 != 0) {
            printf("%d",*it);
            if (b.size() != 1) {
                putchar(' ');
            }
            
            it = b.erase(it); 
            if (it == b.end()) {
                it = b.begin();
            }
                
            continue;
        }
        ++it;
        if (it == b.end()) {
            it = b.begin();
        }
    }

    return 0;
}
