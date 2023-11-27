#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,m="0";
	int len = 0, n, maxlen = 0, po = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		len = s.length();
		if (len > maxlen||(len>=maxlen) && s>m)
		{
			maxlen = len;
			m = s;
			po = i+1;
		}
	}
	cout << po << '\n' << m;
	return 0;
}