#include<iostream>
#include<algorithm>
using namespace std;
int b[7],a[7], jiang[8],num=0;
int main() {
	int n,po;
	cin >> n;
	for (int i = 0; i < 7; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 7);
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < 7; i++)
		{
			cin >> b[i];
			for (int j = 0; j < 7; j++)
			{
				if (b[i] == a[j])
				{
					num++;
				}
			}
		}
		jiang[num]++;
		num = 0;
	}
	cout << jiang[7]<<" ";
	for (int i = 6; i >=1; i--)
	{
		cout << jiang[i] << " ";
	}
	return 0;
}