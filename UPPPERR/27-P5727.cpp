#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int a[10000], n = 1;
	a[0] = num;
	while (num != 1)
	{
		if (!(num % 2)) { a[n++] = (num /= 2); }
		else { num = num * 3 + 1; a[n++] = num; }
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}