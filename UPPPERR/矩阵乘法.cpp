#include<iostream>
using namespace std;
int a[105][105], b[105][105],c[105][105], ans1[105][105], ans2[105][105];
int main()
{
	int n,t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> b[i][j];
				
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans1[i][j] = b[i][j] + a[i][j];
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					sum += a[i][k] * b[k][j];
				}
				ans2[i][j] = sum;
				sum = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << ans1[i][j]<< (j == n - 1 ? '\n' : ' ');
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << ans2[i][j] << (j==n-1?'\n':' ');
			}
		}
	}
	return 0;
}