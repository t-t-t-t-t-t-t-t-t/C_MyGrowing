#include<iostream>
#include<string>
using namespace std;
bool judge1(int x)/////////////////////////////////////
{
	
	for (int i = 2; i * i <= x; i++)
	{
		if (!(x % i)) { return 0; }
	}
	return 1;
}
bool judge2(int x)/////////////////////////
{
	string s;
	s = to_string(x);
	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] != s[s.length() - 1 - i]) { return 0; }
	}
	return 1;
}
bool judge3(int x)//////////////////////////////
{
	if((1000 <= x && x <= 9999) || (100000 <= x && x <= 999999)) return 0;
	return 1;
	//if (x == 11) { return 1; }
//string s;
//s = to_string(x);
//if (!(s.length() % 2)) { return 0; }
//return 1;///////////////////////////////////////////这里超时了马勒戈壁
}

int main()
{

	int l, r;
	cin >> l >> r;
	if (r >= 9999999) r = 9999999;///////////////////!!!!!!!!!!!!!!
	for (int i = (l%2==0?l+1:l); i <= r; i+=2)///////////////////////
	{	
		if (!judge3(i)) { continue; }
		if (!judge2(i)) { continue; }
		if (!judge1(i)) { continue; }
		cout << i << '\n';
	}
	return 0;
}