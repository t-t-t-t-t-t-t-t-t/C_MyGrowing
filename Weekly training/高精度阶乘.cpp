#include<iostream>
#include<vector>
using namespace std;
vector<int> a(100000, 0), b(100000, 0);
int main()
{
	int n;
	cin >> n;a[0] = 1;
	for (int j = 1; j <= n; j++)
	{
		int ch = 0;
		for (int i = 0; i <= 1000; i++)
		{
			a[i] = a[i] * j + ch;
			ch = a[i] / 10;
			a[i] %= 10;
		}


		ch = 0;
		for (int i = 0; i < 10000; i++)
		{
			b[i] += a[i] + ch;
			ch = b[i] / 10;
			b[i] %= 10;
		}
	}
	int num = 10000;
	while (b[num] == 0)
	{
		num--;
	}
	for (int i = num; i >= 0; i--)
	{
		cout << b[i];
	}
	return 0;
}