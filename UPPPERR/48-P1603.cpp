#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string, int>m;
int a[6];
int main()
{
	m["one"] = 1; m["two"] = 4; m["three"] = 9; m["four"] = 16; m["five"] = 25; m["six"] = 36; m["seven"] = 49; m["eight"] = 64; m["nine"] = 81; m["ten"] = 0;
	m["eleven"] = 11; m["twelve"] = 44; m["thirteen"] = 69; m["fourteen"] = 96; m["fifteen"] = 25; m["sixteen"] = 56; m["seventeen"] = 89; m["eighteen"] = 24; m["nineteen"] = 61; m["twenty"] = 0;
	m["a"] = 1; m["both"] = 4; m["another"] = 1; m["first"] = 1; m["second"] = 4; m["third"] = 9;
	string s;
	int num = 0;
	int cnt = 1;
	for (int i = 0; i < 6; i++)
	{
		cin >> s;
		if (m[s]) {
			a[num++] = m[s];
			cnt = 0;///////////////////////////////////
		}
	}
	sort(a, a + num);
	string p;
	for (int i = 0; i < num; i++)
	{
		if (a[i] < 10)
		{
			p += '0';
			p += to_string(a[i]);
		}
		else { p += to_string(a[i]); }
	}
	int len =0;
	while (len<p.length() && p[len] == '0')
	{
		len++;
	}
	for (int i = len; i < p.length(); i++)
	{
		cout << p[i];
	}
	if (cnt) { cout << 0; }
	return 0;
}