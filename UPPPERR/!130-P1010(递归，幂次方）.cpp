#include<iostream>
#include<cmath>
using namespace std;
void fen(int x) {
	for (int i = 14; i >= 0; i--)
	{
		if (pow(2, i) <= x) {
			if (i == 0) {
				cout << "2(0)";
			}
			else if (i == 1) {
				cout << 2;
			}
			else {
				int part1 = pow(2, i);// 即为2^i，后面只需再次分割i 
				cout << "2(";
				fen(i);
				cout << ')';
			}
			int part2 = x -= pow(2, i);//剩下的部分（如果有的话），还需再分割
			if (part2) {
				cout << '+';
			}
		}
	}
}
int main() {
	int n; cin >> n;
	fen(n);
	return 0;
}