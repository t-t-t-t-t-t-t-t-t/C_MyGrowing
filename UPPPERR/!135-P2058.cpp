#include<iostream>
using namespace std;
const int N = 3e5 + 9;
int a[N];
struct pe {
	int it, x;
}m[N];
int main() {
	int p = 0,begin=1;
	int num,ans=0; cin >> num;
	while (num--) {
		int t, n;
		cin >> t >> n;
		while (n--) {
			m[++p].it = t;
			cin >> m[p].x;
			if (!a[m[p].x]) { ans++; }
			a[m[p].x]++;
		}
		while (m[p].it - m[begin].it + 1 > 86400) {
			a[m[begin].x]--;
			if (!a[m[begin].x]) {
				ans--;
			}
			begin++;
		}
		cout << ans<<'\n';
	}
	return 0;
}