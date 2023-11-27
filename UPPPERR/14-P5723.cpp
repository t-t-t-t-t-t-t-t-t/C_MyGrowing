#include<iostream>
using namespace std;
bool judge(int x)
{
	if (x == 1) { return 0; }
	if (x == 2) { return 1; }
	for (int i = 2; i * i <= x; i++)
	{
		if (!(x % i)) { return 0; }
	}
	return 1;
}
int main()
{
	int sum = 0, L,i=0,ans=0;
	cin >> L;
	while (1)
	{
		i++;
		if (judge(i))
		{
			sum += i;///////////////
			if (sum > L)
			{
				sum -= i;
				break;
			}
			cout << i << '\n';
			ans++;
		}
	}
	cout << ans;
	return 0;
}