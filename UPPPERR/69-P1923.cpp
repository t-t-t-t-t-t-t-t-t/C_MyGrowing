
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k;
	cin >> n>>k;
	int a[5005000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	a.erase(unique(a.begin(), a.end()), a.end());
	cout << a[k];
	return 0;
}