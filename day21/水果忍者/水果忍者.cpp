#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define Pair pair<ll, int>
//#define max(a,b) (a)>(b)?(a):(b)
//#define min(a,b) (a)<(b)?(a):(b)
#define clean(a, b) memset(a, b, sizeof(a)) // 水印
// std::ios::sync_with_stdio(false);
//   register
const int MAXN = 1e4 + 10;
const int INF32 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const ll mod = 192600817;
const double EPS = 1.0e-8;
const double PI = acos(-1.0);

//都重写运算符和使用友元，就不能用class吗
struct Point{
    double x, y, t, d;
    Point(double _x = 0, double _y = 0, double _t = 0, double _d = 0){
        x = _x;
        y = _y;
        t = _t;
        d = _d;
    }

    friend Point operator+(const Point &a, const Point &b){
        return Point(a.x + b.x, a.y + b.y);
    }

    friend Point operator-(const Point &a, const Point &b){
        return Point(a.x - b.x, a.y - b.y);
    }

    friend double operator^(Point a, Point b){ //???????
        return a.x * b.y - a.y * b.x;
    }

    friend int operator==(const Point &a, const Point &b){
        return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
    }

    friend double operator*(const Point &a, const Point &b){
        return a.x * b.x + a.y * b.y;
    }
};

class V{
    Point start, end;
    double ang;
    V(Point _start = Point(0, 0), Point _end = Point(0, 0), double _ang = 0.0){
        start = _start;
        end = _end;
        ang = _ang;
    }

    friend V operator+(const V &a, const V &b){
        return V(a.start + b.start, a.end + b.end);
    }

    friend V operator-(const V &a, const V &b){
        return V(a.start - b.start, a.end - b.end);
    }
};

Point Dots1[MAXN], Dots2[MAXN];
Point Stk[MAXN];
int Top;
int n;

double Distance(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Parellel(double key){
    return fabs(key) < EPS ? 0 : key;
}

int Cmp(Point a, Point b){
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

void Jarvis1(){
    sort(Dots1 + 1, Dots1 + 1 + n, Cmp);
    Top = 2;
    Stk[1] = Dots1[1];
    Stk[2] = Dots1[2];
    for (int i = 3; i <= n; ++i){
        while (Top >= 2 && ((Dots1[i] - Stk[Top]) ^ (Stk[Top] - Stk[Top - 1])) >= 0) {
            --Top;
        }
        Stk[++Top] = Dots1[i];
    }
}

void Jarvis2(){
    sort(Dots2 + 1, Dots2 + 1 + n, Cmp);
    Top = 2;
    Stk[1] = Dots2[1];
    Stk[2] = Dots2[2];
    for (int i = 3; i <= n; ++i){
        while (Top >= 2 && ((Dots2[i] - Stk[Top]) ^ (Stk[Top] - Stk[Top - 1])) <= 0) {
            --Top;
        }
        Stk[++Top] = Dots2[i];
    }
}

int main(){
    scanf("%d", &n);
    double x, y1, y2;
    for (int i = 1; i <= n; ++i){
        scanf("%lf%lf%lf", &x, &y1, &y2);
        Dots1[i] = Point(x, y1);
        Dots2[i] = Point(x, y2);
    }
    if (n == 1){
        printf("%.0lf %.0lf %.0lf %.0lf\n", Dots1[1].x - 1, Dots1[1].y, Dots1[1].x + 1, Dots1[1].y);
        return 0;
    }

    if (n == 2){
        printf("%.0lf %.0lf %.0lf %.0lf\n", Dots1[1].x, Dots1[1].y, Dots1[2].x, Dots1[2].y);
        return 0;
    }

    Jarvis1();
    for (int i = 1; i <= Top; ++i) {
        Dots1[i] = Stk[i];
    }
        
    int upn = Top;
    Jarvis2();
    for (int i = 1; i <= Top; ++i) {
        Dots2[i] = Stk[i];
    }
        
    int dwn = Top; //求得下凸和上凸

    //	for(int i=1;i<=upn;++i) cout<<Dots1[i].x<<" "<<Dots1[i].y<<endl;
    //	cout<<"nxt"<<endl;
    //	for(int i=1;i<=dwn;++i) cout<<Dots2[i].x<<" "<<Dots2[i].y<<endl;

    int i, j;
    for (i = 1; i < upn; ++i){
        for (j = 1; j <= dwn; ++j){
            if (((Dots1[i + 1] ^ Dots1[i]) + (Dots1[i] ^ Dots2[j]) + (Dots2[j] ^ Dots1[i + 1])) < 0){ //下面的点比上面的点还要高
                break;
            }
        }
        if (j == dwn + 1) {
            break;
        }   
    }
    //	cout<<i<<" "<<j<<endl;
    Point ans1, ans2;
    if (i == upn){
        for (i = 1; i < dwn; ++i){
            for (j = 1; j <= upn; ++j){
                if (((Dots2[i + 1] ^ Dots2[i]) + (Dots2[i] ^ Dots1[j]) + (Dots1[j] ^ Dots2[i + 1])) > 0){
                    break;
                }
            }
            if (j == upn + 1) {
                break;
            }
                
        }
        ans1 = Dots2[i];
        ans2 = Dots2[i + 1];
        //		cout<<i<<" "<<j<<endl;
        //		cout<<Dots2[i].x<<" "<<Dots2[i].y<<endl;
    } else{
        ans1 = Dots1[i];
        ans2 = Dots1[i + 1];
    }
    printf("%.0lf %.0lf %.0lf %.0lf\n", ans1.x, ans1.y, ans2.x, ans2.y);
}