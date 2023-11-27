#include<iostream>
using namespace std;
bool zhi(int x)
{
	if (x == 0 || x == 1)return 0;
	if (x == 2) { return 1; }
	for (int i = 2; i * i <= x; i++)
	{
		if (!(x % i)) { return 0; }
	}
	return 1;
}
int so(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (zhi(i) && zhi(x - i))
		{
			return i;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 4; i <= n; i += 2)
	{
		cout << i << '=' << so(i) << '+' << i - so(i)<<'\n';
	}
	return 0;
}