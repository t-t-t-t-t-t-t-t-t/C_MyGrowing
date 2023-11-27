#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int a[20005];
int main()
{
	int n;
	cin >> n;
	int g;
	cin >> g;
	for (int i = 0; i< n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	int sum = 0;
	int num = 0;
	while (sum < g)
	{
		sum += a[num++];
	}
	cout << num;
	return 0;
}