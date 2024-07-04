
#include<iostream>
#include<string>
using namespace std;
class PhoneBook;
class Info { //联系人，用一个链表结点表示
	string name; //姓名
	int phoneNum; //电话
	Info* next;  //指向下一个结点
public:
	Info(string _name = "", int _phoneNum = 0) :name(_name), phoneNum(_phoneNum), next(NULL)
	{
	}
	Info(char _name = 'A') :name(""), phoneNum(0), next(NULL)
	{
		name += _name;
	}
	Info operator=(const Info&a) {// 深拷贝
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
	friend ostream& operator<<(ostream& out, const Info& _info) {// 重载运算符>>
		out << _info.name;
		if (_info.phoneNum) {
			out << '.' << _info.phoneNum;
		}
		return out;
	}
	friend ostream& operator<<(ostream& out, const Info* _info) {//函数重载 ,参数为Info* 时用
		out << _info->name;
		if (_info->phoneNum) {
			out << '.' << _info->phoneNum;
		}
		return out;
	}
	friend PhoneBook;
};
class PhoneBook {//组链表方式实现通讯录
	static const int MaxPage = 26;
	Info** Table;// 链表数组
public:
	// init 初始化
	PhoneBook() :Table(new Info* [MaxPage]) {// 首先先开辟26个空间
		for (int i = 0; i < MaxPage; i++) {
			Table[i] = new Info('A' + i);// Table 就是一个 Info* 类型的,给头指针初始化
		}
	}
	// get right pageIndx 一个类模板,既可以输入A-Z的数字,也可以输入0-25,表示访问(链表数组中的)哪一个链表, 返回一个合法数字
	template<typename T>int getRightPageIndex(T pageIndx) {
		if (pageIndx >= 0 && pageIndx <= 26) {
			return pageIndx;
		}
		else {// 如果是字母
			return pageIndx - 'A';
		}
	}
	//  whichPage 访问哪一个链表 , index 访问链表中的第几个元素
	template<typename Type>Info* getNode(Type whichPage, int index) { 
		int pageNum = getRightPageIndex(whichPage);
		index++;// 头指针为标识符(不是信息),不访问;
		Info* pNode = Table[pageNum];
		while (pNode->next && index--) {// 链表用while历遍
			pNode = pNode->next;
		}
		return pNode;
	}
	// getHeadNode 得到某一个链表的头指针
	template<typename Type>Info* head(Type whichPage) { 
		int pageNum = getRightPageIndex(whichPage);
		return Table[pageNum];
	}
	// getLastNode 历遍并得到最后一个Node
	template<typename Type>Info* getLastNode(Type whichPage = 0) {
		int pageNum = getRightPageIndex(whichPage);
		Info* pNode = Table[pageNum];
		while (pNode->next) {
			pNode = pNode->next;
		}
		return pNode;
	}
	// insert 在头指针之后插入
	void insert(Info person) {
		Info* pNode = find(person.name);// 看有没有重复的
		if (pNode) {// 已经有了
			pNode->phoneNum = person.phoneNum; // 那么覆盖电话号码
			return;
		}
		pNode = new Info(person); // 新建一个节点
		Info* headNode = head(person.name[0]);// 得到要插入的链表的首地址
		pNode->next = headNode->next; // 进行插入 
		headNode->next = pNode;
		return;
	}
	// find info 以name为标识符来查找节点
	Info* find(string personName) {
		Info* pNode = head(personName[0]);
		while (pNode->next) {// while历遍
			pNode = pNode->next;// 由于第一个节点为标识符所以直接跳过,变为下一个
			if (pNode->name == personName) {
				return pNode;// 找到了就返回
			}
		}
		return NULL;
	}

	// build
	void Input() { // 建造通讯录
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			Info person("",0); // 开辟一个节点
			cin >> person;// 根据重载的>>,初始化
			insert(person); // 以插入的方式构造
		}
	}
	// print  输出
	void Print() {
		for (int i = 0; i < MaxPage; i++) {
			Info* pNode = head(i);
			if (!(pNode->next)) {// 这个链表没有内容,不输出
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
	// 重载()
	Info* operator()(string personName) { 
		return find(personName);
	}
	// 重载 += 
	void operator+=(Info person) { 
		insert(person);
	}
	PhoneBook& operator = (PhoneBook b){ // 重载= ,深拷贝
		for (int i = 0; i < MaxPage;i++) {
			Info* pNodeA = head(i);
			Info* pNodeB = b.head(i);
			while (pNodeB->next) {
				pNodeB = pNodeB-> next;
				pNodeA->next = new Info("");// 开一个节点,改变了地址
				pNodeA->next->operator=(*pNodeB);// 为节点赋值
				pNodeA = pNodeA->next;
			}
		}
		return *this;
	}
	PhoneBook operator+( PhoneBook &b) { // 两个通讯录合并
		PhoneBook A; // 防止原来的数据变化,做一个拷贝
		A = *this;
		for (int i = 0; i < MaxPage; i++) {
			Info* pNodeB = b.head(i);
			while (pNodeB->next) {// 遍历 B
				pNodeB = pNodeB->next;
				A.insert(*pNodeB); // 把 B中的节点插入A
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


