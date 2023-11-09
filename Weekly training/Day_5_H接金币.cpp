//https://www.luogu.com.cn/problem/P2694
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		vector<int>y(100000, 0);
		map<int, int>coin;
		int num, x;
		bool a =true ,chk=1;
		cin >> num;
		num++;
		x = 0; y[0] = 0;
		coin.insert(pair<int, int>(y[0], x));
		for (int i = 1; i < num; i++)
		{
			cin >> x >> y[i];
			if (coin.count(y[i])&&coin[y[i]]!=x) { chk = 0; }
			coin.insert(pair<int, int>(y[i], x));
		}
		if (!chk) { cout << "Notabletocatch" << endl; continue; }
		for (int i = 1; i < num; i++)
		{
			int temp = y[i],po=i;
			while (po>0)
			{
				if (temp < y[po - 1])
				{
					y[po] = y[po - 1];
					po--;
				}
				else
				{
					break;
				}
			}
			y[po] = temp;
		}
		for (int i = 0; i < num-1; i++)
		{
			if (abs(y[i + 1] - y[i]) < abs(coin[y[i + 1]] - coin[y[i]]) )
			{
				a = false;
				break;
			}
		}
		cout << (a ? "Abletocatch" : "Notabletocatch") << endl;
		a = true;
	}
	return 0;
}