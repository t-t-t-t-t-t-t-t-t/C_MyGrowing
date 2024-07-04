
#include<iostream>
#include<string>
using namespace std;
class PhoneBook;
class Info { //��ϵ�ˣ���һ���������ʾ
	string name; //����
	int phoneNum; //�绰
public:
	Info* next;  //ָ����һ�����
	Info(string _name = "", int _phoneNum = 0) :name(_name), phoneNum(_phoneNum), next(NULL)
	{
	}
	Info(char _name = 'A') :name(""), phoneNum(0), next(NULL)
	{
		name += _name;
	}
	Info operator=(const Info&a) {
		name = a.name;
		phoneNum = a.phoneNum;
		return *this;
	}
	void Print()
	{
		if (phoneNum == 0) {
			cout << name;
			return;
		}
		cout << name << "--" << phoneNum << '\n';
	}
	friend istream& operator>>(istream& in, Info& _info) {
		in >> _info.name >> _info.phoneNum;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Info& _info) {
		out << _info.name;
		if (_info.phoneNum) {
			out << '.' << _info.phoneNum;
		}
		return out;
	}
	friend ostream& operator<<(ostream& out, const Info* _info) {
		out << _info->name;
		if (_info->phoneNum) {
			out << '.' << _info->phoneNum;
		}
		return out;
	}
	friend PhoneBook;
	//���Ե�get��set����....���ж���
};
class PhoneBook {//������ʽʵ��ͨѶ¼
	//....��������һЩ����
	//��ʾ���Ѳ���Ͳ�����д���ڲ��������ٱ���������ص��ã��������
	static const int MaxPage = 26;
	Info** Table;
public:
	// init
	PhoneBook() :Table(new Info* [MaxPage]) {
		for (int i = 0; i < MaxPage; i++) {
			Table[i] = new Info('A' + i);
		}
	}
	// get right pageIndx
	template<typename T>int getRightPageIndex(T pageIndx) {
		if (pageIndx >= 0 && pageIndx <= 26) {
			return pageIndx;
		}
		else {
			return pageIndx - 'A';
		}
	}
	// getNode
	template<typename Type>Info* getNode(Type whichPage, int index) {
		int pageNum = getRightPageIndex(whichPage);
		index++;
		Info* pNode = Table[pageNum];
		while (pNode->next && index--) {
			pNode = pNode->next;
		}
		return pNode;
	}
	// getHeadNode
	template<typename Type>Info* head(Type whichPage) {
		int pageNum = getRightPageIndex(whichPage);
		return Table[pageNum];
	}
	// getLastNode
	template<typename Type>Info* getLastNode(Type whichPage = 0) {
		int pageNum = getRightPageIndex(whichPage);
		Info* pNode = Table[pageNum];
		while (pNode->next) {
			pNode = pNode->next;
		}
		return pNode;
	}
	// insert
	void insert(Info person) {
		Info* pNode = find(person.name);
		if (pNode) {// �Ѿ�����
			pNode->phoneNum = person.phoneNum;
			return;
		}
		pNode = new Info(person);
		Info* headNode = head(person.name[0]);
		pNode->next = headNode->next;
		headNode->next = pNode;
		return;
	}
	// find info
	Info* find(string personName) {
		Info* pNode = head(personName[0]);
		while (pNode->next) {
			pNode = pNode->next;
			if (pNode->name == personName) {
				return pNode;
			}
		}
		return NULL;
	}

	// build
	void Input() {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			Info person("",0);
			cin >> person;
			insert(person);
		}
		Print();
	}
	// print
	void Print() {
		for (int i = 0; i < MaxPage; i++) {
			Info* pNode = head(i);
			if (!(pNode->next)) {
				continue;
			}
			cout << pNode << "--";
			while (pNode->next) {
				pNode = pNode->next;
				cout << pNode << "--";
			}
			cout << '\n';
		}
	}
	Info* operator()(string personName) {
		return find(personName);
	}
	void operator+=(Info person) {
		insert(person);
	}
	PhoneBook& operator = (PhoneBook b){
		for (int i = 0; i < MaxPage;i++) {
			Info* pNodeA = head(i);
			Info* pNodeB = b.head(i);
			while (pNodeB->next) {
				pNodeB = pNodeB-> next;
				pNodeA->next = new Info("");
				pNodeA->next->operator=(*pNodeB);
				pNodeA = pNodeA->next;
			}
		}
		return *this;
	}
	PhoneBook operator+( PhoneBook &b) {
		PhoneBook A;
		A = *this;
		for (int i = 0; i < 12; i++) {
			Info* pNodeB = b.head(i);
			while (pNodeB->next) {
				pNodeB = pNodeB->next;
				A.insert(*pNodeB);
			}
		}
		return A;
	}
};
//...PhoneBook���Ա����������ʵ�֣����б�д
//----������----
int main()
{
	string tname;
	int i, tno;
	Info* p;
	PhoneBook pb;
	pb.Input(); //�����������ݣ���ʼ����һ��ͨѶ¼
	//������������
	for (i = 0; i < 2; i++)
	{
		cin >> tname;
		p = pb(tname); //����()�������ʵ�ֲ���
		if (p)p->Print(); //���ҳɹ��������ϵ����Ϣ
		else cout << "����ʧ��" << endl; //����ʧ�ܣ������ʾ��Ϣ
	}
	//һ�β���
	cin >> tname >> tno;
	Info temp(tname, tno);
	pb += temp; //����+=�������ʵ�ֲ�������ϵ��
	//ͨѶ¼�ϲ�
	PhoneBook pc;
	pc.Input(); //��ʼ���ڶ���ͨѶ¼
	pb = pb + pc; //����+�������ʵ�ֺϲ�
	pb.Print(); //������в������ͨѶ¼
	return 0;
}


