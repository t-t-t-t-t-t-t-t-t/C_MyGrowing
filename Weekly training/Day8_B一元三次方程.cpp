#include<iostream>
#include<iomanip>
using namespace std;
double a, b, c, d;
double f(double x)
{
	return ((a * x + b) * x + c)*x + d;
}
int main()
{
	int ans = 0;
	cin >> a >> b >> c >> d;
	for (double i = -100; i <= 100; i++)
	{
		if (f(i) * f(i + 1) <= 0)
		{
			if (f(i) == 0) {
				cout << fixed << setprecision(2) << i << ' '; ans++;
			}
			else if (f(i + 1) == 0) {}
			else {
				double l = i;
				double r = i + 1;
				double mid;
				while (r - l > 1e-3)
				{
					mid = (l + r) / 2;
					if (f(mid) * f(r) < 0) { l = mid; }
					else { r = mid; }
				}
				cout << fixed << setprecision(2) << mid << ' '; ans++;
			}
		}
		if (ans == 3) { return 0; }
	}
	return 0;
}