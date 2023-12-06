#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char w[10000], b[10000], r[10000];
int m, n;
string s;
int f(char c)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != c) { sum++; }
	}
	return sum;
}
int main()
{

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> s;
		w[i] = w[i - 1] + f('W');
		b[i] = b[i - 1] + f('B');
		r[i] = r[i - 1] + f('R');
	}
	int mi = 0x7fffffff;
	for (int i = 1; i < m-1; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			mi = min(mi, w[i] + b[j] - b[i] + r[m] - r[j]);
		}
	}
	cout << mi;
	return 0;
}