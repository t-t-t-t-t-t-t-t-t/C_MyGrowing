#include<iostream>
#include<cstring>
using namespace std;
long long p[9][2] = {
	{-1,2},
	{-2,1},
	{1,2},
	{2,1},
	{2,-1},
	{1,-2},
	{-1,-2},
	{-2,-1},
	{0,0}
};
long long a[100][100], f[100][100];
int main()
{
	memset(f, 0, sizeof(f));
	long long m, n, x, y;
	cin >> m >> n >> x >> y;
	m++; n++; x++; y++;
	for (long long i = 0; i < 9; i++)
	{
		if (y + p[i][1] <= m && y + p[i][1] >= 0 && x + p[i][0] >= 0 && x + p[i][0] <= n)
		{
			a[x + p[i][0]][y + p[i][1]]++;
		}
	}
	if (a[1][1] == 1) { cout << 0; return 0; }
	f[1][1] = 1;
	for (long long i = 1; i <= m; i++)
	{
		for (long long j = 1; j <= n; j++)
		{
			if (a[i][j]) { continue; }
			f[i][j] += (f[i - 1][j] + f[i][j - 1]);
		}
	}
	cout << f[m][n];
	return 0;
}