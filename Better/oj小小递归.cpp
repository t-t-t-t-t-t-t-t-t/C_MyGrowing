#include<cstring>
#include<iostream>
#include<string>
using namespace std;
class Mystring {
	string* content;
	int n;
	string option;
public:
	Mystring(string* s, int _n) :n(_n), option(""), content(new string[_n + 1]) {
		for (int i = 1; i <= n; i++) {
			content[i] = string(s[i]);
		}
	}
	string copy(int p, int x, int len) {
		return content[p].substr(x, len);
	}
	bool check(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] < '0' || s[i] > '9') {
				return 0;
			}
		}
		return 1;
	}
	string add(string s1, string s2) {
		if ( check(s1) && check(s2)&&toNum(s1)<=99999 && toNum(s2) <= 99999) {
			int len = max(s1.length(), s2.length());
			len += 5;
			int* save = new int[len];
			int* a = new int[len];
			int* b = new int[len];
			for (int i = 0; i < len; i++) {
				save[i] = 0;
				a[i] = 0;
				b[i] = 0;
			}

			for (int i = 0; i < s1.length(); i++) {
				a[i] = s1[s1.length() - i - 1] - '0';
			}
			for (int i = 0; i < s2.length(); i++) {
				b[i] = s2[s2.length() - i - 1] - '0';
			}
			int ch = 0;
			for (int i = 0; i < len; i++) {
				save[i] += a[i] + b[i] + ch;
				ch = save[i] / 10;
				save[i] %= 10;
			}
			int begin = len - 1;
			while (save[begin] == 0 && begin) {
				begin--;
			}
			string s;
			for (int i = begin; i >= 0; i--) {
				s += save[i] + '0';
			}
			return s;
		}
		else {
			return s1 + s2;
		}
	}
	int find(string s, int p) {
		int pos = content[p].find(s, 0);
		return (pos == -1 ? s.length() : pos);
	}
	int rfind(string s, int p) {
		int pos = content[p].rfind(s, content[p].length() - 1);
		return (pos == -1 ? s.length() : pos);
	}
	void insert(string s, int p, int x) {
		content[p].insert(x, s);
	}
	void reset(string s, int p) {
		content[p] = s;
	}
	void print(int p) {
		cout << content[p] << '\n';
	}
	void printAll() {
		for (int i = 1; i <= n; i++) {
			cout << content[i] << '\n';
		}
	}
	void action() {
		while (option != "over") {
			run();
		}
	}
	int toNum(string s) {
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			ans += (s[i] - '0');
			ans *= 10;
		}
		ans /= 10;
		return ans;
	}
	string run() {
		cin >> option;
		if (option == "copy") {
			int p = toNum(run());
			int x = toNum(run());
			int len = toNum(run());
			//cout   << "copy" << ' '<<p<<' '<<x<<' '<<len << '\n';
			return copy(p, x, len);
		}
		else if (option == "add") {
			string s1 = run();
			string s2 = run();
			//cout   << "add" << ' ' << s1 << ' ' << s2 << '\n';
			return add(s1, s2);
		}
		else if (option == "find") {
			string s = run();
			int p = toNum(run());
			//cout   << "find" << ' ' << s << ' ' << p << '\n';
			return to_string(find(s, p));
		}
		else if (option == "rfind") {
			string s = run();
			int p = toNum(run());
			//cout   << "rfind" << ' ' << s << ' ' << p << '\n';
			return to_string(rfind(s, p));
		}
		else if (option == "insert") {
			string s = run();
			int p = toNum(run());
			int x = toNum(run());
			//cout   <<  "insert" << ' ' << s << ' ' << p<<' '<<x << '\n';
			insert(s, p, x);
		}
		else if (option == "reset") {
			string s = run();
			int p = toNum(run());
			//cout   << "reset" << ' ' << s << ' ' << p << '\n';
			reset(s, p);
		}
		else if (option == "print") {
			int p = toNum(run());
			//cout   << "print" << ' ' << p << '\n';
			print(p);
		}
		else if (option == "printall") {
			printAll();
		}
		else {
			return option;
		}
		return "";
	}
};

int main() {
	int  n; cin >> n;
	string* s = new string[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	Mystring ss(s, n);
	ss.action();
	return 0;
}