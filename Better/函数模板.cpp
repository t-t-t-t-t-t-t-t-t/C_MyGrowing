#include<iostream>
#include<string>
using namespace std;
template<class T>
void input(T a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

template<class T>
void show(T a[], T b[], int n) {
	for (int i = 0; i < n; i++) {
		cout << b[i];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	cout << endl;
}

int main() {
	int t, n;
	cin >> t;
	char a;
	while (t--) {
		cin >> a >> n;
		switch (a) {
		case 'I': {
			int* b = new int[n];
			int* c = new int[n];
			input(b, n);
			input(c, n);
			show(b, c, n);
			break;
		}
		case 'D': {
			double* b = new double[n];
			double* c = new double[n];
			input(b, n);
			input(c, n);
			show(b, c, n);
			break;
		}
		case 'C': {
			char* b = new char[n];
			char* c = new char[n];
			input(b, n);
			input(c, n);
			show(b, c, n);
		}
		}
	}
	return 0;
}
