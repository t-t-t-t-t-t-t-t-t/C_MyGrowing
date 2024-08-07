#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int N = 2e5;
struct tree {
	int child_L, child_R, val;
}treeNode[N];
//前序历遍(深度优先遍历(左先)), 根 左 右
void preOrder1(tree* A_tree, int fa = 1) {// 递归, 前序遍历以 fa为根结点的树 
	cout << A_tree[fa].val << ' ';
	if (A_tree[fa].child_L) {//如果有左子树
		preOrder1(A_tree, A_tree[fa].child_L);// 以左子树为根结点
	}
	if (A_tree[fa].child_R) {
		preOrder1(A_tree, A_tree[fa].child_R);
	}
}
void preOrder2(tree* A_tree, int fa = 1) {// 栈
	tree pNode = A_tree[fa];
	stack<tree>treeStack;
	while (pNode.val || !treeStack.empty()) {
		if (pNode.val) {
			cout << pNode.val << ' ';
			treeStack.push(pNode);// 父节点存进
			pNode = A_tree[pNode.child_L];// 拿出左子树,以左子树为根结点
		}
		else {// 当前父节点的左子树不存在,
			tree node = treeStack.top();// 拿出父节点
			treeStack.pop();
			pNode = A_tree[node.child_R];// 拿出右子树
		}
	}
}
//中序历遍, 左 根 右
void middleOrder1(tree* A_tree, int fa = 1) {//递归
	if (A_tree[fa].child_L) {//如果有左子树,先左
		middleOrder1(A_tree, A_tree[fa].child_L);
	}
	cout << A_tree[fa].val << ' ';
	if (A_tree[fa].child_R) {
		middleOrder1(A_tree, A_tree[fa].child_R);
	}
}
void middleOrder2(tree* A_tree, int fa = 1) {
	tree pNode = A_tree[fa];
	stack<tree>treeStack;
	while (pNode.val || !treeStack.empty()) {
		if (pNode.val) {
			treeStack.push(pNode);// 父节点存进
			pNode = A_tree[pNode.child_L];// 拿出左子树
		}
		else {// 当前父节点的左子树不存在,
			tree node = treeStack.top();// 拿出父节点
			treeStack.pop();
			cout << node.val << ' ';
			pNode = A_tree[node.child_R];// 拿出右子树
		}
	}
}
//后序历遍, 左 右 根
void postOrder1(tree* A_tree, int fa = 1) {//递归
	if (A_tree[fa].child_L) {//如果有左子树,先左
		postOrder1(A_tree, A_tree[fa].child_L);
	}
	if (A_tree[fa].child_R) {//如果有右子树,先右
		postOrder1(A_tree, A_tree[fa].child_R);//以右子树为根结点
	}
	cout << A_tree[fa].val << ' ';
}
void postOrder21(tree* A_tree, int fa = 1) {//半个栈
	tree pNode = A_tree[fa];
	stack<tree>treeStack1;
	while (pNode.val || !treeStack1.empty()) {
		if (pNode.val) {
			treeStack1.push(pNode);// 父节点存进
			pNode = A_tree[pNode.child_L];// 拿出左子树,以左子树为根结点
		}
		else {// 当前父节点的左子树不存在,
			tree node = treeStack1.top();
			treeStack1.pop();
			postOrder21(A_tree, node.child_R);// 后续历遍,以右子树为 根节点
			cout << node.val << ' ';// 输出根结点
		}
	}
}

void bfsTree(tree* A_tree, int fa = 1) {
	tree root = A_tree[fa];
	queue<tree>treeQueue;
	treeQueue.push(root);
	while (!treeQueue.empty()) {
		tree pNode = treeQueue.front();
		cout << pNode.val << ' ';
		treeQueue.pop();
		if (A_tree[pNode.child_L].val) {
			treeQueue.push(A_tree[pNode.child_L]);
		}
		if (A_tree[pNode.child_R].val) {
			treeQueue.push(A_tree[pNode.child_R]);
		}
	}
}
int main() {
	int n; cin >> n;
	treeNode[0].val = 0;
	for (int i = 1; i <= n; i++) {
		cin >> treeNode[i].child_L >> treeNode[i].child_R;
		treeNode[i].val = i;
	}
	cout << "前序遍历:\n";
	preOrder1(treeNode);
	cout << '\n';
	preOrder2(treeNode);
	cout << '\n';
	cout << "中序遍历:\n";
	middleOrder1(treeNode);
	cout << '\n';
	middleOrder2(treeNode);
	cout << '\n';
	cout << "后序遍历:\n";
	postOrder1(treeNode);
	cout << '\n';
	postOrder21(treeNode);
	cout << '\n';
	cout << '\n';
	cout << "BFS层次历遍:\n";
	bfsTree(treeNode);
	cout << '\n';
	return 0;
}