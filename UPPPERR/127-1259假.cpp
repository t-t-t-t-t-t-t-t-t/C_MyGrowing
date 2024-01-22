#include<iostream>
#include<string>
using namespace std;
template<typename T>
void swap(T *a,T *b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int n; cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		s += 'o';
	}
	for (int i = n ; i < 2 * n; i++) {
		s += '*';
	}
	s += "--";
	int l1 = n-1, l2 = n ;
	int r1 = 2 * n , r2 = 2 * n + 1;
	cout << s << '\n';
	while (l1 != 3) {
		swap(s[l1], s[r1]);
		swap(s[l2], s[r2]);
		swap(l1, r1);
		swap(l2, r2);
		l1-=2; l2-=2;
		cout << s<<'\n';

		swap(s[l1], s[r1]);
		swap(s[l2], s[r2]);
		swap(l1, r1);
		swap(l2, r2);
		l1 --; l2 --;
		cout << s << '\n';
	}
	if (n > 4)
	{
		cout << "ooo--***";
		for (int i = 1; i <= n - 3; i++)
			cout << "o*";
		cout << endl;	
	}
	cout << "ooo*o**--*";
	for (int i = 1; i <= n - 4; i++)
		cout << "o*";
	cout << endl;
	cout << "o--*o**o";
	for (int i = 1; i <= n - 3; i++)
		cout << "o*";
	cout << endl;
	cout << "o*o*o*--";
	for (int i = 1; i <= n - 3; i++)
		cout << "o*";
	cout << endl;
	cout << "--";
	for (int i = 1; i <= n; i++)
		cout << "o*";
	return 0;

	return 0;
}