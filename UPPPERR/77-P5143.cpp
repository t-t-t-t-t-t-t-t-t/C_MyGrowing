#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct P {
	int x, y, z;
}p[50000];
bool cmp(P a, P b)
{
	return a.z < b.z;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	sort(p, p + n, cmp);
	double sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += sqrt((p[i].x - p[i - 1].x) * (p[i].x - p[i - 1].x) + (p[i].y - p[i - 1].y) * (p[i].y - p[i - 1].y) + (p[i - 1].z - p[i].z) * (p[i - 1].z - p[i].z));
	}
	cout << fixed << setprecision(3) << sum;
	return 0;
}