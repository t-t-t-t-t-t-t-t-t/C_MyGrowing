#include<iostream>
#include<string>
using namespace std;
//小数：1000.000100		1.0		0.1
//分数：1000/1000
int main()
{
	string s;
	cin >> s;
	int len = s.length() - 1;
	if (s[s.length() - 1] == '%')
	{
		int len = s.length() - 2;
		while (len && s[len] == '0')
		{
			len--;
		}
		for (int i = len; i >= 0; i--)
		{
			cout << s[i];
		}
		cout << '%';
		return 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		int po;
		if (s[i] == '.' )
		{
			po = i;
			int len1 = po - 1;
			while (len1 && s[len1] == '0') { len1--; }
			for (int j = len1; j >= 0; j--)
			{
				cout << s[j];
			}
			cout << s[po];
			int len2 = po + 1;
			while (len2 < s.length() - 1 && s[len2] == '0') { len2++; }/////////////////
			int len3 = s.length() - 1;
			while (len3 > len2 && s[len3] == '0') { len3--; }
			for (int j =len3; j >= len2; j--)
			{
				cout << s[j];
			}
			return 0;
		}
		if (s[i] == '/')
		{
			po = i;
			int len1 = po - 1;
			while (len1 && s[len1] == '0') { len1--; }
			for (int j = len1; j >= 0; j--)
			{
				cout << s[j];
			}
			cout << s[po];
			int len3 = s.length()-1;
			while (len3 > po && s[len3] == '0') { len3--; }
			for (int j = len3; j >= po+1; j--)
			{
				cout << s[j];
			}
			return 0;
	}
	}
	while (len && s[len] == '0')
	{
		len--;
	}
	for (int i = len; i >= 0; i--)
	{
		cout << s[i];
	}
	return 0;
}