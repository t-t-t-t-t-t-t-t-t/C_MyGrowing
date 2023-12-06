#include<iostream>
#include<algorithm>
using namespace std;
const long long N = 2e6 + 9;
long long n, m, a[N];
int main()
{
	cin >> n >> m;
	for (long long i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	long long sum = 0,num = n-1;
	while (sum < m)
	{
		sum += (a[num] - a[num - 1])*(n-num);
		num--;
	}
	long long ans=a[num]+(sum - m)/(n-num-1);
	cout << ans;
	return 0;
}