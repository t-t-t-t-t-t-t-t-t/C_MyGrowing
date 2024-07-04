#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class point {
	private:
		double x;
		double y;
	public:
		point() {
			x=0;
			y=0;
		};
		point(double x1,double y1) {
			x=x1;
			y=y1;
		}
		double getx() {
			return x;
		}
		double gety() {
			return y;
		}
		void setx(double x1) {
			x=x1;
		}
		void sety(double y1) {
			y=y1;
		}
		double distance(point p);
};
double point::distance(point p) {
	double dx,dy,dis;
	dx=x-p.x;
	dy=y-p.y;
	dis=pow(dx,2)+pow(dy,2);
	return pow(dis,0.5);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int a,b,c,d;
		point	t1(a,b);
		point	t2(c,d);
		int r=t1.distance(t2);
		cout << "Distance of Point" << "(" << t1.getx() << "," << t1.gety() << ")" << " to Point(" <<  t2.getx() << "," << t2.gety() << ")" << " is " << r << endl;
	}
	return 0;
}
