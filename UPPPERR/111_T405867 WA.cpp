#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>s;
struct mm {
	int x, num;
}a[100000];
bool cmp(mm x, mm y)
{
	return x.num > y.num;
}
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			cin >> a[j].x;
			s.push_back(a[j].x);
			sort(s.begin(), s.end());
			int po = lower_bound(s.begin(), s.end(), a[j].x) - s.begin()+1;
			int ans = 0;
			for (int i = 0; i < po; i++)
			{
				if (s[i]) { ans++; }
			}
			a[j].num = --ans;
			a[j].x = po;
		}
		sort(a, a + n, cmp);
		cout << a[0].x << ' ' << a[0].num << '\n';
		s.clear();
	}
	return 0;
}