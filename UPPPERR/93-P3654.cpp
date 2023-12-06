#include<iostream>
using namespace std;
int a[105][105];
int r, c, k;
bool px(int i, int j)
{
	for (int x = i; x < i + k; x++)
	{
		if (a[x][j]==0) { return 0; }
	}
	return 1;
}
bool py(int i, int j)
{
	for (int y = j; y < j + k; y++)
	{
		if (a[i][y]==0) { return 0; }
	}
	return 1;
}
int main()
{

	cin >> r >> c >> k;
	char m;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m;
			if (m == '.') { a[i][j] = 1; }
		}
	}
	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 0)
			{
				continue;
			}
			if (px(i,j))
			{
				ans++;
			}
			if (py(i, j))
			{
				ans++;
			}
		}
	}
	if (k== 1)
	{
		ans /=2;
	}
	cout << ans;
	return 0;
}