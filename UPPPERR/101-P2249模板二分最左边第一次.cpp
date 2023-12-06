#include<iostream>
using namespace std;
const int N = 2e6 + 9;
int n, m;
int a[N];
int find(int x)
{
	int l = 1, r = n, mid;
	int po = 0;
	while (l < r)
	{
		mid = (l + r)/2;
		if (a[mid] >= x)
			r = mid;
		else
			l = mid+1;
	}
	if (a[l] == x)return l;
	return -1;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	while (m--)
	{
		int num; cin >> num;
		cout << find(num) << ' ';
	}
	return 0;
}