#include<iostream>
using namespace std;
const int N = 1e7 + 9;
int F[N];
int main() {
	int n; cin >> n;
	int ch = 0;
	F[3] = 1;
	for (int i = 4; i <= n+3; i++) {
		ch += F[i - 3];
		ch %= 10000;
		F[i] = F[i - 1] + F[i - 2] + 2 * ch;
		F[i] %= 10000;
	}
	cout << F[n+3];
	return 0;
}