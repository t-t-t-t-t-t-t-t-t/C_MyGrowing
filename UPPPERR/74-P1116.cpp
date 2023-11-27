#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int main()
{
	int n,x;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
		sort(a.begin(), a.end());
		sum+=a.end()-lower_bound(a.begin(), a.end(), x)-1;
	}
	cout << sum;
	return 0;
}