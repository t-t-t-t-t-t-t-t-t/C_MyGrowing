#include<iostream>
#include<string>
using namespace std;
int a[1000];
int main()
{
	int l, r;
	string s;

	cin >> l >> r;
	for (int i = l; i <= r; i++)
	{
		s = to_string(i);
		for (int j = 0; j< s.length(); j++)
		{
			a[s[j] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}