#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int a[10000];
int main() {
	int n,ma=-100,mi=100,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
		sum += a[i];
	}
	sum -= ma;
	sum -= mi;
	n -= 2;
	cout << fixed << setprecision(2) << sum*1.0 / n ;///×ª¸¡µãÐÍ
	return 0;
}