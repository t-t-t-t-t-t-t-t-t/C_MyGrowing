#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[30][5], b[1000], x[30], y[30];
struct {
	int num, x, y;
}m[30];
int main() {
	int po = 0;
	string ans, q; cin >> ans >> q;
	int* p = a[0];
	for (int i = 0; i < ans.length(); i++) {
		*p++ = ans[i] - 'a';
		b[ans[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (!b[i]) {
			*p++ = i;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			x[a[i][j]] = i;
			y[a[i][j]] = j;
		}
	}
	x[a[5][0]] = -1;
	y[a[5][0]] = -1;
	string q2;
	for (int i = 0; i < q.length() - 1; i += 2) {
		int x1 = x[q[i] - 'a'], y1 = y[q[i] - 'a'];
		int x2 = x[q[i + 1] - 'a'], y2 = y[q[i + 1] - 'a'];
		if (x1 == -1 || x2 == -1) {
			q2 += q[i];
			q2 += q[i + 1];
		}
		else if (x1 == x2 && y1 != y2) {
			q2 += a[x2][y2] + 'a';
			q2 += a[x1][y1] + 'a';
		}
		else if (x1 != x2 && y1 == y2) {
			q2 += a[x2][y2] + 'a';
			q2 += a[x1][y1] + 'a';
		}
		else if (x1 == x2 && y1 == y2) {
			q2 += a[x2][y2] + 'a';
			q2 += a[x1][y1] + 'a';
		}
		else {
			q2 += a[x1][y2] + 'a';
			q2 += a[x2][y1] + 'a';
		}
	}
	if (q.length() & 1) {
		q2 += q[q.length() - 1];
	}
	cout << q2;

	return 0;
}