#include<iostream>
using namespace std;
int n;
int a[1000][1000], b[1000][1000];
int main() {
	int m;
	cin >> n >> m;
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = num++;
			b[i][j] = a[i][j];
		}
	}
	while (m--)
	{
		int x, y, r, z;//rŒ™∞Îæ∂
		cin >> x >> y >> r >> z;
		if (z == 0)//À≥ ±’Î;
		{
			for (int i = -r; i <= r; i++)
			{
				for (int j = -r; j <= r; j++)
				{
					b[x + j][y - i] = a[x + i][y + j];
				}
			}
		}
		else//ƒÊ ±’Î;
		{
			for (int i = -r; i <= r; i++)
			{
				for (int j = -r; j <= r; j++)
				{
					b[x - j][y + i] = a[x + i][y + j];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}