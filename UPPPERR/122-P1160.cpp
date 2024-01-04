#include<iostream>
#include<list>
using namespace std;
const int N = 1e5 + 10;
list<int>::iterator pos[N];
int main() {
	int n; cin >> n;
	list<int>m(n);
	m.push_front(1);
	pos[1] = m.begin();
	for (int i = 2; i <= n; i++) {
		int po, di; cin >> po >> di;
		if (po == 0) {
			m.insert(pos[po], i);
		}
		else {
			list<int>::iterator nextIter = next(pos[po]);
			pos[i] = m.insert(nextIter, i);
		}
	}
	int h, x; cin >> h;
	for (int i = 0; i < h; i++)
	{
		cin >> x;
		m.remove(x);
	}
	for (list<int>::iterator i = m.begin(); i != m.end(); i++) {
		cout << *i << ' ';
	}
	return 0;
}