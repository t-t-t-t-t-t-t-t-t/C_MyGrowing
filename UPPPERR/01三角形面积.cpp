#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c, p;
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	cout << fixed << setprecision(1) << sqrt(p * (p - a) * (p - b) * (p - c));
	return 0;
}