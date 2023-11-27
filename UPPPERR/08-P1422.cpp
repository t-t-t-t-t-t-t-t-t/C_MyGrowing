#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double ABS(int x)
{
	if (x < 0)return -x;
	return x;
}
int main()
{
	double E,sum=0,flag=1e-9;
	cin >> E;
	if (E <= 150)
	{
		sum = ((E < 150 || ABS(E - 150) < flag) ? E * 0.4463 : 150 * 0.4463);/////////////////////////////any better????
	}
	else{	sum = ((E < 150 || ABS(E - 150) < flag) ? E * 0.4463 : 150 * 0.4463) + ((E > 150 && (E < 400 || ABS(E - flag) < flag)) ? (E - 150) * 0.4663 : (400 - 150) * 0.4663) + (E > 400 ? (E - 400) * 0.5663 : 0);
}
	cout <<fixed<<setprecision(1)<< sum;
	return 0;
}