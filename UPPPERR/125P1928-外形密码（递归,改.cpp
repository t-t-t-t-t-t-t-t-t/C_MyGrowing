#include<iostream>
#include<string>
using namespace std;
string m;
int p = 0;
string read() {
	string s;
	string b;
	char a;
	while (p<m.length()) {
		a = m[p++];
		if (a == '[') {
			int num=0;
			while (m[p] <= '9' && m[p] >= '0') {
				num += (m[p++] - '0');
				num *= 10;
			}
			num /= 10;
			b = read();
			while (num--) {
				s += b;
			}
		}
		else if (a == ']') {
			return s;
		}
		else {
			s += a;
		}
	}
	return s;
}
int main() {
	cin >> m;
	cout << read();
	return 0;
}