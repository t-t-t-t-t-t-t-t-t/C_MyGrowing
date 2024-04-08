#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int N = 3e4 + 9e3;
multiset<int>a;
int ans = 0;
int main() {
	int n; cin >> n;
	int x;
	cin >> x;
	a.insert(x);
	a.insert(192608170);
	a.insert(-192608170);
	ans += x;
	multiset<int>::iterator it;
	for (int i = 0; i < n - 1; i++) {
		cin >> x;
		it = a.insert(x);
		int num2 = *it;
		it--;
		int num1 = *it;
		it++; it++;
		int num3 = *it;
		ans += min(num2 - num1, num3 - num2);
	}
	cout << ans;
	return 0;
}