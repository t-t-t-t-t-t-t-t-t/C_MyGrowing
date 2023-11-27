#include<iostream>
using namespace std;
bool zhi(int x)
{
	if (x == 0 || x == 1) { return 0; }
	if (x == 2) { return 1; }
	for (int i = 2; i * i <= x; i++)
	{
		if (!(x % i)) { return 0; }
	}
	return 1;
}int a[1000000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (zhi(a[i])) { cout << a[i]<<' '; }
	}
	return 0;
}