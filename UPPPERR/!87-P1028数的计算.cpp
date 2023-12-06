#include<iostream>
using namespace std;
int a[10000];
int main()
{
	int n;
	cin >> n;
	int sum=0;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		a[i] = a[i - 1];
		if (i % 2 == 0)
		{
			a[i] += a[i / 2];//偶数比前一个数多了一个f（n/2）；
		}
	}
	cout << a[n];
	return 0;
}
//https://www.luogu.com.cn/blog/user15214/solution-p1028