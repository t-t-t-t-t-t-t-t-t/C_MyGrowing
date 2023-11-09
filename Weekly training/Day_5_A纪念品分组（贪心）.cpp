//https://www.luogu.com.cn/problem/P1094
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, n, ans = 0;
	cin >> num;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int first = 0, last = a.size() - 1;
	while(first<=last)
	{
		if (a[first] + a[last] > num)
		{
			ans++;
			last--;
		}
		else
		{
			ans++;
			last--;
			first++;
		}
	}
	cout << ans;
	return 0;
}