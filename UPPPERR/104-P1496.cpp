#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e6 + 10;
struct mm {
	int l, r;
}dis[N];
int a[N];
vector<int>X;
int po(int x)
{
	return lower_bound(X.begin(), X.end(), x)-X.begin()+1;
}
int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int l, r;
		cin >> l >> r;
		dis[i] = { l,r };
		X.push_back(l);
		X.push_back(r);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for (int i = 0; i <= t; i++)
	{
		a[po(dis[i].l)] ++;
		a[po(dis[i].r)]--;
	}
	for (int i = 1; i < X.size(); i++)
	{
		a[i] += a[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= t; i++)
	{
		
	}
	return 0;
}