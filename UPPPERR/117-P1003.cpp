#include<iostream>
#include<algorithm>
using namespace std;
struct po {
	int x, y;
}a[10019], b[10019];
int main() {
	int num; cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
		b[i].x += a[i].x-1;
		b[i].y += a[i].y-1;
	}
	int x, y; cin >> x >> y;
	int ans = -1;
	for (int i = 0; i < num; i++) 	if (a[i].x <= x && b[i].x >= x && a[i].y <= y && b[i].y >= y)ans = i + 1;
	cout << ans;
	return 0;
}