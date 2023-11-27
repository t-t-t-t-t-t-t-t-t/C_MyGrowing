#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[30];
bool zhi(int x)
{
	if (x == 1||x==0) { return 0; }
	if (x == 2) { return 1; }
	for (int i = 2; i * i <= x; i++)
	{
		if (!(x % i)) { return 0; }
	}
	return 1;
}
int main()
{
	string s;
	cin >> s;
	for (auto i : s)
	{
		a[i - 'a']++;
	}
	int ma = -100,mi=10000;
	for (int i = 0; i < 26; i++)
	{
		ma = max(ma, a[i]);
		if (a[i] < mi && a[i] != 0)
		{
			mi = a[i];
		}
	}
	if (zhi(ma-mi))
	{
		cout << "Lucky Word" << "\n"<<ma-mi;
	}
	else {
		cout << "No Answer" << "\n" << 0;
	}
	return 0;
}