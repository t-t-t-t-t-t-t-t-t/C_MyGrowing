#include<iostream>
#include<string>
using namespace std;
int a[1000009],b[1000009];
int main() {
	string  s;
	cin >> s;
	bool y = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Z') {
			y = 1;
		}
		if (y == 1 && (s[i] == 'X' || s[i] == 'Y')) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'X') {
			a[i] = 1;
			b[i] = 0;
		}
		else if (s[i] == 'Y') {
			a[i] = 0;
			b[i] = 1;
		}
		else {
			a[i] = b[i] = 0;
		}
	}
	for (int i = 0; i < s.length(); i++) {
		cout << a[i];
	}
	cout << '\n';
	for (int i = 0; i < s.length(); i++) {
		cout << b[i];
	}


	return 0;
}