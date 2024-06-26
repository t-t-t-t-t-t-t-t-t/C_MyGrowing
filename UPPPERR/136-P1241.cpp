#include<iostream>
#include<string>
using namespace std;
const int N = 2e5 + 9;
int stack[N];
bool ok[N];//判断该字符是否被匹配,右括号" ] " 或者 " ) ",和离它最近的左括号是否匹配
string s;
int main() {
	int top = 0, bottom = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			stack[++top] = i;//用一个栈来记录最右边的那一个左括号
		}
		else if (top) {// 栈不空的情况
			if (s[stack[top]] == '(' && s[i] == ')' || s[stack[top]] == '[' && s[i] == ']')
			{
				ok[i] = 1;
				ok[stack[top]] = 1;//两个配对的标记一下,输出的时候就原样输出

				top--;
			}
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (ok[i])  cout << s[i]; //如果是匹配的就原样输入
		else {//否则补齐
			if (s[i] == '[' || s[i] == ']') { cout << "[]"; }
			else {
				cout << "()";
			}
		}
	}
	return 0;
}