#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXSIZE 1000
class hero {
    public:
        void setHero(int id) {
            this->id = id;
            this->count = 0;
        }
        short id;
        unsigned short count;
        hero & operator++() {
            ++this->count;
        }
};

int main() {
    hero h[MAXSIZE];
    int i, temp, n;
    scanf("%d",&n);
    for (i = 0; i < MAXSIZE; i++) {
        h[i].setHero(i);
    }
    for (i = 0; i < n; i++) {
        scanf("%d",&temp);
        ++h[temp];
    }
    sort(h,h + MAXSIZE,[](const hero & h1, const hero & h2)->bool {
        if (h1.count == h2.count) {
            return h1.id < h2.id;
        }
        return h1.count > h2.count;
    });
    printf("%d\n%d",h[0].id,h[0].count);
    return 0;
}