
#include<iostream>
#include<string>
using namespace std;
class PhoneBook;
class Info { //联系人，用一个链表结点表示
	string name; //姓名
	int phoneNum; //电话
public:
	Info* next;  //指向下一个结点
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
	//属性的get和set方法....自行定义
};
class PhoneBook {//组链表方式实现通讯录
	//....自行增加一些操作
	//提示：把插入和查找先写成内部函数，再被运算符重载调用，会更方便
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
		if (pNode) {// 已经有了
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
//...PhoneBook类成员函数，类外实现，自行编写
//----主函数----
int main()
{
	string tname;
	int i, tno;
	Info* p;
	PhoneBook pb;
	pb.Input(); //接收输入数据，初始化第一个通讯录
	//两次姓名查找
	for (i = 0; i < 2; i++)
	{
		cin >> tname;
		p = pb(tname); //调用()运算符，实现查找
		if (p)p->Print(); //查找成功，输出联系人信息
		else cout << "查找失败" << endl; //查找失败，输出提示信息
	}
	//一次插入
	cin >> tname >> tno;
	Info temp(tname, tno);
	pb += temp; //调用+=运算符，实现插入新联系人
	//通讯录合并
	PhoneBook pc;
	pc.Input(); //初始化第二个通讯录
	pb = pb + pc; //调用+运算符，实现合并
	pb.Print(); //输出所有操作后的通讯录
	return 0;
}


