#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;
struct stu {
	string tu;
	string s[3];
}m[1000];
int check(stu* a, stu* b, int k) {
	int num = 0, len = min((*a).s[k].length(), (*b).s[k].length());
	for (int l = 0; l < len; l++)if ((*a).s[k][l] == (*b).s[k][l]) num++;
	if (num * 1.0 >= len * 0.9)return 1;
	return 0;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) cin >> m[i].tu >> m[i].s[0] >> m[i].s[1] >> m[i].s[2];
	for (int i = 0; i < t - 1; i++) {
		for (int j = i + 1; j < t; j++) {
			for (int k = 0; k < 3; k++) {
				if (check((m + i), (m + j), k)) {
					cout << m[i].tu << ' ' << m[j].tu << ' ' << k + 1 << "\n";
				}
			}
		}
	}
	return 0;
}