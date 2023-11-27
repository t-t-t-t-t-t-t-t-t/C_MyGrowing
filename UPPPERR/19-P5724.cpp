#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
void quicksort(int *a, int l, int r) {
	if (l >= r) { return; }
	int begin = l, end = r, key = a[begin];
	while (begin < end)
	{
		while (a[end] >= key && end > begin)
		{
			end--;
		}
		a[begin] = a[end];
		while (a[begin]<=key && end>begin)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	int mid = begin;
	quicksort(a, l, mid - 1);
	quicksort(a, mid + 1, r);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//sort(a, a + n);  // 当然自己也可以写个排序；
	//快速排序；
	quicksort(a, 0, n - 1);
	cout << a[n - 1] - a[0];
	return 0;
}