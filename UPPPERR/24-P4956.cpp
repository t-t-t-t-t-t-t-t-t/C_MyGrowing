#include<iostream>
using namespace std;
int main()
{
	int x, n, k;
	cin >> n;
	for (int k = 1;; k++)
	{
		x = n / 364 - 3 * k;
		if (x > 100 || x < 1) { continue; }////////////
		if ((x + 3 * k) * 364 == n)
		{
			cout << x << '\n' << k;
			return 0;
		}
	}
	return 0;
}