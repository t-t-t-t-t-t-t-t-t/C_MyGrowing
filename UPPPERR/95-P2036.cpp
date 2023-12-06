#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[100], b[100];

int main()
{
	int t;
	cin >> t;
	long long m = 1, n = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i] >> b[i];
	}
	int U = 1 << t;
	long long mi = 0x7fffffff;
	for (int i = 1; i < U; i++)
	{
		m = 1, n = 0;
		for (int j = 0; j < t; j++)
		{
			if (i & (1 << j)) {
				m *= a[j];
				n += b[j];
			}
		}
		mi = min(abs(m-n), mi);
	}
	cout << mi;
	return 0;
}