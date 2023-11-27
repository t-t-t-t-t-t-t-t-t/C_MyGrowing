#include<iostream>
#include<string>
#include <cstdio>
using namespace std;
void s1( int x, int y,char c)
{
	string s;
	s += to_string(x);
	s += to_string(y);
	if (c == 'a') { s += to_string(x + y); cout << x << "+" << y << "=" << x + y << '\n' << 2 + s.length() << '\n'; }
	if (c == 'b') { s += to_string(x - y); cout << x << "-" << y << "=" << x - y << '\n' << 2 + s.length() << '\n'; }
	if (c == 'c') { s += to_string(x * y); cout << x << "*" << y << "=" << x * y << '\n' << 2 + s.length() << '\n'; }
}
int main()
{
	int x, y;
	char m;
	char c[10];
	int t; cin >> t;
	while (t--)
	{
		cin >> c;
		if (c[0] <= 'z' && c[0] >= 'a') { cin >> x>>y; m = c[0]; }
		else { cin >> y; sscanf(c, "%d", &x); }
		s1( x, y,m);
	}
	return 0;
}