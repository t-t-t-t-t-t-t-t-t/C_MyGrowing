#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int x, y;

int a[10000], b[10000], c[10000];
string cheng(string s1,string s2) {
	string s;
	vector<int>a(10001, 0), b(10001, 0), c(10001, 0);
	for (int i = 0; i < s1.length(); i++)
	{
		a[i] = s1[s1.length() - 1 - i] - '0';
	}
	for (int i = 0; i < s2.length(); i++)
	{
		b[i] = s2[s2.length() - 1 - i] - '0';
	}
	for (int i = 0, j = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			c[i + j] += a[i] * b[j];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}
	}
	int si = c.size() - 1;
	while (c[si] == 0 && si > 0)
	{
		si--;
	}
	for (int j = si; j >= 0; j--)
	{
		s += c[j] + '0';
	}
	return s;

}
int main()
{
	string l1, r1,l2,r2;
	cin >> x >> y;
	if (x < 0) { x = -x; }
	if (y < 0) { y = -y; }
	l1 = to_string(x);
	r1 = to_string(y);
	cin >> x >> y;
	if (x < 0) { x = -x; }
	if (y < 0) { y = -y; }
	l2 = to_string(x);
	r2 = to_string(y);
	string s1 = cheng(l1,l2);
	string s2 = cheng(r1, r2);
	if ((s1.length()==10&&s1 > "2147483648")|| s1.length()>10||s2.length() > 10 ||(s2.length() == 10&&s2 > "2147483647"))
	{
		cout << "long long int";
	}
	else {
		cout << "int";
	}
	return 0;
}