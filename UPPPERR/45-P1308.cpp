#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s, po;
	getline(cin, po);
	getline(cin, s);
	po = " " + po + " ";
	s = " " + s + " ";
	for (int i = 0; i < po.length(); i++)
	{
		if (po[i] >= 'A' && po[i] <= 'Z') { po[i] += 'a' - 'A'; }
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') { s[i] += 'a' - 'A'; }
	}
	int begin = s.find(po);
	int num = 0, first;
	first = begin;
	if (begin == -1)
	{
		cout << -1; return 0;
	}
	else {
		while (begin != -1)
		{
			begin = s.find(po, begin+1) ;
			num++;
		}
	}
	cout << num << ' ' << first;
	return 0;
}