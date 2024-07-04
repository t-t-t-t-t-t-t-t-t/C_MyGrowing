#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Geometry {
public:
	virtual double getArea() = 0; //计算面积，结果保留小数点后两位
};
class Circle :public Geometry {
	double r;
public:
	Circle(double _r) :r(_r) {

	}
	virtual double getArea() {
		return r * r * 3.14;
	}
};
class Rect :public Geometry {
	double a,b;
public:
	Rect(double _a, double _b) :a(_a), b(_b) {

	}
	virtual double getArea() {
		return a * b;
	}
};
class TotalArea {
public:
	static void computerMaxArea(Geometry** t, int n) {
		double maxArea = 0.0;
		for (int i = 0; i < n; i++) {
			maxArea = max(maxArea, (*(t + i))->getArea());
		}
		cout<<fixed<<setprecision(2) << "最大面积=" << maxArea;
	}
};
int main() {
	int t; cin >> t;
	Geometry** mm=new Geometry*[t];// 抽象类父指针 装多种子类，多态
	int type;
	double a, b, r;
	for (int i = 0; i < t; i++) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b;
			*(mm + i) = new Rect(a, b);
		}
		else {
			cin >> r;
			*(mm + i) = new Circle(r);
		}
	}
	TotalArea::computerMaxArea(mm, t);
	delete[]mm;
	return 0;
}