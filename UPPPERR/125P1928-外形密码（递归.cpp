#include<iostream>
#include<string>
using namespace std;
string read(){
	int num;
	string s, b;
	char a;
	while (cin >> a){
		if (a == '['){
			cin >> num;
			b = read();
			while (num--) s += b;
		}
		else if (a == ']'){
			return s;
		}
		else{
			s += a;
		}
	}
	return s;
}
int main(){
	cout << read();
	return 0;
}