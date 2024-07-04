#include<iostream>
#include<string>
using namespace std;
class CVehicle {
protected:
	int max_speed, speed, weight;
public:
	CVehicle(int _max_speed, int _speed, int _weight) :max_speed(_max_speed), speed(_speed), weight(_weight) {

	}
	void display() {
		cout << "Vehicle:\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
	}
};
class CBicycle :virtual public CVehicle {
protected:
	int height;
public:
	CBicycle(int _max_speed, int _speed, int _weight, int _height) :CVehicle(_max_speed, _speed, _weight), height(_height) {

	}
	void display() {
		cout << "Bicycle:\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
		cout << "height:" << height << "\n";
	}
};
class CMotocar :virtual public CVehicle {
protected:
	int seat_num;
public:
	CMotocar(int _max_speed, int _speed, int _weight, int _seat_num) :CVehicle(_max_speed, _speed, _weight), seat_num(_seat_num) {

	}
	void display() {
		cout << "Motocar:" << "\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
		cout << "seat_num:" << seat_num << "\n";
	}
};
class CMotocycle : public CMotocar, public CBicycle {
public:
	CMotocycle(int _max_speed, int _speed, int _weight, int _seat_num, int _height) :CVehicle(_max_speed, _speed, _weight), CMotocar(_max_speed, _speed, _weight, _seat_num), CBicycle(_max_speed, _speed, _weight, _height) {

	}
	void display() {
		cout << "Motocycle:" << "\n";
		cout << "max_speed:" << max_speed << "\n";
		cout << "speed:" << speed << "\n";
		cout << "weight:" << weight << "\n";
		cout << "height:" << height << "\n";
		cout << "seat_num:" << seat_num << "\n";
	}
};
int main() {
	int max_speed, speed, weight;
	int height;
	int seat_num;
	cin >> max_speed >> speed >> weight >> height >> seat_num;
	CVehicle Vehicle(max_speed, speed, weight);
	Vehicle.display();
	cout << '\n';
	CBicycle Bicycle(max_speed, speed, weight, height);
	Bicycle.display();
	cout << '\n';
	CMotocar Motocar(max_speed, speed, weight, seat_num);
	Motocar.display();
	cout << '\n';
	CMotocycle Motocycle(max_speed, speed, weight, seat_num, height);
	Motocycle.display();
	return 0;
}