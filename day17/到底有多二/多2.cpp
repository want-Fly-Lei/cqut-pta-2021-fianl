#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int len = str.size();
    int son = 0,father;
    double multiple;
    if(str[0] == '-') {
        father = len -1;
        multiple = 1.5;
    } else {
        multiple = 1;
        father = len;
    }
    for(int i = 0; i < len; i++) {
        if(str[i] == '2') {
            ++son;
        }
    }
    if(str[len - 1] % 2  == 0) {
        multiple *= 2;
    }
    printf("%.2lf%%",multiple * son * 100 / father);
    return 0;
}