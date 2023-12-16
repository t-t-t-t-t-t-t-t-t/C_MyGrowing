#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
const int N = 405;

int px[8] = { 1,2,2,1,-1,-2,-2,-1 };
int py[8] = { 2,1,-1,-2,-2,-1,1,2 };
int m, n;
struct po {
	int x, y;
}p;
queue<po>q;
int main()
{
	int ansm[N][N];
	int x, y;
	cin >> m >> n >> x >> y;
	memset(ansm, -1, sizeof(ansm));
	ansm[x][y] = 0;
	p = { x, y };
	q.push(p);
	while (q.size())
	{
		int nx = q.front().x;
		int ny = q.front().y;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int vx = nx + px[i], vy = ny + py[i];
			if (ansm[vx][vy] == -1 && vx <= m && vy <= n && vx >= 1 && vy >= 1)
			{
				p = { vx,vy };
				q.push(p);
				ansm[vx][vy] = ansm[nx][ny] + 1;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ansm[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}