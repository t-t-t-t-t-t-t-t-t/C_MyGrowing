#include<iostream>
using namespace std;
int main()
{
	int n;
	double a;
	int ans = 0;
	int t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> t;
		for (int j = 1; j <= t; j++)
		{
			ans ^= int(a * j);////////////////////±äÕûÐÍ	
		}
	}
	cout << ans;
	return 0;
}