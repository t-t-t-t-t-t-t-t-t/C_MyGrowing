#include<iostream>
using namespace std;
int main()
{
	double s, start = 2,ans=0,now=0;
	cin >> s;
	while (now < s)
	{
		now += start;
		start *= 0.98;
		ans++;
	}
	cout << ans;
}