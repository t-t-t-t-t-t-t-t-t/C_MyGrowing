#include<iostream>
using namespace std;
const int N = 1e3;
int cntx[N], cnty[N];
int step[N];
int wmap[N][N];
int n; int all = 0;
bool final = 0;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0,1,0,-1 };
bool check() {
	for (int i = 1; i <= n; i++) {
		if (cntx[i] || cnty[i])return 0;
	}
	return 1;
}
void go(int x, int y, int deep) {
	step[deep] = x + (y - 1) * n - 1;
	wmap[x][y] = 1;
	cntx[x]--;
	cnty[y]--;
	if (x == n && y == n && check()) {
		final = 1;//ע���֧
		return;
	}
	else if (deep > all/2) { return; }
	else {
		for (int i = 0; i < 4; i++) {
			int afx = x + dx[i], afy = y + dy[i];
			if (afx <= n && afx >= 1 && afy <= n && afy >= 1 && !wmap[afx][afy] && !final) {
				if (cntx[afx] && cnty[afy])//final��һ��������quanjieshu����
				{
					go(afx, afy, deep + 1);//��һ��
					wmap[afx][afy] = 0;//��
					cntx[afx]++;
					cnty[afy]++;
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> cntx[i], all += cntx[i];
	for (int i = 1; i <= n; i++)cin >> cnty[i], all += cnty[i];
	go(1, 1, 1); 
	for (int i = 1; i <= all / 2; i++) {
		cout << step[i] << ' ';
	}
	return 0;
}