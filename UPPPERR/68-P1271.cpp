#include<iostream>
using namespace std;
int a[2000000], b[2000000];
void gui(int* a, int l, int r)
{
	if (l >= r) { return; }
	int mid = l + r >> 1;
	gui(a, l, mid);
	gui(a, mid + 1, r);
	int begin1 = l, end1 = mid, begin2 = mid + 1, end2 = r;
	int left = l;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2]) { b[left++] = a[begin1++]; }
		else { b[left++] = a[begin2++]; }
	}
	while (begin1 <= end1) { b[left++] = a[begin1++]; }
	while (begin2 <= end2) { b[left++] = a[begin2++]; }
	for (int i = l; i <= r; i++)
	{
		a[i] = b[i];
	}
}
int main()
{
	int n;
	cin >>n>> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	gui(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}