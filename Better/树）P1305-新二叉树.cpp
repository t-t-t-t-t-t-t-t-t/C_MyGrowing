#include<iostream>
using namespace std;
const int N = 2e5;
struct tree {
	char child_R,child_L;
}a[N];
void preOrder(char root) {
	if (root == '*') { return; }
	cout << root;
	if (a[root].child_L != '*') {
		preOrder(a[root].child_L);
	}
	if (a[root].child_R != '*') {
		preOrder(a[root].child_R);
	}
}
int main() {
	int n; cin >> n;
	char gen; cin >> gen;
	cin >> a[gen].child_L;
	cin >> a[gen].child_R;
	for (int i = 2; i <= n; i++) {
		char root; cin >> root;
		cin >> a[root].child_L;
		cin >> a[root].child_R;
	}
	preOrder(gen);
	return 0;
}