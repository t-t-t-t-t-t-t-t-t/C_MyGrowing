#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char W[10][5][3] =
{
	{//0
	'X','X','X',
	'X','.','X',
	'X','.','X',
	'X','.','X',
	'X','X','X',
	},
	{//1
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
	},
	{//2
		'X','X','X',
		'.','.','X',
		'X','X','X',
		'X','.','.',
		'X','X','X',
	},
	{//3
		'X','X','X',
		'.','.','X',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	},
	{//4
		'X','.','X',
		'X','.','X',
		'X','X','X',
		'.','.','X',
		'.','.','X',
	},
	{//5
		'X','X','X',
		'X','.','.',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	},
	{//6
		'X','X','X',
		'X','.','.',
		'X','X','X',
		'X','.','X',
		'X','X','X',
	},
	{//7
		'X','X','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
	},
	{//8
		'X','X','X',
		'X','.','X',
		'X','X','X',
		'X','.','X',
		'X','X','X',
	},
	{//9
		'X','X','X',
		'X','.','X',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	}
};
int n;
char s[110];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				cout << W[s[j] - '0'][i][k];
			}
			if (j != n - 1) cout << '.';
		}
		cout << endl;
	}
	return 0;
}