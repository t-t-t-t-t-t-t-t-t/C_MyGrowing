#include<iostream>
#include<string>
using namespace std;
class Employee {
protected:
	string name, position;
	int level, year;
public:
	Employee(string _name="", string _position="", int _level=0, int _year=0) :name(_name), position(_position), level(_level), year(_year) {
	}
	virtual void display() {
			cout << name << ":" << position << ",Salary:" << 1000 + 500 * level + 50 * year << '\n';
	}
};
class Teamleader:public Employee {
public:
	Teamleader(string _name, string _position, int _level, int _year):Employee(_name, _position, _level, _year){
	}
	virtual void display() {
			cout << name << ":" << position << ",Salary:" << 3000 + 800 * level + 100 * year << '\n';
	}
};
class Manager : public Employee {
public:
	Manager(string _name, string _position, int _level, int _year) :Employee(_name, _position, _level, _year) {
	}
	virtual void display() {
			cout << name << ":" << position << ",Salary:" << 5000 + 1000 * (level + year) << '\n';
	}

};
int main() {
	int t; cin >> t;
	Employee* pv ;
	while (t--) {
		string name, position;
		int level, year;
		cin >> name >> position >> level >> year;
		if (position != "Employee" && position != "Teamleader"&&position!="Manager") {
			cout << "error position.\n";
		}
		else if (level <0 ||year < 0) {
			cout << "error grade or year.\n";
		}
		else {
			if (position == "Employee") {
				pv =new Employee(name, position, level, year);
			}
			if (position == "Teamleader") {
				pv =new Teamleader(name, position, level, year);
			}
			if (position == "Manager") {
				pv =new Manager(name, position, level, year);
			}
			pv->display();
		}
	}

	return 0;
}