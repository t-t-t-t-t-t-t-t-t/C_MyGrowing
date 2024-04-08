#include<iostream>
using namespace std;
const int N = 2e5 + 9;
struct lian {
	int l, r;
}a[N];
void add(int po, int ins, int di) {
	if (di == 1) {
		a[ins].r = a[po].r;
		a[ins].l = po;
		a[a[po].r].l = ins;
		a[po].r = ins;
	}
	else {
		a[ins].r = po;
		a[ins].l = a[po].l;
		a[a[po].l].r = ins;
		a[po].l = ins;
	}
	return;
}
void erase(int po) {
	if (a[po].r == -1)return;////////////////
	a[a[po].l].r = a[po].r;
	a[a[po].r].l = a[po].l;
	a[po].r = -1;
	a[po].l = -1;
	return;
}
int main() {
	a[1].l = 1;
	a[1].r = 1;
	a[0].r = 0;
	a[0].l = 0;
	add(0, 1, 1);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int po, dis;
		cin >> po >> dis;
		add(po, i, dis);
	}
	int num; cin >> num;
	while (num--) {
		int po;
		cin >> po;
		erase(po);
	}
	int i = 0;
	do {
		cout << a[i].r << ' ';
		i = a[i].r;
	} while (a[i].r != 0);
	return 0;
}