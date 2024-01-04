#include<iostream>
#include<string>
#include <cstring>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		char a[1000], b[1000], c[1000];		cin >> a >> b;
		char* p = a; char* q = b; char* s = c;
		a[strlen(a)] = '\0';b[strlen(b)] = '\0';c[strlen(a)] = '\0';
		while (*p != '\0') {
			*s = (((char(*p + (*q - '0')) <= 'z' && *p <= 'z' && *p >= 'a') || ((char(*p + (*q - '0')) <= 'Z' && *p <= 'Z' && *p >= 'A'))) ? char(*p + (*q - '0')) : char(*p + (*q - '0' - 26)));
			s++; p++; q++;
			if (*q == '\0')q = b;
		}
		cout << c << "\n";
	}
	return 0;
}