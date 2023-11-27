#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define double long double
double n,ans,m= 2100000000;
struct hb {
	double num,price;
}HB[3];
int main()
{
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> HB[i].num >> HB[i].price;
		ans = ceil(n*1.0 / HB[i].num) * HB[i].price;
		m = min(ans, m);
	}
	cout <<int( m);
	return 0;
}