#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int a[10000], ma = INT16_MIN, mi = INT16_MAX, sum = 0;
int main()
{
	int m, n;
	double p=-1000000;
	cin >> n >> m;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + m);
		mi = a[m - 1];
		ma = a[0];
		p = max((sum-mi-ma)*1.0  / (m - 2),p);
		sum = 0;
		int  ma = INT16_MIN, mi = INT16_MAX;
	}
	cout << fixed << setprecision(2) << p;
	return 0;
}