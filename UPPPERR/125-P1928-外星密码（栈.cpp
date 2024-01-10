#include<iostream>
#include<string>
using namespace std;
const long long N = 2e5 + 9;
char s[N];
int num[N];
int main()
{
	char c;
	string m;
	cin >> m;
	int top1 = 0;
	int top2 = 0;
	for (int i = 0; i < m.length(); i++) {
		if (m[i] == '[') {
			s[++top1] = m[i];
			num[++top2] = m[i + 1] - '0';
			i++;
		}
		else if (m[i] == ']') {
			string s1;
			while (s[top1] != '[') {
				s1 += s[top1];
				top1--;
			}
			top1--;
			for (int i = 0; i < num[top2]; i++) {
				for (int j = s1.length()-1; j >= 0; j--) {
					s[++top1] = s1[j];
				}
			}
			top2--;
		}
		else {
			s[++top1] = m[i];
		}
	}
	for (int i = 0; i <= top1; i++) {
		cout << s[i];
	}

	return 0;
}