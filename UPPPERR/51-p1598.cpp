#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[10000][26];
int b[26] = { 0 };
char s;
int main()
{
	int m = -100;

	while (cin >> s)/////////////////////////////////////“ıº‰µƒ ‰»Î£ª
	{
		if (s == ' ' || s == '\n' || s == '\0')
		{
			continue;
		}
		b[s - 'A']++;
		a[b[s - 'A']][s - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		m = max(m, b[i]);
	}
	for (int i = m; i >= 1; i--)//////////////m
	{
		for (int j = 0; j < 26; j++)
		{
			if (a[i][j])
			{
				cout << "*";
			}
			else { cout << " "; }
			if (j != 25)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
	return 0;
}