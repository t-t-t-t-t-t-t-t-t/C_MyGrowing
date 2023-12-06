#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 9;
int a[N], b[N];
int c[N], d[N];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(a, a + m);
	for (int i = 0; i < n; i++)
	{
		c[i] = upper_bound(a, a + m, b[i])-a;
	}
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << ' ';
	}
	return 0;
}