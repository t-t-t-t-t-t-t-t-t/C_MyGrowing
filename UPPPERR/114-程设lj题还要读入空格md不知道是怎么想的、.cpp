#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
string ans;
void strToDouble() {
	if (s.length() == 0 || s == "\n")
	{
		cout << 0 << '\n'; return;
	}
	int cnt = 0;
	if (s[0] == '-')cnt = 1;
	ans = s;
	int pot = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > '9' || s[i] < '0')
		{
			if (s[i] == '.' && pot == 0) {
				pot++; continue;
			}
			s.erase(i,1);
			i--;
		}
	}
	if (s.length() == 0) { cout << 0 << '\n'; return; }
	int begin = 0, end = s.length() - 1;
	while (s[begin] == '0')begin++;
	while (s[end] == '0')end--;
	string ans2;
	for (int i = begin; i <= end; i++)
	{
		ans2 += s[i];
	}

	if (ans2.length() == 1 && ans2[0] == '.') { cout << 0 << '\n'; return; }
	int po = -1;
	for (int i = 0; i < ans2.length(); i++) {
		if (ans2[i] == '.')
		{
			po = i;
		}
	}
	if (po == 0) {
		ans2 = '0' + ans2;
		po++;
	}
	if (cnt)cout << '-';
	for (int i = 0; i < (ans2.length() > 7 ? 7 : ans2.length()); i++)cout << ans2[i];
	cout << '\n';
	return;
}
int main() {
	char c = ' ';
	while (getline(cin, s))
	{
		if (s == "\n") {
			cout << 0;
			continue;
		}
		strToDouble();
	}
	return 0;
}