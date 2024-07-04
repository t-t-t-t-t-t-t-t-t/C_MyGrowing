#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�����࣬����
class CBoxObject
{
protected:
	string type; // ��¼������Ϣ
public:
	CBoxObject(string _type) : type(_type) {}
	virtual void show(ostream&) const = 0; // ���������Ϣ,���麯��
	friend ostream& operator<<(ostream& out, CBoxObject& rhs);
};
// ����CBoxObject������ �������

// ������ģ��CBox

//������ģ������CBox<CBoxObject *>
/********** Write your code here! **********/
ostream& operator<<(ostream& out, CBoxObject& rhs) {
	rhs.show(out);
	return out;
}
ostream& operator<<(ostream& out, CBoxObject* rhs) {
	rhs->show(out);
	return out;
}
template<class Type>class CBox :public CBoxObject {
	Type value;
public:
	CBox(string _type, Type _value) :CBoxObject(_type), value(_value) {

	}
	virtual void show(ostream& out)const {
		out << "{" << type << ": " << value << "}";
	}
	void setVal(Type _value) {
		value = _value;
	}
};
template<>class CBox<CBoxObject*> :public CBoxObject {
	CBoxObject* value;
public:
	CBox(string _type, CBoxObject* _value) :CBoxObject(_type), value(_value) {

	}
	virtual void show(ostream& out)const {
		if (value) {
			out << "{" << type << ": " << value << "}";
		}
		else {
			out << "{}";
		}
	}
	void setVal(CBoxObject* _value) {
		value = _value;
	}
};


/*******************************************/
template <typename T>
void pushBox(istream& in, vector<CBoxObject*>& container, const string& type)
{
	T val;
	in >> val;
	container.emplace_back(new CBox<T>(type, val));
}

int main()
{
	string type;  // ��������
	int n, index; // nΪ���������indexΪvector�����±�

	cin >> n;
	vector<CBoxObject*> pBoxes;
	pBoxes.reserve(n); // Ԥ�ȷ����㹻�Ŀռ�(pBoxes.size()==0��Ȼ����)
	while (n-- > 0)
	{
		cin >> type;
		// �����������ͷֱ��װ
		if (type == "char")
			pushBox<char>(cin, pBoxes, type);
		else if (type == "int")
			pushBox<int>(cin, pBoxes, type);
		else if (type == "double")
			pushBox<double>(cin, pBoxes, type);
		else if (type == "string")
			pushBox<string>(cin, pBoxes, type);
		// ���Ǿ���һ������Ҳ�ǿ��԰�װ��һ�����ӵ�
		// Ϊ�˱����������ǲ��ú���ָ������ʾ���Ӽ�İ�װ��ϵ
		else if (type == "box")
		{
			cin >> index;
			auto box = new CBox<CBoxObject*>("box", nullptr);
			// ����index��pBoxes���еĺ�����ѡ��һ�����º��Ӱ�װ
			if (0 <= index && index < pBoxes.size())
			{
				box->setVal(pBoxes[index]);
				// ��ʵ�к����ǲ����Լ���װ�Լ���
				// �ڱ����У���������Լ���װ�Լ�����ָ��ֵ����Ϊ��
				// �����ݲ���������ɻ�����
			}
			pBoxes.emplace_back(box);
		}
		index = (int)pBoxes.size() - 1;
		cout << *pBoxes[index] << endl;
	}
	for (CBoxObject*& box : pBoxes)
		delete box;
	return 0;
}
