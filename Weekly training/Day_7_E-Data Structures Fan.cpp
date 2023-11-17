#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 + 10;
long long a[N], sum0 = 0, sum1 = 0,xordiff[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	string s;
	int t;
	cin >> t;
	while (t--)
	{
		sum0 = 0, sum1 = 0;///////////////////////清零很重要；
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
	
		for (int i = 1; i <= n; i++)
		{
			xordiff[i] = a[i] ^ xordiff[i - 1];
		}
		cin >> s >> q;
		s = '?'+s;		//////////////////在s前加一个任意字符
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '0') 
			{
				sum0 ^= a[i];
			}
			else { sum1 ^= a[i]; }
		}
		while (q--)
		{
			int num, l, r, c;
			cin >> num;
			switch (num)
			{
			case 2:cin >> c; cout<< (c ? sum1 : sum0) << " "; break;
			case 1:cin >> l >> r; sum0 ^= (xordiff[r] ^ xordiff[l - 1]); sum1 ^= (xordiff[r] ^ xordiff[l - 1]); break;
			}
		}
		cout << '\n';
	}
	return 0;
}