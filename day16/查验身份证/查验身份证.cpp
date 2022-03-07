#include<string>
#include<iostream>
#include<cstdio>
#include<cctype>
#define SIZE 17
using namespace std;
int value[SIZE] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11] = {'1','0', 'X', '9', '8' ,'7', '6', '5', '4', '3', '2'};
int main() {
    int n, i, j, sum;
    scanf("%d",&n);
    string str;
    bool flag = true;
    for(i = 0; i < n; i++) {
        cin>>str; 
        if(str.size() != SIZE + 1) {
            cout<<str<<endl;
            flag = false;
            continue;
        }
        sum = 0;
        for(j = 0; j < SIZE; j++) {
            if(isdigit(str[j])) {
                sum += (str[j] - 48) * value[j];
            } else {
                sum += 10 * value[j];
            }
        }
        if(str[SIZE] != M[sum % 11]) {
            cout<<str<<endl;
            flag = false;
        }

    }
    if(flag) {
        printf("All passed\n");
    }
    return 0;
}