#include<iostream>
using namespace std;
int jie(int n)
{
	if (n == 1) { return 1; }
	return n * jie(n - 1);
}
int main()
{
	int n;
	cin >> n;
	cout << jie(n);
	return 0;
}