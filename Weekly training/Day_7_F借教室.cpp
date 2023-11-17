//https://www.luogu.com.cn/problem/P1083
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e6 + 10;
long long n, m;
long long start[N],l[N],r[N],add[N],need[N],diff[N];
bool judge(int nth)
{
	memset(diff, 0, sizeof(diff));
	for (int i = 1; i <= nth; i++)
	{
		diff[l[i]] += add[i];
		diff[r[i] + 1] -= add[i];
	}
	for(int i=1;i<=n;i++)
	{
		need[i] = diff[i] + need[i - 1];
		if (need[i] > start[i])
		{
			return 0;
		}
	}
	return 1;////////////
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin>>start[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> add[i] >> l[i] >> r[i];
	}
	if (judge(m)) { cout << '0'; return 0; }/////////
	int begin = 1, end = m,mid;
	while (begin < end)
	{
		mid = begin + end >>1;
		if (judge(mid)) { begin = mid+1; }
		else { end = mid; }
	}
	cout << -1 << '\n' << end;//错点2，：cout，begin，end都可以，mid不行，
								//begin与end比较后相同时停止循环，mid未更新
	return 0;
}