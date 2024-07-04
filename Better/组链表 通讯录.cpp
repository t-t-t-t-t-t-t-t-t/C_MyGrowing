
#include<iostream>
#include<string>
using namespace std;
class PhoneBook;
class Info { //��ϵ�ˣ���һ���������ʾ
	string name; //����
	int phoneNum; //�绰
	Info* next;  //ָ����һ�����
public:
	Info(string _name = "", int _phoneNum = 0) :name(_name), phoneNum(_phoneNum), next(NULL)
	{
	}
	Info(char _name = 'A') :name(""), phoneNum(0), next(NULL)
	{
		name += _name;
	}
	Info operator=(const Info&a) {// ���
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
	friend ostream& operator<<(ostream& out, const Info& _info) {// ���������>>
		out << _info.name;
		if (_info.phoneNum) {
			out << '.' << _info.phoneNum;
		}
		return out;
	}
	friend ostream& operator<<(ostream& out, const Info* _info) {//�������� ,����ΪInfo* ʱ��
		out << _info->name;
		if (_info->phoneNum) {
			out << '.' << _info->phoneNum;
		}
		return out;
	}
	friend PhoneBook;
};
class PhoneBook {//������ʽʵ��ͨѶ¼
	static const int MaxPage = 26;
	Info** Table;// ��������
public:
	// init ��ʼ��
	PhoneBook() :Table(new Info* [MaxPage]) {// �����ȿ���26���ռ�
		for (int i = 0; i < MaxPage; i++) {
			Table[i] = new Info('A' + i);// Table ����һ�� Info* ���͵�,��ͷָ���ʼ��
		}
	}
	// get right pageIndx һ����ģ��,�ȿ�������A-Z������,Ҳ��������0-25,��ʾ����(���������е�)��һ������, ����һ���Ϸ�����
	template<typename T>int getRightPageIndex(T pageIndx) {
		if (pageIndx >= 0 && pageIndx <= 26) {
			return pageIndx;
		}
		else {// �������ĸ
			return pageIndx - 'A';
		}
	}
	//  whichPage ������һ������ , index ���������еĵڼ���Ԫ��
	template<typename Type>Info* getNode(Type whichPage, int index) { 
		int pageNum = getRightPageIndex(whichPage);
		index++;// ͷָ��Ϊ��ʶ��(������Ϣ),������;
		Info* pNode = Table[pageNum];
		while (pNode->next && index--) {// ������while����
			pNode = pNode->next;
		}
		return pNode;
	}
	// getHeadNode �õ�ĳһ�������ͷָ��
	template<typename Type>Info* head(Type whichPage) { 
		int pageNum = getRightPageIndex(whichPage);
		return Table[pageNum];
	}
	// getLastNode ���鲢�õ����һ��Node
	template<typename Type>Info* getLastNode(Type whichPage = 0) {
		int pageNum = getRightPageIndex(whichPage);
		Info* pNode = Table[pageNum];
		while (pNode->next) {
			pNode = pNode->next;
		}
		return pNode;
	}
	// insert ��ͷָ��֮�����
	void insert(Info person) {
		Info* pNode = find(person.name);// ����û���ظ���
		if (pNode) {// �Ѿ�����
			pNode->phoneNum = person.phoneNum; // ��ô���ǵ绰����
			return;
		}
		pNode = new Info(person); // �½�һ���ڵ�
		Info* headNode = head(person.name[0]);// �õ�Ҫ�����������׵�ַ
		pNode->next = headNode->next; // ���в��� 
		headNode->next = pNode;
		return;
	}
	// find info ��nameΪ��ʶ�������ҽڵ�
	Info* find(string personName) {
		Info* pNode = head(personName[0]);
		while (pNode->next) {// while����
			pNode = pNode->next;// ���ڵ�һ���ڵ�Ϊ��ʶ������ֱ������,��Ϊ��һ��
			if (pNode->name == personName) {
				return pNode;// �ҵ��˾ͷ���
			}
		}
		return NULL;
	}

	// build
	void Input() { // ����ͨѶ¼
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			Info person("",0); // ����һ���ڵ�
			cin >> person;// �������ص�>>,��ʼ��
			insert(person); // �Բ���ķ�ʽ����
		}
	}
	// print  ���
	void Print() {
		for (int i = 0; i < MaxPage; i++) {
			Info* pNode = head(i);
			if (!(pNode->next)) {// �������û������,�����
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
	// ����()
	Info* operator()(string personName) { 
		return find(personName);
	}
	// ���� += 
	void operator+=(Info person) { 
		insert(person);
	}
	PhoneBook& operator = (PhoneBook b){ // ����= ,���
		for (int i = 0; i < MaxPage;i++) {
			Info* pNodeA = head(i);
			Info* pNodeB = b.head(i);
			while (pNodeB->next) {
				pNodeB = pNodeB-> next;
				pNodeA->next = new Info("");// ��һ���ڵ�,�ı��˵�ַ
				pNodeA->next->operator=(*pNodeB);// Ϊ�ڵ㸳ֵ
				pNodeA = pNodeA->next;
			}
		}
		return *this;
	}
	PhoneBook operator+( PhoneBook &b) { // ����ͨѶ¼�ϲ�
		PhoneBook A; // ��ֹԭ�������ݱ仯,��һ������
		A = *this;
		for (int i = 0; i < MaxPage; i++) {
			Info* pNodeB = b.head(i);
			while (pNodeB->next) {// ���� B
				pNodeB = pNodeB->next;
				A.insert(*pNodeB); // �� B�еĽڵ����A
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


