#include<iostream>
#include<string>
using namespace std;
class Vehicle
{
protected:
	string no;//编号
public:
	Vehicle(string _id = "") :no(_id) {

	}
	virtual void display() = 0;//应收费用
};
class Car :public Vehicle {
private:
	int personNum, weigth;
public:
	Car(int _personNum, int _weigth, string _id) : Vehicle(_id) ,personNum(_personNum), weigth(_weigth){

	}
	void display() {
		cout << no << ' ' << personNum * 8 + weigth * 2 << '\n';
	}
};
class Truck :public Vehicle {
private:
	int weigth;
public:
	Truck(int _weigth, string _id) : Vehicle(_id), weigth(_weigth) {
		
	}
	void display() {
		cout << no << ' ' << weigth * 5 << '\n';
	}
};
class Bus :public Vehicle {
private:
	int personNum;
public:
	Bus(int _personNum, string _id) :Vehicle(_id) , personNum(_personNum) {

	}
	void display() {
		cout << no << ' ' << personNum * 3 << '\n';
	}
};
int main() {
	Vehicle* pv = {};
	int t; cin >> t;
	while (t--) {
		int type;
		string id;
		int personNum, weight;
		cin >> type;
		switch (type)
		{
		case 1: {
			cin >> id >> personNum >> weight;
			Car a(personNum, weight, id);
			pv = &a;
			pv->display();
			break;
		}
		case 2: {
			cin >> id >> weight;
			Truck a(weight, id);
			pv = &a;
			pv->display();
			break;
		}
		case 3: {
			cin >> id >> personNum;
			Bus a(personNum, id);
			pv = &a;
			pv->display();
			break;
		}
		}
	}
	return 0;
}