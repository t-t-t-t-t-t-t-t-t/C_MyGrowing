//https://www.luogu.com.cn/problem/P3397
#include<iostream>
#include<cstring>//////////注意头文件《memset。的
using namespace std;
int main()
{
	int n,x1,x2,y1,y2;
	int t;
	cin >> n >> t;
	int a[1002][1002];///边界在102/////////
	memset(a, 0, sizeof(a));			//
	for (int i = 1; i <= t; i++)		//
	{									//
		cin >> x1 >> y1 >> x2 >> y2;	//
		a[x1][y1]++;					//
		a[x2 + 1][y1]--;				//
		a[x1][y2 + 1]--;				//
		a[x2 + 1][y2 + 1]++;//<<<<<<<<<///
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] += (a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}