#include<iostream>
using namespace std;
int a[21][21];
int main()
{
	int n;
	cin >> n;
	a[1][1] = 1;
	for (int i = 2; i <=n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << '\n';
	}
	return 0;
}