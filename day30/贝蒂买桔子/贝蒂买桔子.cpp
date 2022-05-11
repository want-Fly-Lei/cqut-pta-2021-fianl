#include <cstdio>
#include <string>
#include <iostream>
#include <set>
using namespace std;

set<string> myStr;
//运行超时，真恶心,时间20ms也太恶心了吧
//如果是是15的话，你需要输出三万多行，我丢我觉得很离谱


char chs[15];
int n, i, j;

void toBuy(string str, char ch);

void nuBuy(string str, char ch) {
    if (ch + 1 < 'a' + n) {
        nuBuy(str, ch + 1);
        toBuy(str, ch + 1); 
    } else {
        myStr.insert(str);
    }
}

void toBuy(string str, char ch) {
    str +=  ",";
    str.append(1,ch);
    
    if (ch + 1 < 'a' + n) {
        nuBuy(str, ch + 1);
        toBuy(str, ch + 1); 
    } else {
        myStr.insert(str);
    }
}

void baseToBuy(char ch) {
    string str = string(1,ch);
    if (ch + 1 < 'a' + n) {
       nuBuy(str,ch + 1);
       toBuy(str, ch + 1); 
    } else {
        myStr.insert(str);
    }
}

int main() {
    puts("{}");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        chs[i] = i + 'a';
    }
    for(i = 0; i < n; i++) {
        baseToBuy(chs[i]);
    }
    for (set<string>::iterator iter = myStr.begin(); iter != myStr.end(); iter++) {
        cout << "{" << *iter << "}" << endl;
    }
    return 0;
}