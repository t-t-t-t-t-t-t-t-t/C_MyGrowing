#include<iostream>
#include<cmath>
using namespace std; int a[10000],c[10000];
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int po = 1,num=1,ans=1;
	while (po < n)
	{
		po++;
		while (a[po+1] - a[po] == 1)///当不满足条件就不计数，跳出；
		{
			num++;
			po++;
		}
		ans = max(ans, num);
		num = 1;//至少为一个
	}
	cout << ans;
	return 0;
}