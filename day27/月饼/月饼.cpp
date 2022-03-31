#include<stdio.h>
#include<algorithm>
using namespace std;

class goods {
    public:
    double num, price;
};

bool cmp(goods & g1, goods & g2) {
    return g1.num * g2.price < g2.num * g1.price;
}

int main() {
    int n, i, max;
    double sum = 0;
    scanf("%d %d",&n,&max);
    goods g[n];
    for(i = 0; i < n; i++) {
        scanf("%lf",&g[i].num);
    }
    for(i = 0; i < n; i++) {
        scanf("%lf", &g[i].price);
    }
    sort(g,g + n, cmp);

    for(i = 0; i < n; i++) {
        if(g[i].num < max) {
            sum += g[i].price;
            max -= g[i].num;
        } else {
            sum += g[i].price * max * 1.0 / g[i].num;
            break;
        }
    }
    printf("%.2lf\n",sum);
    return 0;
}