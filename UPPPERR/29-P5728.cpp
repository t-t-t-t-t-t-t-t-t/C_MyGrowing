#include<iostream>
#include<cmath>
using namespace std;
int a[100000];
class stu {
public:
	int a, b, c;
	int sum(int a, int b, int c)
	{
		return a + b + c;
	}
}m[1000];
int main()
{
	int n,ans=0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i].a >> m[i].b >> m[i].c;
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (abs(m[i].a - m[j].a) <= 5 && abs(m[i].b - m[j].b) <= 5 && abs(m[i].c - m[j].c) <= 5 && abs(m[i].sum(m[i].a, m[i].b, m[i].c) - m[j].sum(m[j].a, m[j].b, m[j].c)) <= 10)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}