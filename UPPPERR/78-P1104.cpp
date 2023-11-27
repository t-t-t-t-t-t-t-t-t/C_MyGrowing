#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct S {
	string name;
	int year, mon, day,po;
}num[105];
bool cmp(S a, S b)
{
	if (a.year != b.year) { return a.year < b.year; }
	if (a.year == b.year && a.mon != b.mon) { return a.mon < b.mon; }
	if (a.year == b.year && a.mon == b.mon && a.day != b.day) { return a.day < b.day; }
	if (a.year == b.year && a.mon == b.mon && a.day == b.day) { return a.po > b.po; }

}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i].name >> num[i].year >> num[i].mon >> num[i].day;
		num[i].po = i;
	}
	sort(num, num + n,cmp);
	for (int i = 0; i < n; i++)
	{
		cout << num[i].name<<'\n';
	}
	return 0;
}