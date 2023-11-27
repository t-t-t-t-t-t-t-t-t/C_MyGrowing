#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long x;
	cin >> x;
	if (x < 0) { cout << "-"; x = -x; }
	string s;
	s = to_string(x);
	int len = s.length()-1;
	while (s[len] == '0'&&len)/////////////////////////////////
	{
		len--;
	}
	for (int i = len; i >= 0; i--)
	{
		cout << s[i];
	}
	return 0;
}