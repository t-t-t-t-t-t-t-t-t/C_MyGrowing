#include<iostream>
using namespace std;
bool zhi(int x)
{
	if (x == 1) { return 0; }
	if (x == 2) { return 1; }
	for (int i = 2; i * i <= x; i++)
	{
		if (!(x % i)) { return 0; }
	}
	return 1;
}
bool zheng(int x, int i)
{
	if (!(x % i)) { return 1; }
	return 0;
}
int main()
{
	int num;
	cin >> num;
	for (int i = 2; i <= num; i++)
	{
		if (zhi(i) && zheng(num, i)) { cout << num / i; return 0; }
	}
	return 0;
}