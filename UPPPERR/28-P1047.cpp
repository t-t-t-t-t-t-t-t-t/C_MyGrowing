#include<iostream>
using namespace std;
int a[100000];
int main()
{
	int len, m,l,r;
	cin >> len >> m;
	len++;// ��������� 0 �������һ�ã�
	int t = len;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		if (l == r) { continue; }
		a[l] ++;
		a[r + 1] --;
	}
	for (int i = 1; i <= t; i++)//�ж���t��if (a[i-1]) �ſ����ж��ꣻ
	{
		a[i] += a[i - 1];
		if (a[i-1])//  �ж���i=t=len+1 �� (a[i-1]) �ſ����ж��ꣻ 0��len-1Ϊ�� ��len���� ����ȷ��
		{
			len--;
		}
	}
	cout << len;
	return 0;
}