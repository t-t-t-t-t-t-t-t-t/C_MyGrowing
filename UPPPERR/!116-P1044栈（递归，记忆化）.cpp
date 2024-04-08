#include<iostream>
using namespace std;
int d[20][20][20];
int f(int x, int y, int z, int n) {
	if (d[x][y][z])return d[x][y][z];
	if (x)d[x][y][z] += f(x - 1, y + 1, z, n);
	if (y)d[x][y][z] += f(x, y - 1, z + 1, n);
	return d[x][y][z];
}
int main() {
	int n;
	cin >> n;
	d[0][0][n] = 1;
	cout << f(n, 0, 0, n);
	return 0;
}
