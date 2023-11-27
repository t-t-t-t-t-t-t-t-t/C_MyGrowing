#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[10000],ans=1e9;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans = min(ans, a[i]);
	}
	cout << ans;
	return 0;
}