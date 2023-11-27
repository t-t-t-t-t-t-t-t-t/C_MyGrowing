#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	float m, h;
	cin >> m >> h;
	float bmi = m / (h * h);
	if (bmi < 18.5) { cout << "Underweight"; }
	if ((bmi > 18.5 || abs(bmi - 18.5 )< 0.0001) && bmi < 24) { cout << "Normal";  }
	if (bmi > 24 || abs(bmi - 24 )< 0.0001) { cout << bmi << '\n' << "Overweight"; }
	return 0;
}