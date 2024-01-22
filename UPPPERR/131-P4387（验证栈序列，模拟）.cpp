#include<iostream>
using namespace std;
const int N = 2e5;
int a[N], b[N],s[N];
int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		int top1 = 0,top2=0;
		for (int i = 0; i < n; i++) {
			s[++top1] = a[i];
			while(s[top1] == b[top2]) {
				top1--;
				top2++;
				if (!top1)break;
			}
		}
		if (!top1) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
	}
	return 0;
}
//两个栈来模拟进和出栈