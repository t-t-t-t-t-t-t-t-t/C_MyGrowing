#include<iostream>
using namespace std;
const int N = 2e6;
struct tree {
	int child_L, child_R;//������,�����ӽڵ�
}a[N];
int dfs_tree(tree fa, int deep) {
	int ans1 = 0, ans2 = 0;
	if (fa.child_L) { ans1 = dfs_tree(a[fa.child_L], deep + 1); }//�õ���ڵ����
	if (fa.child_R) { ans2 = dfs_tree(a[fa.child_R], deep + 1); }//�õ��ҽڵ����
	return  max(ans1, max(ans2, deep));//��ڵ����,�ҽڵ����,��ǰ��ȵ����ֵ
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].child_L >> a[i].child_R;// ����
	}
	cout << dfs_tree(a[1], 1);
	return 0;
}