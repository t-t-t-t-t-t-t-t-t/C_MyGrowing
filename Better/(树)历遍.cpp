#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int N = 2e5;
struct tree {
	int child_L, child_R, val;
}treeNode[N];
//ǰ������(������ȱ���(����)), �� �� ��
void preOrder1(tree* A_tree, int fa = 1) {// �ݹ�, ǰ������� faΪ�������� 
	cout << A_tree[fa].val << ' ';
	if (A_tree[fa].child_L) {//�����������
		preOrder1(A_tree, A_tree[fa].child_L);// ��������Ϊ�����
	}
	if (A_tree[fa].child_R) {
		preOrder1(A_tree, A_tree[fa].child_R);
	}
}
void preOrder2(tree* A_tree, int fa = 1) {// ջ
	tree pNode = A_tree[fa];
	stack<tree>treeStack;
	while (pNode.val || !treeStack.empty()) {
		if (pNode.val) {
			cout << pNode.val << ' ';
			treeStack.push(pNode);// ���ڵ���
			pNode = A_tree[pNode.child_L];// �ó�������,��������Ϊ�����
		}
		else {// ��ǰ���ڵ��������������,
			tree node = treeStack.top();// �ó����ڵ�
			treeStack.pop();
			pNode = A_tree[node.child_R];// �ó�������
		}
	}
}
//��������, �� �� ��
void middleOrder1(tree* A_tree, int fa = 1) {//�ݹ�
	if (A_tree[fa].child_L) {//�����������,����
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
			treeStack.push(pNode);// ���ڵ���
			pNode = A_tree[pNode.child_L];// �ó�������
		}
		else {// ��ǰ���ڵ��������������,
			tree node = treeStack.top();// �ó����ڵ�
			treeStack.pop();
			cout << node.val << ' ';
			pNode = A_tree[node.child_R];// �ó�������
		}
	}
}
//��������, �� �� ��
void postOrder1(tree* A_tree, int fa = 1) {//�ݹ�
	if (A_tree[fa].child_L) {//�����������,����
		postOrder1(A_tree, A_tree[fa].child_L);
	}
	if (A_tree[fa].child_R) {//�����������,����
		postOrder1(A_tree, A_tree[fa].child_R);//��������Ϊ�����
	}
	cout << A_tree[fa].val << ' ';
}
void postOrder21(tree* A_tree, int fa = 1) {//���ջ
	tree pNode = A_tree[fa];
	stack<tree>treeStack1;
	while (pNode.val || !treeStack1.empty()) {
		if (pNode.val) {
			treeStack1.push(pNode);// ���ڵ���
			pNode = A_tree[pNode.child_L];// �ó�������,��������Ϊ�����
		}
		else {// ��ǰ���ڵ��������������,
			tree node = treeStack1.top();
			treeStack1.pop();
			postOrder21(A_tree, node.child_R);// ��������,��������Ϊ ���ڵ�
			cout << node.val << ' ';// ��������
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
	cout << "ǰ�����:\n";
	preOrder1(treeNode);
	cout << '\n';
	preOrder2(treeNode);
	cout << '\n';
	cout << "�������:\n";
	middleOrder1(treeNode);
	cout << '\n';
	middleOrder2(treeNode);
	cout << '\n';
	cout << "�������:\n";
	postOrder1(treeNode);
	cout << '\n';
	postOrder21(treeNode);
	cout << '\n';
	cout << '\n';
	cout << "BFS�������:\n";
	bfsTree(treeNode);
	cout << '\n';
	return 0;
}