#include<iostream>
using namespace std;
int main()
{
	int n,num=1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%02d", num++);
		}
		cout << '\n';
	}
	cout << '\n';
	num = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n - i; k++)
		{
			cout << "  ";////Á½¸ö¿Õ¸ñ
		}
		for (int j = 1; j <= i; j++)
		{
			printf("%02d", num++);
		}
		cout << '\n';
	}
	return 0;
}