#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const long long N = 2e5 + 9;
char s[N];
int num[N];
int main()
{
	memset(num, 0, sizeof(num));
	char c;
	string m;
	cin >> m;
	int top1 = 0;//ջ��
	int top2 = 0;
	for (int i = 0; i < m.length(); i++) {
		if (m[i] == '[') {
			s[++top1] = m[i];
			i++;top2++;
			num[top2] = 0;//�ǵù�0����--��Ȼ����++������num[top2],�ǲ����Զ���0��
			while (m[i] <= '9' && m[i] >= '0') {
				num[top2] += (m[i ] - '0');
				num[top2] *= 10;
				i++;
			}
			i--; //��forѭ����,forѭ������i++;
			num[top2] /= 10;//������һ��10;��ȥ
		}
		else if (m[i] == ']') {
			string s1;
			while (s[top1] != '[') {
				s1 += s[top1--];
			}
			top1--;//ȥ��'['
			for (int k = 0; k < num[top2]; k++) {
				for (int j = s1.length()-1; j >= 0; j--) {
					s[++top1] = s1[j];
				}
			}
			top2--;//�õ�һ��num
		}
		else {
			s[++top1] = m[i];//��ջs�м�����ĸ
		}
	}

	for (int i = 1; i <= top1; i++) {
		cout << s[i];
	}

	return 0;
}