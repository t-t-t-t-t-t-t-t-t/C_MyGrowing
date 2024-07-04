#include<iostream>
#include<iomanip>
using namespace std;
class Date {
protected:
	int year, month, day;
public:
	Date(int _year, int _month, int _day) :year(_year), month(_month), day(_day) {

	}
	Date(const Date& a) {
		year = a.year;
		month = a.month;
		day = a.day;
	}
};
class Time {
protected:
	int hour, minute, second;
public:
	Time(const Time& a) {
		hour = a.hour;
		minute = a.minute;
		second = a.second;
	}
	Time(int _hour, int _minute, int _second) :hour(_hour), minute(_minute), second(_second) {
	}
};
class Schedule :public Date, public Time {
private:
	int ID;
public:
	Schedule(const Schedule& a) :Date(a), Time(a) {
		ID = a.ID;
	}
	Schedule(int _year, int _month, int _day, int _hour, int _minute, int _second, int _ID) :ID(_ID), Date(_year, _month, _day), Time(_hour, _minute, _second) {};
	friend bool before(const Schedule& s1, const Schedule& s2);
	void print() {
		cout << "The urgent schedule is No." << ID << setw(2) << setfill('0') << ": " << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << " " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << "\n";
	}
};
bool before(const Schedule& s1, const Schedule& s2) {
	if (s1.year < s2.year) {
		return true;
	}
	else if (s1.year > s2.year) {
		return false;
	}

	if (s1.month < s2.month) {
		return true;
	}
	else if (s1.month > s2.month) {
		return false;
	}

	if (s1.day < s2.day) {
		return true;
	}
	else if (s1.day > s2.day) {
		return false;
	}

	if (s1.hour < s2.hour) {
		return true;
	}
	else if (s1.hour > s2.hour) {
		return false;
	}

	if (s1.minute < s2.minute) {
		return true;
	}
	else if (s1.minute > s2.minute) {
		return false;
	}

	if (s1.second < s2.second) {
		return true;
	}
	else if (s1.second > s2.second) {
		return false;
	}

	return false;
}
int main() {
	int year, month, day;
	int hour, minute, second;
	int id;
	Schedule latest(99999999, 0, 0, 0, 0, 0, 0);
	while (1) {
		cin >> id;
		if (id == 0) { break; }
		cin >> year >> month >> day >> hour >> minute >> second;
		Schedule current(year, month, day, hour, minute, second, id);
		if (before(current, latest)) {
			latest = current;
		}
	}
	latest.print();

	return 0;
}