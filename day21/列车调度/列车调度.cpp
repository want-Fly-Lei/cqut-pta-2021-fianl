#include<iostream>
#include<set>
using namespace std;
set<int> s; 
//使用二分查找发
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(s.upper_bound(x) != s.end()){
            s.erase(s.upper_bound(x));
            s.insert(x);
        }
        else s.insert(x);
    }
    cout << s.size();
}