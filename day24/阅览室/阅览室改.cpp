#include<cstdio>
#include<vector>
using namespace std;

class book {
    public:
    int id, hour,min;
    char s;
    //进行比较时间
    bool operator<=(const book & b) const {
        if( this->hour == b.hour) {
            return this->min <= b.min;
        }
        return this->hour < b.hour;
    }
    //相减
    int operator-(const book &b) const {
        return (this->hour - b.hour) * 60 + this->min - b.min;
    }
    //相等
    int operator==(const book &b) const {
        return this->id == b.id;
    }
};

vector<book> borrow;
book b;
int i, j, k, n, count, myTime;

int main() {
    scanf("%d",&n);
    i = 0;
    while(i < n) {
        scanf("%d %c %d:%d",&b.id, &b.s, &b.hour, &b.min);
        if(b.id != 0) {
                borrow.push_back(b);
        } else {
            myTime = count = 0;
            for(j = 0; j < borrow.size(); j++) {
               for(k =  j + 1; k < borrow.size(); k++) {
                   if(borrow[j] == borrow[k] && borrow[j].s == 'S') {  
                       if(borrow[k].s == 'S') {
                           break;
                       }
                       ++count;
                       myTime += borrow[k]- borrow[j];
                       break;
                   }
               }
            }
            if( count != 0) {
               printf("%d %.0lf\n",count,myTime * 1.0 / count); 
            } else {
                printf("0 0\n"); 
            }
            
            borrow.clear();
            ++i;
        }
    }
    return 0;
}