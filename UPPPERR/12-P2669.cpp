#include<iostream>
using namespace std;
int main()
{
	long long ans=0;
	int k,day=0;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ans += i; day++;
			if (day == k)
			{
				cout << ans; return 0;
			}
		}
	}
	return 0;
}