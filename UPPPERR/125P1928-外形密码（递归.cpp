#include<iostream>
#include<string>
using namespace std;
const long long N = 2e5 + 9;
string ans;
string key()
{
	int n;
	string s, s1;
	char c;
	while (cin >> c)
	{
		if (c == '[')
		{
			cin >> n;
			s1 = key();
			while (n--) s += s1;
		}
		else
		{
			if (c == ']') return s;
			else s += c;
		}
	}
	ans = s;
}
int main()
{
	key();
	cout << ans;
	return 0;
}