#include<iostream>
using namespace std;
int main()
{
	int x, n,v=250;
	cin >> x >> n;
	int rest = (x + n - 1) / 7 * 2 + ((x + n - 1) % 7==6  ? 1 : 0 ) - (x == 7 ? 1 : 0);
	int day = n - rest;
	cout << day * v;

	return 0;

}