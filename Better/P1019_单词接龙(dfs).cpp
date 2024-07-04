#include<iostream>
#include<string>
using namespace std;
const int N = 2e5;
int ans = 0;
string a[N];
int isused[N];
int n;
bool check(string front, string s2, int len) {
	for (int i = 0; i < len; i++) {
		if (front[front.length() - len + i] != s2[i]) {
			return false;
		}
	}
	return true;
}
int deep = 1;

void dfs(string front) {
	ans = max(int(front.length()), ans);
	for (int i = 0; i < n; i++) {
		if (isused[i] < 2) {//�ж�����ÿ������ֻ��������
			for (int j = 1; j <= a[i].length() && j <= front.length(); j++) {//�жϿ��ܳ��ֵĹ��������С
				if (check(front, a[i], j)) {// ����Ƿ��й�������
					string temp = front + a[i].substr(j);// ��һ���м������ƴ��
					isused[i]++;//��ʾʹ����һ��
					//cout << deep++ << '\n' << front << ' ' << a[i] << '\n' << temp << "\n\n";
					dfs(temp);
					isused[i]--;// ����
					deep--;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string ch;
	cin >> ch;
	dfs(ch);
	cout << ans;
	return 0;
}