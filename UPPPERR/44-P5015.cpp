#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	string s;
	int sum = 0;
	while (cin >> s)//////////////
	{
		sum += s.length();
	}
	cout << sum;
	return 0;
}