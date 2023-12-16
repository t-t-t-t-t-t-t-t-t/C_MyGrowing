#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int x = 1; x <= pow(n, n); x++)
	{
		if ((x % k) % n == 0 && x % 10 == n)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}