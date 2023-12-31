#include<iostream>
#include<vector>
using namespace std;
void Quicksort(vector<int>& a, int left, int right)
{
	if (left >= right) { return; }//left = right 就停下来；
	int begin = left;
	int end = right;
	int key = a[begin];
	while (begin < end)///反过来想，结束时end=begin；
	{
		while (a[end] >= key && end > begin)//end  右边都是大于等于 key
		{
			end--;
		}
		a[begin] = a[end];
		while (a[begin] <= key && end>begin)//begin 左边都是小于等于 key
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	int po = begin;
	Quicksort(a, left, po - 1);
	Quicksort(a, po + 1, right);
}
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	Quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;

}