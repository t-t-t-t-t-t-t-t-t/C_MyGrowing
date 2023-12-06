#include<iostream>
#include<cstring>
using namespace std;
long long b[10005];
int a[2005], sav[2005], result[2005];
void first(int x)
{
	memset(a, 0, sizeof(a));
	for (int i = 0; x != 0; i++)
	{
		a[i] = x % 10;
		x /= 10;
	}
}
void cheng(int x)
{
	memset(sav, 0, sizeof(sav));
	first(x);
	int ch = 0;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			sav[i + j] += a[i] * result[j];
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		sav[i + 1] += sav[i] / 10;
		sav[i] %= 10;
	}
	memcpy(result, sav, sizeof(a));
}
int main()
{
	result[0] = 1;
	long long num, sum = 0;
	cin >> num;
	if (num <= 4)
	{
		cout << num << '\n' << num;
		return 0;
	}
	long long n;
	for (long long i = 2; sum < num; i++)
	{
		sum += i;
		b[i]++;
		n = i;
	}
	if (sum > num)
	{
		if (sum - num == 1) { b[2]--; b[n]--; b[n + 1]++; }
		else { b[sum - num]--; }
	}
	for (long long i = 2; i < num; i++)
	{
		if (b[i]) { cheng(i); }
	}
	for (long long i = 2; i < num; i++)
	{
		if (b[i]) { cout << i << ' '; }
	}
	cout << '\n';
	int len = 100;
	while (!result[len]) { len--; }
	for (int i = len; i >= 0; i--)
	{
		cout << result[i];
	}
	return 0;
}
