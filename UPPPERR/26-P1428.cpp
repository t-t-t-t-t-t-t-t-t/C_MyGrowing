#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
		sort(a.begin(), a.end());
		cout << lower_bound(a.begin(), a.end(), x) - a.begin() << " ";//从左往右一个个把数存进去，找到的第一个大于自己的数的迭代器，（位置+1）-1；就为前面有几个小于自己的
		return 0;
	}
}
//lower_bound :{ a.begin(), a.end() }区间内查找 x ；
//并返回第一个大于x的数的迭代器，如果没有则返回 右区间的迭代器
//一般配合sort来使用 ，那么 虽然说返回的是 右区间的迭代器 ，但是 sort之后找不到比自己大的那么自己就是最大的
//因此返回的迭代器也就是自己的迭代器
//总结：lower_bound查找第一个比自己大的数的位置（用了sort，区间为 a.begin(), a.end(),x 自己也在区间内 )如没有则返回自己的位置；

