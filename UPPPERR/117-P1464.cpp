#include<iostream>
#include<cstring>
using namespace std;
long long m[22][22][22];
long long w(long long a, long long b, long long c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) a = b = c = 20;
	if (m[a][b][c])return m[a][b][c];
	if (a < b && b < c) m[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else m[a][b][c] =w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return m[a][b][c];
}
int main()
{
	long long a, b, c;
	while (cin >> a >> b >> c)
	{
		memset(m, 0, sizeof(m));
		if (a == -1 && b == -1 && c == -1)return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
	return 0;
}