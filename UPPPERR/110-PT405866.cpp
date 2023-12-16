#include<iostream>
using namespace std;
int a[10000];
int main()
{
	int n;
	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		x ^= a[i];
	}
	cout << x << ' ' << 0;

	return 0;
}