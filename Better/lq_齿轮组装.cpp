#include<iostream>
using namespace std;
int a[200005];

int main() {
	int n, m; cin >> n >> m;
	int x,ma=-10;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++; //���г��ֵ����ٶ���ͬ����ôֻ��Ҫ�ҵ������뾶���q���ĳ��־�ok
		ma = max(ma, x);
	}
	int q;
	while (m--) {
		cin >> q;
		int cnt = 0;
		for (int i = 0; i <= ma / q; i++) {
			if (a[i] && a[i * q]) {
				if (i != i * q || i == i * q && a[i] > 1) {
					cnt = 1;
				}
			}
		}
		if (cnt||n==1&&q==1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}