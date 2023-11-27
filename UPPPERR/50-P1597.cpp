#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char, int>m;
int main()
{
	m['m'] = 0; m['b'] = 0; m['c'] = 0;
	string s;
	cin >> s;
	int p1 = 0;
	while(1)
	{
		p1 = s.find('=',p1+1);
		if (p1 == -1)
		{
			break;
		}
		if (s[p1 + 1] <= '9' && s[p1 + 1] >= '0') { m[s[p1 - 2]] = s[p1 + 1] - '0'; }
		else { m[s[p1 - 2]] = m[s[p1 + 1]]; }
	}
	cout << m['a'] << ' ' << m['b'] << ' ' << m['c'];
	return 0;
}