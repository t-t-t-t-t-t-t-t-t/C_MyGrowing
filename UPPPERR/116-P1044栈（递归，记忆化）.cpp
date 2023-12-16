#include<iostream>
using namespace std;
int d[20][20][20];
int dfs(int x, int y, int z, int n) {
	if (x == n)d[x][y][z]=1;
	if (d[x][y][z])return d[x][y][z];
	if (y)d[x][y][z] += dfs(x + 1, y - 1, z, n);
	if (z)d[x][y][z] += dfs(x, y + 1, z - 1, n);
	return d[x][y][z];
}
int main() {
	int n;
	cin >> n;
	cout << dfs(0, 0, n, n);
	return 0;
}