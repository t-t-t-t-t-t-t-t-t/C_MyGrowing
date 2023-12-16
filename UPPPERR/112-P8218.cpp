#include<iostream>
using namespace std;
int a[100050];
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int m;
	cin >> m;
	int l, r;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;
		cout << a[r] - a[l - 1]<<'\n';
	}
	return 0;
}