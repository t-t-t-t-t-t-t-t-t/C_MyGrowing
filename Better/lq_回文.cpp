#include<iostream>
#include<string>
using namespace std;
bool check(string s) {
	for (int l = 0, r = s.length() - 1; l <= s.length() / 2; l++, r--) {
		if (s[l] != s[r]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	string s; cin >> s;
	if (check(s)) {
		cout << "Y";
	}
	else {
		cout << "N";
	}
	return 0;
}