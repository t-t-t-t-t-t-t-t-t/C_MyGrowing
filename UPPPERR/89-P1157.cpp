#include<iostream>
#include<iomanip>
using namespace std; 
long long a[1000];
int main()
{
	long long n, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	int U = 1 << n;
	for (int S = U-1; S >=0; S--)
	{
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			if (S & (1 << i))
			{
				num++;
			}
		}
		if (num == r)
		{
			for (int i = n-1; i  >=0; i--)
			{
				if (S & (1 << i))
				{
					cout <<setw(3)<< a[n-i-1];
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
