#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Shop {
	string name, id, color, size;
	int num;
	double value;
public:
	Shop() {};
	Shop (string id, string name, string color, string size, double value, int num) {
		this->name = name;
		this->id = id;
		this->color = color;
		this->size = size;
		this->num = num;
		this->value = value;
	}
	double sum() {
		return num * value;
	}
	void print() {
		cout << name << "," << color << "," << size << "," << fixed << setprecision(2) << value << "," << num << "," << sum() << "\n";
	}
	friend class chart;
};
class chart {
private:
	Shop* content;
	int allNum;
	int typeNum;
	double sum;
public:
	void print() {
		cout << "商品清单:\n商品,颜色,尺码,单价,数量,小计\n";
		for (int i = typeNum-1; i >=0 ; i--) {
			content[i].print();
		}
		cout << "----------\n";
		cout << allNum << "件商品,总商品金额" << sum << '\n';
	}
	chart() {
		content = new Shop[2000];
		allNum = 0;
		typeNum = 0;
		sum = 0;
	}
	int getPos(string id) {
		for (int i = 0; i < typeNum; i++) {
			if (id == content[i].id) {
				return i;
			}
		}
		return -1;
	}
	void ADD(Shop& a) {
		int pos = getPos(a.id);
		if (pos != -1) {
			content[pos].num++;
		}
		else {
			content[typeNum] = a;
			typeNum++;
		}
		sum += a.sum();
		allNum+=a.num;
	}
	void DELETE(string id) {
		int pos = getPos(id);
		allNum -= content[pos].num;
		sum -= content[pos].sum();
		for (int i = pos; i < typeNum - 1; i++) {
			content[i] = content[i + 1];
		}
		typeNum--;
	}
	void UP(string id) {
		int pos = getPos(id);
		content[pos].num++;
		sum += content[pos].value;
		allNum++;
	}
	void DOWN(string id) {
		int pos = getPos(id);
		content[pos].num--;
		sum -= content[pos].value;
		allNum--;
	}
};
int main() {
	int t; cin >> t;
	string option;
	while (t--) {
		int n; cin >> n;
		chart c;
		while (n--) {
			cin >> option;
			string id;
			if (option == "ADD") {
				string name, id, color, size;
				int num;
				double value;
				cin >> id >> name >> color >> size >> value >> num;
				Shop s(id, name, color, size, value, num);
				c.ADD(s);
			}
			else if (option == "UP") {
				cin >> id;
				c.UP(id);
			}
			else if (option == "DOWN") {
				cin >> id;
				c.DOWN(id);
			}
			else if (option == "DELETE") {
				cin >> id;
				c.DELETE(id);
			}
		}
		c.print();
	}
	return 0;
}