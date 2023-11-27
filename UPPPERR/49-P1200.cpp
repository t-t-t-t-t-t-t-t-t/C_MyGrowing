#include<iostream>
#include<string>
using namespace std;
int main()
{
	string m, n;
	cin >> m >> n;
	int sum1 = 1, sum2 = 1;
	for (int i = 0; i < m.length(); i++)
	{
		sum1 *= int(m[i] - 'A' + 1);
	}
	for (int i = 0; i < n.length(); i++)
	{
		sum2 *= int(n[i] - 'A' + 1);
	}
	if (sum1 % 47 == sum2 % 47)
	{
		cout << "GO";
	}
	else { cout << "STAY"; }
	return 0;
}