#include<iostream>
#include<cmath>
using namespace std;
struct stu {
	int a, b, c, sum;
	string x;
}s[10000];
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s[i].x >> s[i].a >> s[i].b >> s[i].c;
		s[i].sum = s[i].a + s[i].b + s[i].c;
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = i+1; j < t; j++)
		{
			if (abs(s[i].a - s[j].a) <= 5 && abs(s[i].b - s[j].b) <= 5 && abs(s[i].c - s[j].c) <= 5 && abs(s[i].sum - s[j].sum) <= 10)
			{
				cout << s[i].x << " " << s[j].x << '\n';
			}
		}
	}
	return 0;
}