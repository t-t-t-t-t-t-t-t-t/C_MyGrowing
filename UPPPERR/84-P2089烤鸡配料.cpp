#include<iostream>
using namespace std;
int n, num=0, way[11], ans[1000][11];
void f(int sum, int nth)
{
	if (nth == 10)
	{
		if (sum == n)
		{
			for (int i = 0; i < 10; i++)
			{
				ans[num][i] = way[i];
			}
			num++;
		}
		return;
	}
	else if (sum >= n) { return; }//总数太大了；
	else {
		for (int i = 1; i <= 3; i++)
		{
			way[nth] = i;
			f(sum + i, nth + 1);
		}
	}
}
int main()
{
	cin >> n;
	if (n < 10)
	{
		cout << 0<<'\n';
		return 0;
	}
	f(0,0);
	cout << num << endl;
	for(int i= 0; i <num; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}