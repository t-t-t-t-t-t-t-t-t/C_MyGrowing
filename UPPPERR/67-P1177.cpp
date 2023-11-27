
#include<iostream>
using namespace std;
int b[1000000]; int a[1000000];
void mergesort(int a[], int l, int r)
{
	if (l >= r) { return; }
	int mid = (l + r) / 2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	int j = l, k = mid + 1, cnt = l;
	while (j <= mid && k <= r)
	{
		if (a[j] <= a[k]) { b[cnt++] = a[j++]; }
		else { b[cnt++] = a[k++]; }
	}
	while (j <= mid) { b[cnt++] = a[j++]; }
	while (k <= r) { b[cnt++] = a[k++]; }
	for (int i = l; i <= r; i++)
	{
		a[i] = b[i];
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	mergesort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}