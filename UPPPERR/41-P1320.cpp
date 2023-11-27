#include<iostream>
#include<cmath>
using namespace std;
int a[1000000];
int main()
{
	char x, po = '0'; int num = 0, sum = 0;
	while (cin >> x)
	{
		if (x==po) { a[num]++; }
		else { po = x; a[++num]++; }
		sum++;
	}
	cout << sqrt(sum);
	for (int i = 0; i <= num; i++)
	{
		cout<< " " << a[i] ;
	}
	return 0;
}