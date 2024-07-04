#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const long long N = 2e5;
void chu(string s, long long y) {
	if (s == "0") { cout << 0; return; }
	long long m[N] = { 0 }, ans[N] = { 0 };
	for (long long i = 0; i < s.length(); i++) {
		m[i] = s[i] - '0';
	}
	long long ch = 0;
	for (long long i = 0; i < s.length(); i++) {
		
		ans[i] = (ch * 10 + m[i]) / y;
		ch = (ch * 10 + m[i]) % y;
	}
	string n;
	int begin = 0;
	while (ans[begin] == 0&&begin<s.length()) {
		begin++;
	}
	for (int i = begin; i < s.length(); i++) {
		cout << ans[i];
	}
}
int main() {
	string a;int b;
	cin >> a >> b;
	chu(a, b);
	return 0;
}