#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Tv {
private:
	int status, volume, maxchannel, channel, mode, input;
public:
	Tv(int status, int volume, int  channel, int mode, int input) {
		this->status = status;
		this->volume = volume;
		this->channel = channel;
		this->mode = mode;
		this->input = input;
		maxchannel = 100;
	}
	void onoff() {
		this->status = !this->status;
	}
	bool ison() {
		return this->status;
	}
	bool volup() {
		return  this->volume++;
	}
	bool voldown() {
		return this->volume--;
	}
	void chanup() {
		this->channel++;
	}
	void chandown() {
		this->channel--;
	}
	void set_mode() {
		this->mode = !this->mode;
	}
	void set_input() {
		this->input = !this->input;
	}
	void settings()const {
		cout << (status == 1 ? "on" : "off") << ' ' << volume << ' ' << channel << ' ' << (mode == 0 ? "Cable" : "Antenna") << ' ' << (input == 0 ? "VCR" : "TV") << '\n';
	}
	friend class Remote;
};

class Remote {
private:
public:
	bool volup(Tv& t) {
		return t.volup();
	}
	bool voldown(Tv& t) {
		return t.voldown();
	}
	void onoff(Tv& t) {
		t.onoff();
	}
	void chanup(Tv& t) {
		t.chanup();
	}
	void chandown(Tv& t) {
		t.chandown();
	}
	void set_chan(Tv& t, int c) {
		t.channel = c;
	}
	void set_mode(Tv& t) {
		t.set_mode();
	}
	void set_input(Tv& t) {
		t.set_input();
	}
};

int main() {
	string status1, mode1, input1;
	int volume, channel;
	cin >> status1 >> volume >> channel >> mode1 >> input1;
	int status, mode, input;
	status = (status1 == "on" ? 1 : 0);
	mode = (mode1 == "Cable" ? 0 : 1);
	input = (input1 == "VCR" ? 0 : 1);
	Tv t(status, volume, channel, mode, input);
	string option;
	Remote r;
	while (cin >> option) {
		if (option == "onoff") {
			r.onoff(t);
		}
		else if (t.ison()) {
			if (option == "volup") {
				r.volup(t);
			}
			if (option == "voldown") {
				r.voldown(t);
			}
			if (option == "onoff") {
				r.onoff(t);
			}
			if (option == "chanup") {
				r.chanup(t);
			}
			if (option == "chandown") {
				r.chandown(t);
			}
			if (option == "set_chan") {
				int c; cin >> c;
				r.set_chan(t, c);
			}
			if (option == "set_mode") {
				r.set_mode(t);
			}
			if (option == "set_input") {
				r.set_input(t);
			}
		}
	}
	t.settings();
	return 0;
}