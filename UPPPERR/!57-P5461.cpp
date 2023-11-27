#include<iostream>
#include<cmath>
using namespace std;
int a[1100][1100];
void she(int (*a)[1100], int x1, int y1, int x2, int y2)
{
	
	int px = x1 + x2 >> 1;
	int py = y1 + y2 >> 1;
	if (x1 == x2) { return; }
	she(a, x1, y1, px, py);
	she(a, x1, py + 1, px, y2);
	she(a, px + 1, y1, x2, py);
	she(a, px + 1, py + 1, x2, y2);
	for (int i = x1; i <= px; i++)
	{
		for (int j = y1; j <= py; j++)
		{
			a[i][j] = 1;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int m = pow(2, n);
	m--;
	she(a, 0, 0, m, m);
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (a[i][j] == 0) { cout << 1 << " "; }
			else { cout << 0 << " "; }
		}
		cout << '\n';
	}
	return 0;
}