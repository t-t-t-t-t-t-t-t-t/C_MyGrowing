#include<iostream>
using namespace std;
int a[40010];
int main()
{
	int t, x1, x2, cnt = 0;
	cin >> t;
	int po = 0;
	int sum = 0;
	while (sum<t*t)
	{
		cin >> x1;
		sum += x1;
		po += x1;
		cin >> x2;
		sum += x2;
		a[po + 1]++;
		a[po + x2 + 1]--;
		po += x2;
	}
	for (int i = 1; i <= t * t; i++)
	{
		a[i] += a[i - 1];
		cout << a[i];
		cnt++;
		if (!(cnt % t))
		{
			cout << '\n';
		}
	}
	return 0;
}