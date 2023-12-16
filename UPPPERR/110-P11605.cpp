#include<iostream>
using namespace std;
int px[4] = { -1,0,1,0 };
int py[4] = { 0,1,0, -1 };
int map[10][10], wmap[10][10];
int ans = 0, n, m, t, sx, sy, fx, fy, tx, ty;
void walk(int x, int y)
{
	if (x == fx && y == fy)
	{
		ans++;
		return;
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			if (wmap[x + px[i]][y + py[i]] == 0 && map[x + px[i]][y + py[i]] == 1)
			{
				wmap[x][y] = 1;
				walk(x + px[i], y + py[i]);
				wmap[x][y] = 0;
			}
		}
	}
}
int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = 1;
		}
	}
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < t; i++)
	{
		cin >> tx >> ty;
		map[tx][ty] = 0;
	}
	walk(sx, sy);
	cout << ans;
	return 0;
}