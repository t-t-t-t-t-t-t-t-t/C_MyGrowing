//https://www.cnblogs.com/didiaoxiaoguai/p/11602967.html
#include<iostream>
#include<string>
using namespace std;
int ans[1000], n;
int num = 3;
int f(int po) {
	if (po == 0)return 0;
	if (po == 1)return 3;
	if (po == 2)return 6;
	if (po == 3)return 6;
	return f(po - 1) + 2 * f(po - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << f(n)<<'\n';
	}
	return 0;
}