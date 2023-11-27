#include<iostream>
#include<algorithm>
using namespace std;
struct stu {
	int a, b, c,num;
	int sum ;
}s[10000];

bool cmp(const stu& a, const stu& b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.sum == b.sum && a.a != b.a)
		return a.a > b.a;
	else if (a.sum == b.sum && a.a == b.a && a.num != b.num)
	
		return a.num < b.num;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].a >> s[i].b >> s[i].c;
		s[i].sum= s[i].a + s[i].b + s[i].c;
		s[i].num = i+1;
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < 5; i++)
	{
		cout << s[i].num <<' ';
		cout << s[i].sum<<'\n';
	}
	return 0;
}