#include<iostream>
using namespace std;
int a[60009];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		a[i] %= 7;
	}
	int l=0,r=0,ma=-1e9;
	for (int num = 0; num < 7; num++) {
		l = 0, r = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == num) {
				l = i;
				break;
			}
		}
		if (num == 0) {/////////////////////   0ÊÇÌØÊâµÄ
			l = 0;
		}
		for (int j = n; j >= 1; j--) {
			if (a[j] == num) {
				r = j;
				break;
			}
		}
		ma = max(ma, r - l);
	}
	cout << ma;
	return 0;
}