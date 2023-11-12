#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	int gap = a.size();
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < a.size() - gap; i++)
		{
			int po = i;
			int temp = a[gap + po];
			while (po >= 0)
			{
				if (temp < a[po])
				{
					a[gap + po] = a[po];
					po -= gap;
				}
				else { break; }
			}
			a[po + gap] = temp;
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i]<<" ";
	}
	return 0;
}