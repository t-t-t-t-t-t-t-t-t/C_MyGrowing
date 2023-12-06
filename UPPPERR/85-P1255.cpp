#include<iostream>
#include<cstring>
using namespace std;
int ar1[10000], ar2[10000],ar3[10000];
void a()
{
	for (int i = 0; i < 9000; i++)
	{
		ar3[i] = ar1[i] + ar2[i];
	}
	for (int i = 0; i < 9000; i++)
	{
		ar3[i + 1] += ar3[i] / 10;
		ar3[i] %= 10;
	}
	memcpy(ar1, ar2, sizeof(ar1));
	memcpy(ar2, ar3, sizeof(ar2));
}
int main()
{
	int n;
	cin >> n;
	if (n <= 1)
	{
		cout << 1;
		return 0;
	}
	ar1[0] = 1;
	ar2[0] = 1;
	for (int i = 1; i < n; i++)
	{
		a();
	}
	int len = 9000;
	while (!ar3[len])
	{
		len--;
	}
	for (int i = len; i >= 0; i--)
	{
		cout << ar3[i];
	}
	return 0;
}