#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
void solution(string middle, string pre) {
	if (pre.empty()) { return; }
	char root = pre[0];// ����ǰ��,���ĸ����
	int mid = middle.find(root);
	// ���ݸ��ڵ�ֳ�����������
	string Child_L_mid = middle.substr(0, mid);
	string Child_R_mid = middle.substr(mid + 1);
	// ��������ǰ��
	string Child_L_pre = pre.substr(1, mid);
	string Child_R_pre = pre.substr(mid+1);
	solution(Child_L_mid, Child_L_pre);
	solution(Child_R_mid, Child_R_pre);
	cout << root;
}
int main() {
	string middleOrder, preOrder;
	cin >> middleOrder >> preOrder;
	solution(middleOrder, preOrder);
	return 0;
}