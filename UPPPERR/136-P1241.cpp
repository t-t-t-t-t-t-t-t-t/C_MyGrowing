#include<iostream>
#include<string>
using namespace std;
const int N = 2e5 + 9;
int stack[N];
bool ok[N];//�жϸ��ַ��Ƿ�ƥ��,������" ] " ���� " ) ",������������������Ƿ�ƥ��
string s;
int main() {
	int top = 0, bottom = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			stack[++top] = i;//��һ��ջ����¼���ұߵ���һ��������
		}
		else if (top) {// ջ���յ����
			if (s[stack[top]] == '(' && s[i] == ')' || s[stack[top]] == '[' && s[i] == ']')
			{
				ok[i] = 1;
				ok[stack[top]] = 1;//������Եı��һ��,�����ʱ���ԭ�����

				top--;
			}
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (ok[i])  cout << s[i]; //�����ƥ��ľ�ԭ������
		else {//������
			if (s[i] == '[' || s[i] == ']') { cout << "[]"; }
			else {
				cout << "()";
			}
		}
	}
	return 0;
}