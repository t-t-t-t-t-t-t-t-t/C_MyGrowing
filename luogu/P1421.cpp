//https://www.luogu.com.cn/problem/P1421
#include <iostream>
using namespace std;
int main() {
	int yuan, jiao;
	cin >> yuan >> jiao;
	int total = yuan * 10 + jiao; 
	int price = 1 * 10 + 9;
	cout << total / price << endl;
	return 0;
}