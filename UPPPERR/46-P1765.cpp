#include<iostream>
#include<string>
using namespace std;
int a[4000] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };
int main()
{
	int sum = 0;
	string b; char m = ' ';
	getline(cin, b);
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] <= 'z' && b[i] >= 'a')
		{
			sum += a[b[i] - 'a'];
		}
		if (b[i] == ' ')///////////////////
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}