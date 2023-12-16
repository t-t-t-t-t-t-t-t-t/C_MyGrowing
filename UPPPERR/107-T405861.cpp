#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int a;
	cin >> a;
	int x=0;
	int y = 10 * sqrt(x);
	while (y < a)
	{
		x++;
		y = 10 * sqrt(x);
	}
	cout << x;
	return 0;
}