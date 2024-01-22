#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char s[1000][1000];
//x,yΪͼ�����½ǵ�����,ÿ�λ滭����,���ǲ�����С��Χ
void draw(int x, int y, int deep) {
    if (deep == 1) {          
        s[x][y] = '/';
        s[x][y + 1] = '\\';
        s[x + 1][y - 1] = '/';
        s[x + 1][y] = '_';
        s[x + 1][y + 1] = '_';
        s[x + 1][y + 2] = '\\';
        return;
    }
    draw(x, y, deep - 1);
    draw(x + pow(2, deep - 1), y - pow(2, deep - 1), deep - 1);
    draw(x + pow(2, deep - 1), y + pow(2, deep - 1), deep - 1);
}
int main() {
	int n; cin >> n;
	memset(s, ' ', sizeof(s));
    int x = 1, y = pow(2, n);

    draw(1, y, n);
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= pow(2,n+1); j++) {
			cout << s[i][j];
		}
		cout << '\n';
	}
	return 0;
}