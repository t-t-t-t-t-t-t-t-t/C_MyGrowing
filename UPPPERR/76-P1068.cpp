#include<iostream>
#include<algorithm>
using namespace std;
struct stu {
	int x, num;
}s[5005];
bool cmp1(stu a, stu b)
{
	return a.x > b.x;
}
bool cmp2(stu a, stu b)
{
	if (a.x != b.x) { return a.x > b.x; }
	if (a.x == b.x) { return a.num < b.num; }
}
int main()
{
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		cin >>s[i].num>> s[i].x;
	}
	sort(s, s + n, cmp1);
	int linenum = m * 3 >> 1;
	int linescore = s[linenum-1].x;
	for (int i = (m * 3 >> 1); i < n; i++)
	{
		if (s[i].x == linescore)
		{
			linenum++;
		}
	}
	cout << linescore << ' ' << linenum << '\n';;
	sort(s, s + linenum, cmp2);
	for (int i = 0; i < linenum; i++)
	{
		cout << s[i].num << ' ' << s[i].x << '\n';
	}
	return 0;
}
