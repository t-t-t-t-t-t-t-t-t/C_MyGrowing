#include<iostream>
using namespace std;
int a[30000];
int main()
{
	int l, r;
	cin >> l >> r;
	int num = 0;
	for (int i = l; i <= r; i++)
	{
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
		{
			a[num++] = i;;
		}
	}
	cout << num << '\n';
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}