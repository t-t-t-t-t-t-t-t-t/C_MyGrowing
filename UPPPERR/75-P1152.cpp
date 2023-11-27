#include<iostream>
#include<cmath>
using namespace std;
int a[1005],b[10000000];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		b[abs(a[i] - a[i - 1])]++;
	}
	for (int i = 1; i < n; i++)
	{
		if (!b[i]) { cout << "Not jolly"; return -0; }
	}
	cout << "Jolly";
	return 0;
}