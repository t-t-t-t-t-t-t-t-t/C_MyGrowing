#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b)
{
	return a + b > b + a;
}
string s[25];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n, cmp);
	string a;
	for (int i = 0; i < n; i++)
	{
		a += s[i];
	}
	cout << a;
	return 0;
}