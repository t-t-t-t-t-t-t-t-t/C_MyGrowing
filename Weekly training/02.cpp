#include<iostream>
using namespace std;
int m, n;
int f(int x)
{
	if (x == n) { return 1; }
	else if (x && x % 3==0) { return f(x / 3) + f(x * 2 / 3); }
	else { return 0; }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		bool cnt = 1;
		if (f(m))
		{
			cout << "yes\n";
			cnt = 0;
		}
		if (cnt)
		{
			cout << "no\n";
		}
	}
	return 0;
}