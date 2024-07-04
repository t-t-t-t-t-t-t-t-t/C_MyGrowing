#include<iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node() {
		val = 0;
		next = NULL;
	}
};
class CList {
	Node* head;
public:
	CList(int* a, int n) {
		creatList(a, n);
	}
	void quchong() {
		Node* pNode1 = head;
		while (pNode1 != NULL) {
			Node* pNode2 = pNode1->next;
			while (pNode2 != NULL) {
				if (pNode2->val == pNode1->val) {
					int pos = find(pNode2);
					pNode2 = pNode2->next;
					remove(pos);
					continue;
				}
				pNode2 = pNode2->next;
			}
			pNode1 = pNode1->next;
		}
		print(head);
	}
	int find(Node* node) {
		Node* pNode = head;
		int pos=1;
		while (pNode != node) {
			pNode = pNode->next;
			pos++;
		}
		return pos;
	}
	void creatList(int* a, int n) {
		head = new Node;
		Node* pNode = head;
		for (int i = 0; i < n - 1; i++) {
			pNode->val = a[i];
			Node* node = new Node;
			pNode->next = node;
			pNode = pNode->next;
		}
		pNode->val = a[n - 1];
		pNode->next = NULL;
	}
	void print(Node* node)const {
		if (node == NULL) {
			return;
		}
		cout << node->val << (node->next==NULL?"\n":" ");
		print(node->next);
	}
	Node* getNode(int pos) {
		Node* pNode = head;
		for (int i = 1; i < pos; i++) {
			pNode = pNode->next;
			if (pNode == NULL) {
				break;
			}
		}
		return pNode;
	}
	void insert(int pos, int val) {
		Node* pNode = getNode(pos);
		if (pNode == NULL) {
			cout << "error\n";
			return;
		}
		Node* node = new Node;
		node->val = val;
		node->next = pNode->next;
		pNode->next = node;
	}
	void remove(int pos) {
		if (pos == 1) {
			Node* pNode = head;
			head = head->next;
			delete pNode;
			return;
		}
		Node* pNode = getNode(pos - 1);
		if (pNode == NULL|| pNode->next==NULL) {
			cout << "error\n";
			return;
		}
		Node* node = pNode->next;
		pNode->next = node->next;
		node->next = NULL;
		delete node;
	}
	void destory(Node* node) {
		if (node == NULL) { return; }
		destory(node->next);
		delete node;
	}
	~CList() {
		destory(head);
	}
};
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		CList* list = new CList(a, n);
		list->quchong();
		delete list;
		delete[]a;
	}
	return 0;
}