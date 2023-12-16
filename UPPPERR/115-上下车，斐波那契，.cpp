#include<iostream>
using namespace std;
int up[10000], down[10000];
int a, n, m, x, b;
int upp(int po) {
	if (po == 1)return a;
	if (po == 2)return b;
	return upp(po - 1) + upp(po - 2);
}
int downp(int po) {
	if (po == 1)return 0;
	if (po == 2)return b;
	return upp(po - 1);
}
int ans(int po) {
	if (po == 1)return a;
	if (po == 2)return a;
	return ans(po-1)+upp(po) - downp(po);
}
int main()
{
	cin >> a >> n >> m >> x;
	for (int i = 0;; i++)
	{
		b = i;
		if (m == ans(n - 1)) {
			break;
		}
	}
	cout << ans(x);
	return 0;
}