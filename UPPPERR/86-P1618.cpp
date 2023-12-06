#include<iostream>
#include<cstring>
using namespace std;
int b[11];
void in(int x)
{
	while (x)
	{
		b[x % 10]++;
		x /= 10;
	}
}
bool check(int x, int y, int z)
{
	memset(b, 0, sizeof(b));
	in(x); in(y); in(z);
	for (int i = 1; i <= 9; i++)
	{
		if (!b[i])
		{
			return 0;
		}
	}
	
	return 1;
}
int main()
{
	int a, b, c;
	int x, y, z;
	bool cnt = 1;
	cin >> a >> b >> c;
	if (a == 0 || b == 0 || c == 0) { cout << "No!!!"; return 0; }
	for (int x = 100; x <= 999; x++)
	{
		if (x * b % a != 0 || x * c % a != 0) { continue; }
		y = x * b / a;
		z = x * c / a;
		if (z > 999 || y > 999) { continue; }
		if (check(x, y, z)) { cout << x << " " << y << " " << z << " " << "\n"; cnt = 0; }
	}
	if (cnt) { cout << "No!!!"; }
	return 0;
}