#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const long long N = 2e3;
string chu(long long x, long long y) {
	string s = to_string(x);
	long long m[N] = { 0 }, ans[N] = { 0 };
	for (long long i = 0; i < s.length(); i++) {
		m[i] = s[i] - '0';
	}
	long long ch = 0;
	for (long long i = 0; i < s.length(); i++) {
		ans[i] = (ch * 10 + m[i]) / y;
		ch= (ch * 10 + m[i]) % y;
	}
	string n;
	for (long long i = 0; i < s.length(); i++) {
		n += ans[i] + '0';
	}
	long long begin = 0;
	while (n[begin] == '0'&&begin<n.length()) {
		begin++;
	}
	string final;
	for (long long i = begin; i < n.length(); i++) {
		final += n[i];
	}
	return final;
}
int main() {
	long long a, b;
	cin >> a >> b;
	cout<<chu(a, b);
	return 0;
}