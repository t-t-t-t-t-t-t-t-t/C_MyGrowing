#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int num = int(unique(a.begin(), a.end())-a.begin());
	a.erase(unique(a.begin(), a.end()), a.end());
	cout << num<<'\n';
	for (int i = 0; i < num; i++)
	{
		cout << a[i]<<' ';
	}
	return 0;
}