#include<iostream>
using namespace std;
int main()
{
	char s[3];
	int a[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> s[i];
		cout << a[s[i] - 'A']<<" ";
	}
	
	return 0;
}