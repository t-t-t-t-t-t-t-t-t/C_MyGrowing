#include<iostream>
using namespace std;
const int N = 1e7+9;
int F[N];
int main() {
	int n; cin >> n;
	int ch = 0;
	F[0] = 1; F[1] = 1; F[2] = 2;
	for (int i = 3; i <= n; i++) {
		ch += F[i - 3];
		ch %= 10000;
		F[i] = F[i - 1] + F[i - 2] + 2 * ch;
		F[i] %= 10000;
	}
	cout << F[n];
	return 0;
}