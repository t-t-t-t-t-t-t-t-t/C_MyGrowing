#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
int a[10000];
int f(int num)
{
	int x1 = 0, x2 = 0;
	int a[5];
	for (int i = 0; i < 4; i++)
	{
		a[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int m= a[i], n= a[3 - i];
		for (int j = 0; j < i; j++)
		{
			m *= 10;
			n *= 10;
		}
		x1 += m; x2 += n;
	}
	return abs(x1 - x2);
}
int b[100000];

int main() {

	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		int ans = 0;
		b[ans++] = num;
		while (1)
		{
			int po = f(num);
			b[ans++] = po;
			bool cnt = 0;
			for (int i = 0; i < ans-1; i++)
			{
				if (po == b[i]) { cnt = 1; }
			}
			num = po;
			if (cnt) { ans--; cout << ans << '\n'; break; }
		}
	}
	return 0;
}