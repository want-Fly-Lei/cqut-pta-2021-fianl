#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;
#define SIZE 9
#define MAXSIZE 10
int main() {
    int n,i,j;
	int sum;
    scanf("%d",&n);
    string str;
	bool flag, allFlag = true;
    for(i = 0; i < n; i++) {
        cin>>str;
		if(str.size() != MAXSIZE) {
			allFlag = false;
			cout<<str<<endl;
			continue;
		}
		flag = true;
		for(j = 0; j < SIZE; j++) {
			if(!isdigit(str[j])){
				flag = false;
				break;
			}
		}
		if(flag) {
			if((isdigit(str[9])) || (str[9] == 'X') || (str[9] == 'x')) {
				sum = 0;
				for(j = 0; j < SIZE; j++) {
					sum += (j + 1) * (str[j] - 48);
				}
				if(isdigit(str[9])) {
					sum += 10 * (str[9] - 48);
				} else {
					sum += 100;
				}
				if(sum % 11 != 0) {
					allFlag = false;
					cout<<str<<endl;
				}
			} else {
				allFlag = false;
				cout<<str<<endl;
			}
		} else {
			allFlag = false;
			cout<<str<<endl;
		}
    }
	if(allFlag) {
		printf("All passed");
	}
    return 0;
}