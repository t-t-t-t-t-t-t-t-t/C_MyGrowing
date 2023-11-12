//https://www.lanqiao.cn/problems/6278/learning/?contest_id=146
#include<iostream>
#include<cmath>
#include<map>
#include<string>
using namespace std;
int main()
{
	map<char, int>m;
	m.insert(pair<char, int>('3', 1));
	m.insert(pair<char, int>('4', 2));
	m.insert(pair<char, int>('5', 3));
	m.insert(pair<char, int>('6', 4));
	m.insert(pair<char, int>('7', 5));
	m.insert(pair<char, int>('8', 6));
	m.insert(pair<char, int>('9', 7));
	m.insert(pair<char, int>('X', 8));
	m.insert(pair<char, int>('J', 9));
	m.insert(pair<char, int>('Q', 10));
	m.insert(pair<char, int>('K', 11));
	m.insert(pair<char, int>('A', 12));
	m.insert(pair<char, int>('2', 13));
	m.insert(pair<char, int>('M', 14));
	m.insert(pair<char, int>('F', 15));
	int t; string s1, s2;
	cin >> t;
	while (t--)
	{
		cin >> s1 >> s2;

		if (m[s1[0]] < m[s1[1]]) { int temp = s1[0]; s1[0] = s1[1]; s1[1] = temp; }
		if (m[s2[0]] < m[s2[1]]) { int temp = s2[0]; s2[0] = s2[1]; s2[1] = temp; }
		if (s1[0] == s1[1]) { cout << "ShallowDream" << endl; continue; }//1���֣��ж��ӣ������Ӯ��
		if (s1[0] == 'F' && s1[1] == 'M') { cout << "ShallowDream" << endl; continue; }//1����ը�������Ӯ
		if (s2[0] == 'F' && s2[1] == 'M') { cout << "Joker" << endl; continue; }//1��������û�У���B���ƣ�B����ը����Ӯ
		if (m[s1[0]] >= m[s2[0]]) { cout << "ShallowDream" << endl; continue; }//�����ƣ�˭��������������Ǿ�Ӯ������Ϊ��һ��һ���������ƣ�
		else
		{
			cout << "Joker" << endl; continue;
		}
	}
	return 0;
}