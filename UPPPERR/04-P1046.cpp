#include<iostream>
using namespace std;
int main()
{
	int a[20],h,add=30,ans=0;
	for (int i = 1; i <= 10; i++)
	{
		cin >> a[i];
		
	}
	cin >> h;
	for (int i = 1; i <= 10; i++)
	{
		if (a[i] <= h + add) { ans++; }
	}
	cout << ans;
	return 0;
}