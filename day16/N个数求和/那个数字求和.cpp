#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){ //求a,b最大公约数
	if (b)
		return gcd(b, a % b);
	return a;
}

void merge(LL &a1, LL &b1, LL &a2, LL &b2){	//计算两个数的和
	LL fenmu = b1 * b2 / gcd(b1, b2);				  //两个分母的最小公倍数
	LL fenzi = (fenmu / b1) * a1 + (fenmu / b2) * a2; //通分相加
	a1 = fenzi;
	b1 = fenmu;
}

int main(){
	LL n, a1, b1, a2, b2;
	char ch;
	cin >> n;
	cin >> a1 >> ch >> b1; //先输入一个数据
	for (int i = 0; i < n - 1; i++){
		cin >> a2 >> ch >> b2;
		merge(a1, b1, a2, b2); //每输入一个就计算一个，每次都给保存在a1和b1中
	}
	LL k = gcd(a1, b1); //求分子总和a1和分母总和b1的最大公约数
	a1 = a1 / k;
	b1 = b1 / k;
	if (a1 && a1 / b1 == 0)
		cout << a1 % b1 << "/" << b1; //分子不为0且分子小于分母
	else if (a1 % b1 == 0)
		cout << a1 / b1; //整数
	else
		cout << a1 / b1 << " " << a1 % b1 << "/" << b1; //分子大于分母
	return 0;
}
