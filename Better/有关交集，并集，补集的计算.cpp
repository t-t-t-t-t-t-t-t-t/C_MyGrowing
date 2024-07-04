#include<iostream>
using namespace std;
class Set {
	int* content;
	size_t size;
public:
	Set(int* _content, size_t _size) :size(_size), content(new int[_size]) {
		for (int i = 0; i < size; i++) {
			content[i] = _content[i];
		}
	}
	Set operator+(const Set& a) {
		int* newArr = new int[size + a.size];
		size_t newLen = size + a.size;
		for (int i = 0; i < size; i++) {
			newArr[i] = content[i];
		}
		for (int i = size; i < size + a.size; i++) {
			newArr[i] = a.content[i - size];
		}
		for (int i = newLen - 1; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (newArr[i] == newArr[j]) {
					for (int k = i; k < newLen - 1; k++) {
						newArr[k] = newArr[k + 1];
					}
					newLen--;
					break;
				}
			}
		}
		return Set(newArr, newLen);
	}
	Set operator*(const Set& a) {
		int* newArr = new int[max(a.size, size)];
		size_t newLen = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < a.size; j++) {
				if (content[i] == a.content[j]) {
					newArr[newLen] = content[i];
					newLen++;
				}
			}
		}
		return Set(newArr, newLen);
	}
	Set operator-(const Set& a) {
		int* newArr = new int[size];
		size_t newLen = size;
		for (int i = 0; i < size; i++) {
			newArr[i] = content[i];
		}
		for (int i = 0; i < newLen; i++) {
			for (int j = 0; j < a.size; j++) {
				if (newArr[i] == a.content[j]) {
					for (int k = i; k < newLen - 1; k++) {
						newArr[k] = newArr[k + 1];
					}
					newLen--;
					i--;
					break;
				}
			}
		}

		return Set(newArr, newLen);
	}
	friend ostream& operator<<(ostream& out, const Set& a) {
		for (int i = 0; i < a.size; i++) {
			out << a.content[i] << (i == a.size - 1 ? "" : " ");
		}
		return out;
	}

};
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Set A(a, n);
		cin >> n;
		int* b = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		Set B(b, n);
		cout << "A:" << A << '\n';
		cout << "B:" << B << '\n';
		cout << "A+B:" << A + B << '\n';
		cout << "A*B:" << A * B << '\n';
		cout << "(A-B)+(B-A):" << (A - B) + (B - A) << "\n\n";
	}
	return 0;
}