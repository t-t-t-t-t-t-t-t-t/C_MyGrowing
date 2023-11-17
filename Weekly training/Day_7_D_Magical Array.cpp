//https://codeforces.com/contest/1704/problem/D
#include<iostream>
using namespace std;
int main()
{
	long long a[300005];
	int t;
	cin >> t;
	while (t--)
	{
		long long num, len;
		cin >> num >> len;
		long long sum[100000] = { 0 };

		for (int i = 1; i <= num; i++) {
			for (long long j = 1; j <= len; j++) {
				cin >> a[j];
				a[j] += a[j - 1];
				sum[i] += a[j];
			}
		}
		long long max = LLONG_MIN, min = LLONG_MAX, minpo = 0;
		for (int i = 1; i <= num; i++)
		{
			if (sum[i] > max) { max = sum[i]; }
			if (sum[i] <= min) {
				min = sum[i]; minpo = i;
			}
		}
		cout << minpo << " " << max - min << endl;
	}
	return 0;
}