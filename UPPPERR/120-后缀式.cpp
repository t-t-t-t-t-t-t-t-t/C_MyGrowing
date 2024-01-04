#include<iostream>
#include<stack>
using namespace std;
long long s[100000];

int main() {
	char c;
	long long num = 0;
	long long n = 0;
	while ((c = getchar()) != '@') {
		if (c >= '0' && c <= '9') {
			num *= 10;
			num += (c - '0');
		}
		else if (c == '.') {
			s[++n] = num;
			num = 0;
		}
		else if (c == '+') {
			s[n - 1] = s[n - 1] + s[n];
			n--;
		}
		else if (c == '-') {
			s[n - 1] = s[n - 1] - s[n];
			n--;
		}
		else if (c == '*') {
			s[n - 1] = s[n - 1] * s[n];
			n--;
		}
		else if (c == '/') {
			s[n - 1] = s[n - 1] / s[n];
			n--;
		}
	}
	cout << s[1];
	return 0;
}