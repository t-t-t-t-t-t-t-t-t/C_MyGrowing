#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];	
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	int ans = 100000;
	for (int i = 0; i < n && i < n - m + 1; i ++ )
	{
	
		for (int j = i; j < m + i; j++)
		{
			sum += a[j];
		}
		ans = min(sum, ans);
		sum = 0;
	}
	cout << (ans== 100000?0:ans);
	return 0;
}