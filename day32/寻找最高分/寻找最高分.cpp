#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

class  Student {
    public:
    char num[11];        //学号，最多10个字符
    char name[11];       //姓名, 最多10个字符
    int s1,s2,s3;        //三门课的考试成绩
    int total;           //总成绩   
    void addTotal(){
        this->total = this->s1 + this->s2 + this->s3;
    }
    //重写是否相等
    bool operator==(const Student & st) {
        return this->total == st.total;
    }
};

//重写cout输出
ostream & operator<<(ostream & out, const Student & st) {
    out << st.num << " " << st.name << " " << st.total;
    return out;
}

int main() {
    int n;
    register int i;
    scanf("%d",&n);
    Student st[n];
    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d %d",&st[i].num, &st[i].name, &st[i].s1, &st[i].s2, &st[i].s3);
        st[i].addTotal();
    }
    sort(st, st + n,[](const Student & p1,const Student & p2)->bool {
        //利用lambda来确认判断，我就不重写<
        return p1.total > p2.total;
    });
    cout << st[0] << endl;
    for (i = 1; i < n; i++) {
        if (st[i] == st[0]) {
            cout << st[i] << endl;
        } else {
            break;
        }
    }
}