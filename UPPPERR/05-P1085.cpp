#include<iostream>
using namespace std;
int main()
{
	int a, b, sum[8] = { 0 }, m = 0,day;
	bool si=1;
	for (int i = 1; i <= 7; i++)
	{
		cin >> a >> b;
		sum[i] = (a + b);
		if (sum[i] > m)
		{
			day = i;
			m = sum[i];
		}
		if (sum[i] > 8)
		{
			si = 0;
		}
	}
	if (si) { cout << 0; }
	else { cout << day; }
	return 0;
}