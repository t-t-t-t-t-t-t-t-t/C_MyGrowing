#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int po = i;
		while (po >= 0)
		{
			if (temp < a[po - 1])
			{
				a[po] = a[po - 1];
				po--;
			}
			else { break; }
		}
		a[po] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;

}