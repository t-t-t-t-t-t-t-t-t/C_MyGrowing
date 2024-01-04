#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
stack<char>a;
int main() {
	string s; cin >> s;
	string s2;
	for (int i = 0; i < s.length(); i++) {
		while(a.size() && a.top() > s[i]) {
			a.pop();
		}
		if(a.size()) {
			s2 += a.top();
		}
		a.push(s[i]);
	}
	cout << s2;
	return 0;
}