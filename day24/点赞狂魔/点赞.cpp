#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

class person {
    public:
    //i don't know if here is 8 the result will wrong
    char name[9];
    int sum;
    int count;
};

set<int> s;

bool cmp(person p1, person p2) {
    if(p1.sum == p2.sum ) {
        return p1.count < p2.count;
    }
    return p1.sum > p2.sum;
}

int main() {
    int m, n , i, j, temp;
    scanf("%d",&m);
    person p[m];
    for(i = 0; i < m; i++) {
        scanf("%s",&p[i].name);
        scanf("%d",&n);
        p[i].count = n;
        for(j = 0; j < n; j++) {
            scanf("%d",&temp);
            s.insert(temp);
        }
        p[i].sum = s.size();
        s.clear();
    }

    sort(p, p + m,cmp);
    if(m < 3) {
        for(i = 0; i < m; i++) {
           printf("%s ",p[i].name); 
        }
        for( ; i < 3; i++) {
            if(i == 2) {
                printf("-\n");
            } else {
                printf("- ");
            }
        }
    } else {
        for(i = 0; i < 2; i++) {
            printf("%s ",p[i].name);
        }
        printf("%s\n",p[i].name);
    }
    
    return 0;
}