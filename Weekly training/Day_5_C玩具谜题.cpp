
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[100000];
	string b[100000];
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	int po = 0;
	for (int i = 0; i < m; i++)
	{
		int g,h;
		cin >> g >> h;
		if (g == a[po])
		{
			po -= h;
			if (po < 0)
			{
				po = n + po%n;
			}
		}
		else 
		{ 
			po += h;
			po %= n;
		}
	}
	cout << b[po];
	return 0;
}