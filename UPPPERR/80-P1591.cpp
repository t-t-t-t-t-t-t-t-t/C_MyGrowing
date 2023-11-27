#include<iostream>
#include<cstring>
using namespace std;
int a[100000];
int main()
{
	int t;
	cin >> t;
	int n;
	int key;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		cin >> n >>key;
		a[0] = 1;
		for (int j = 2; j <= n; j++)
		{
			int ch = 0;
			for (int i = 0; i < 100000; i++)
			{
				a[i] = a[i] * j + ch;
				ch = a[i] / 10;
				a[i] %= 10;
			}
		}
		int num = 100000;
		int ans = 0;
		while (!a[num])
		{
			num--;
		}
		for (int i = 0; i <= num; i++)
		{
			if (a[i] == key) { ans++; }
		}
		cout << ans<<'\n';
	}
	return 0;
}