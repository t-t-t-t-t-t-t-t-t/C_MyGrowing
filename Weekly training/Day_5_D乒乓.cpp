//https://www.luogu.com.cn/problem/P1042
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char a[100000];
	int num = 1;
	while (a[num - 1] != 'E')
	{
		cin >> a[num];
		num++;
	}
	int left = 0, right = 0;
	for (int i = 1; i < num; i++)
	{
		if (a[i] == 'W') 
		{ 
			left++; 
		}
		else if(a[i]=='L')
		{ 
			right++;
		}
		if (a[i] == 'E')
		{
			cout << left << ":" << right << endl;
			left = 0;
			right = 0;
		}
		if (right >= 11 || left >= 11)
		{
			if (left - right >= 2 || right - left >= 2)
			{
				cout << left << ":" << right << endl;
				left = 0;
				right = 0;
			}
		}
		
	}
	cout << endl;
	left = 0, right = 0;
	for (int i = 1; i < num; i++)
	{
		if (a[i] == 'W') { left++; }
		else if(a[i]=='L') { right++; }
		if (a[i] == 'E')
		{
			cout << left << ":" << right << endl;
			left = 0;
			right = 0;
		}
		if (left >= 21 || right >= 21)
		{
			if (left - right >= 2 || right - left >= 2)
			{
				cout << left << ":" << right << endl;
				left = 0;
				right = 0;
			}
		}
	}
	return 0;
}