#include<iostream>
using namespace std;
long long result=1,base,power,mod;
int main() {
	cin >> base >> power >> mod;
	result = 1;
	long long po = power;
	long long ba = base;
	while (power) {
		if (power & 1) {
			result *= base;
			result %= mod;
		}
		base *= base;
		base %= mod;
		power /= 2;
	}
	result %= mod;
	cout << ba << '^' << po << " mod " << mod << '=' << result;
	return 0;
}