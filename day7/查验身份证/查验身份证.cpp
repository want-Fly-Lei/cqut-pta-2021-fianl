#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string* str = new string[n];
	for (int i = 0; i < n; i++)//输入身份证号 
	{
		cin >> str[i];

	}
	char a[n];	// 存储每行最后一位
	int sum[n];	// 存储每行前17位的和
	int shaobing[n];// 用于判断是否符合条件，1 符合 0 不符合
	for (int i = 0; i < n; i++)
	{
		a[i] = str[i][17];
		sum[i] = 0;
		shaobing[i] = 1;	
	}
	char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int N[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

	// 检验前十七位是否全为数字
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 17; i++)
		{
			if (str[j][i] >= '0'&&str[j][i] <= '9')
			{
				sum[j] += (str[j][i] - '0')*N[i];	// 加权求和
			}
			else
			{
				shaobing[j] = 0;
				break;
			}
		}
	}
	bool flag = 1;	// 判断是否所有均符合条件
	for (int i = 0; i < n; i++)
	{
		if (shaobing[i] == 0 || M[sum[i] % 11] != a[i])
		{
			flag = 0;	// 进入此循环则有一个不符合条件
			cout << str[i] << endl;
		}
	}
	if (flag)
	{
		cout << "All passed" << endl;
	}
	return 0;
}