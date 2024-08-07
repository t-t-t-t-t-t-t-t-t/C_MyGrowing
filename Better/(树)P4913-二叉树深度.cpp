#include<iostream>
using namespace std;
const int N = 2e6;
struct tree {
	int child_L, child_R;//二叉树,两个子节点
}a[N];
int dfs_tree(tree fa, int deep) {
	int ans1 = 0, ans2 = 0;
	if (fa.child_L) { ans1 = dfs_tree(a[fa.child_L], deep + 1); }//得到左节点深度
	if (fa.child_R) { ans2 = dfs_tree(a[fa.child_R], deep + 1); }//得到右节点深度
	return  max(ans1, max(ans2, deep));//左节点深度,右节点深度,当前深度的最大值
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].child_L >> a[i].child_R;// 建树
	}
	cout << dfs_tree(a[1], 1);
	return 0;
}