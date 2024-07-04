//补充CBigInteger类和头文件
/********** Write your code here! **********/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class CBigInteger {
	string num;
	bool sign;
public:
	CBigInteger(string _num = "",bool _sign=0) :num(_num),sign(_sign) {}
	friend istream& operator>>(istream& in,  CBigInteger& a) {
		string s;
		in >> s;
		if (s[0] == '-') {
			a.sign = 1;
			s = s.substr(1, s.length() - 1);
		}
		else {
			a.sign = 0;
		}
		int begin = 0;
		while (s[begin] == '0'&& begin < s.length()-1) {
			begin++;
		}
		a.num = s.substr(begin, s.length() - begin);
		return in;
	}
	friend ostream& operator<<(ostream& out,const CBigInteger& a) {
		if (a.num == "0") {
			out << "0";
		}
		else if (a.sign == 1) {// -
			out << '(' <<'-'<< a.num << ')';
		}
		else {
			out << a.num;
		}
		return out;
	}
	bool compare(string s1, string s2) {
		if (s1.length() > s2.length()) {
			return 1;
		}
		else if(s1.length() < s2.length()){
			return 0;
		}
		else {
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] > s2[i]) {
					return 1;
				}
				else if(s1[i] < s2[i]){
					return 0;
				}
			}
		}
	}
	string add(string s1,string s2) {
		int a[2000], b[2000];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < s1.length(); i++) {
			a[i] = s1[s1.length() - i - 1] - '0';
		}
		for (int i = 0; i < s2.length(); i++) {
			b[i] = s2[s2.length() - i - 1] - '0';
		}
		int ch = 0;
		for (int i = 0; i < 1000; i++) {
			a[i] += b[i];
			a[i+1]+= a[i] / 10;
			a[i] %= 10;
		}
		int begin = 1500;
		while (a[begin] == 0 && begin) {
			begin--;
		}
		string ans;
		for (int i = begin; i >= 0; i--) {
			ans += a[i] + '0';
		}
		return ans;
	}
	string sub(string s1, string s2) {
		int a[2000], b[2000];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < s1.length(); i++) {
			a[i] = s1[s1.length() - i - 1] - '0';
		}
		for (int i = 0; i < s2.length(); i++) {
			b[i] = s2[s2.length() - i - 1] - '0';
		}
		for (int i = 0; i < 1000; i++) {
			a[i] -=  b[i] ;
			while (a[i] < 0) {
				a[i] += 10;
				a[i + 1]--;
			}
		}
		int begin = 1500;
		while (a[begin] == 0 && begin) {
			begin--;
		}
		string ans;
		for (int i = begin; i >= 0; i--) {
			ans += a[i] + '0';
		}
		return ans;
	}
	string multi(string s1, string s2) {
		int a[2000], b[2000], save[4005];
		memset(save, 0, sizeof(save));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < s1.length(); i++) {
			a[i] = s1[s1.length() - i - 1] - '0';
		}
		for (int i = 0; i < s2.length(); i++) {
			b[i] = s2[s2.length() - i - 1] - '0';
		}
		for (int i = 0; i < s1.length(); i++) {
			for (int j = 0; j < s2.length(); j++) {
				save[i + j] += a[i] * b[j];
				save[i + j+1]+= save[i + j] / 10;
				save[i + j] %= 10;
			}
		}	
		int begin = 3000;
		while (save[begin] == 0 && begin) {
			begin--;
		}
		string ans;
		for (int i = begin; i >= 0; i--) {
			ans += save[i] + '0';
		}
		return ans;
	}
	CBigInteger operator+(const CBigInteger& add) {
		string s1 = num, s2 = add.num;
		bool _sign = 0;
		if (!compare(s1, s2)) {
			swap(s1, s2);
			_sign = 1;
		}
		if (sign == 1 && add.sign == 1) {
			return CBigInteger(this->add(s1, s2), 1);
		}
		else if (sign == 1 && add.sign == 0) {
			return CBigInteger(this->sub(s1, s2), !_sign);
		}
		else if (sign == 0 && add.sign == 1) {
			return CBigInteger(this->sub(s1, s2), _sign);
		}
		else if (sign == 0 && add.sign == 0) {
			return CBigInteger(this->add(s1, s2), 0);
		}
	}
	CBigInteger operator-(const CBigInteger& add) {
		string s1 = num, s2 = add.num;
		bool _sign = 0;
		if (!compare(s1, s2)) {
			swap(s1, s2);
			_sign = 1;
		}
		if (sign == 1 && add.sign == 1) {
			return CBigInteger(this->sub(s1, s2), !_sign);
		}
		else if (sign == 1 && add.sign == 0) {
			return CBigInteger(this->add(s1, s2), 1);
		}
		else if (sign == 0 && add.sign == 1) {
			return CBigInteger(this->add(s1, s2), 0);
		}
		else if (sign == 0 && add.sign == 0) {
			return CBigInteger(this->sub(s1, s2), _sign);
		}
	}
	CBigInteger operator*(const CBigInteger& add) {
		string s1 = num, s2 = add.num;
		return	CBigInteger(this->multi(s1, s2), sign^add.sign);
	}
};
/*******************************************/
int main()
{
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;

	cin >> t;
	while (t--)
	{
		cin >> bigNum1 >> op >> bigNum2;
		cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
		if (op == '+')
			cout << bigNum1 + bigNum2 << endl;
		else if (op == '-')
			cout << bigNum1 - bigNum2 << endl;
		else if (op == '*')
			cout << bigNum1 * bigNum2 << endl;
	}
	return 0;
}
