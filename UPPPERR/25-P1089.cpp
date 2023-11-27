#include<iostream>
using namespace std;
int main()
{
	int a[13], now = 0, more = 0;
	for (int i = 1; i <= 12; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= 12; i++)
	{
		now += 300;
		now -= a[i];
		if (now < 0) {cout << -i; return 0;}
		while (now > 100)//////¶àµÄÈ«´æ£»
		{
			now -= 100;
			more++;
		}
	}
	cout << now + 120 * more;
	return 0;
}