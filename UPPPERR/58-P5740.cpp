#include<iostream>
#include<string>
using namespace std;
struct stu {
	int a, b, c;
	string x;
}s[10000];
int sum[10000];
int main()
{
	int t;
	cin >> t;
	int m = INT16_MIN;
	int po;
	for (int i = 0; i < t; i++)
	{
		cin >> s[i].x >> s[i].a >> s[i].b >> s[i].c;
		sum[i] = s[i].a + s[i].b + s[i].c;
		if (sum[i] > m)
		{
			m = sum[i];
			po = i;
		}
	}
	cout << s[po].x << " " << s[po].a << " " << s[po].b << " " << s[po].c;
	return 0;
}