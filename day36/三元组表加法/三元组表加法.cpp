#include <iostream>
#include <map>
using namespace std;

class book {
    public:
    int x, y;
    bool operator <(const book & b1) const {
        if (this->x != b1.x) {
            return this->x < b1.x;
        }
        return this->y < b1.y;
    }
};

map<book, int> M;
int main()
{
    int n, m, i, x, y, z;
    book s;
    scanf("%d %d",&n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d",&x, &y, &z);
        s.x = x;
        s.y = y;
        M[s] += z;
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&x, &y, &z);
        s.x = x;
        s.y = y;
        M[s] += z;
    }

    map<book, int>::iterator it;
    for (it = M.begin(); it != M.end(); it++) {
        s = it->first;
        if (it->second != 0) {
            printf("%d %d %d\n", s.x, s.y, it->second);
        }
            
    }
}
