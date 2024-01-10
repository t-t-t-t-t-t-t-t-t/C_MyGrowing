#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int sav[N];
int add1[N], add2[N];
void Fibo(int x) {

	add1[0] = 1;
	add2[0] = 1;
	if (x < 3) {
		sav[0] = 1;
		return;
	}
	for (int i = 3; i <= x; i++) {
		memset(sav, 0, N);
		for (int i = 0; i < N; i++) {
			sav[i] += add1[i] + add2[i];
		}
		for (int i = 0; i < N; i++) {
			sav[i + 1] += sav[i] / 10;
			sav[i] %= 10;
		}
		memcpy(add1, add2, N);
		memcpy(add2, sav, N);

	}
}
string sol(int x) {
	Fibo(x);
	string ans;
	int begin = N;
	while (!sav[begin]) {
		begin--;
	}
	for (int i = begin; i >= 0; i--) {
		ans += sav[i] + '0';
	}
	return ans;
}
int main() {
	int m, n;
	cin >> m >> n;
	cout << sol(n - m + 1);

	return 0;
}