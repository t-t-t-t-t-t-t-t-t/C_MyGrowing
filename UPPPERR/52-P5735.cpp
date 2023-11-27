#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
struct po {
	double x, y;
}p[3];
int main()
{
	cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
	cout << fixed << setprecision(2) << dis(p[0].x, p[0].y, p[1].x, p[1].y) + dis(p[0].x, p[0].y, p[2].x, p[2].y) + dis(p[1].x, p[1].y, p[2].x, p[2].y);
	return 0;
}