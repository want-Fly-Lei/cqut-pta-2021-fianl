#include<string>
#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
int main(){
    string strFather,strSon;
    getline(cin,strSon);
    getline(cin,strFather);
    int i,len;
    bool caseArr[128];
    for(i = 0; i < 128; i++) {
        caseArr[i]= true;
    }
    len = strFather.size();
    for(i = 0; i < len; i++) {
        caseArr[strFather[i]] = false;
    }
    len = strSon.size();
    for(i = 0; i < len; i++) {
        if(caseArr[strSon[i]]) {
            cout<<strSon[i];
        }
    }
    return 0;
}