#include<iostream>
using namespace std;
int dea = 1,deb=1 ,_x1, _y1, _x2, _y2,dx1, dx2, dy1, dy2,t = 0;
char m[15][15];
void ar()
{
	if (dea == 1) {
		dx1 = _x1 - 1;
		dy1 = _y1;
	}
	if (dea == 2) {
		dx1 = _x1;
		dy1 = _y1 + 1;
	}
	if (dea == 3) {
		dx1 = _x1 + 1;
		dy1 = _y1;
	}
	if (dea == 4) {
		dx1 = _x1;
		dy1 = _y1 - 1;
	}
	if (dx1 >= 1 && dx1 <= 10 && dy1 >= 0 && dy1 <= 10 && m[dx1][dy1] == '.')
	{
		_x1 = dx1;
		_y1 = dy1;
	}
	else { dea++; if (dea > 4) { dea = 1; } }
}
void br()
{
	if (deb == 1) {
		dx2 = _x2 - 1;
		dy2 = _y2;
	}
	if (deb == 2) {
		dx2 = _x2;
		dy2 = _y2 + 1;
	}
	if (deb == 3) {
		dx2 = _x2 + 1;
		dy2 = _y2;
	}
	if (deb == 4) {
		dx2 = _x2;
		dy2 = _y2 - 1;
	}
	if (dx2 >= 1 && dx2 <= 10 && dy2 >= 0 && dy2 <= 10 && m[dx2][dy2] == '.')
	{
		_x2 = dx2;
		_y2 = dy2;
	}
	else { deb++; if (deb > 4) { deb = 1; } }
}
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 'F')
			{
				_x1 = i;
				_y1 = j;
				m[i][j] = '.';
			}
			if (m[i][j] == 'C')
			{
				_x2 = i;
				_y2 = j;
				m[i][j] = '.';
			}
		}
	}
	while (1)
	{
		ar();
		br();
		t++;
		if (t > 10000) { cout << 0; return 0; }
		if (_x1 == _x2 && _y1 == _y2) { cout << t; return 0; }
	}
	return 0;
}