#include<iostream>
#include<string>
using namespace std;
int main() {
    int i, n;
    string str1, str2;
    cin>>n>>str1;
    cin.get();//吸收换行符
    getline(cin,str2);
    int len = str2.size();
    if(n >= len) {
        for(i = 0; i < n - len; i++) {
            cout<<str1;
        }
        cout<<str2<<endl;
    } else {
        for(i = len - n; i < len; i++) {
            cout<<str2[i];
        }
        cout<<endl;
    }
    return 0;
}