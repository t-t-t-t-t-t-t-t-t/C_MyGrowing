#include<iostream>
#include<iomanip>
using namespace std;
int  main()
{
	double a[1000];
	int  n;
	cin >> n;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	cout <<fixed<<setprecision(2)<< a[n - 1];
	return 0;
}