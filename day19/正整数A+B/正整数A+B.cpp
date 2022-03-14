#include<iostream>
#include<cctype>
#include<string>
//不知道为啥，有一个测试点无法通过
using namespace std;
int main() {
	int len1, len2, i, temp1, temp2;
	string str1, str2;
	bool b1 = true, b2 = true;
	cin>>str1>>str2;
	len1 = str1.size();
	len2 = str2.size();
	if(len1 > 5) {
		b1 = false;
	} else {
		if(isdigit(str1[0]) || str1[0] == '+') {
			for(i = 1; i < len1; i++) {
				if('0' > str1[i] || str2[i] > '9') {
					b1 = false;
					break;
				}
			}
		} else {
			b1 = false;
		}
		
	}
	if(len2 > 5) {
		b2 = false;
	} else {
		if(isdigit(str2[0]) || str2[0] == '+') {
			for(i = 1; i < len2; i++) {
				if('0' > str2[i] || str1[i] > '9') {
					b2 = false;
					break;
				}
			}
		} else {
			b2 = false;
		}
	}
	if(b1) {
		temp1 = stoi(str1);
	}
	if( 0 < temp1 && temp1 <= 1000) {
		printf("%d + ",temp1);
	} else {
		printf("? + ");
		b1 = false;
	}
	if(b2) {
		temp2 = stoi(str2);
	}
	if(0 < temp2 && temp2 <= 1000) {
		printf("%d = ",temp2);
	} else {
		b2 = false;
		printf("? = ");
	}
	if(b1 && b2) {
		printf("%d\n",temp1 + temp2);
	} else {
		printf("?\n");
	}
	return 0;
}