#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int base[1001], p, result[1001], sav[1001];//�˷�Ҫ����������
void result_1()
{
	memset(sav, 0, sizeof(sav));
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= 500; j++)

		{
			sav[i + j - 1] += result[i] *base[j];//�ȼ���ÿһλ�ϵ�ֵ������λ��sav �м�������ݴ棻
		}
	}
	for (int i = 1; i <= 500; i++)
	{
		sav[i + 1] += sav[i] / 10;//���������λ���⣬�����׳���
		sav[i] %= 10;
	}
	memcpy(result, sav, sizeof(result));//cstring����ĸ�ֵ��������sav��ֵ����result
}
void result_2()//ֻ����result_1�Ļ����Ͻ�����ϸ΢���޸�
{
	memset(sav, 0, sizeof(sav));
	for (int i = 1; i <= 500; i ++)
	{
		for (int j = 1; j <= 500; j ++)

		{
			sav[i + j - 1] +=base[i] *base[j];//
		}
	}
	for (int i = 1; i <= 500; i ++)
	{
		sav[i + 1] += sav[i] / 10;
		sav[i] %= 10;
	}
	memcpy(base, sav, sizeof(base));//sav����base�������ĸ���
}
int main()
{
	cin >> p;
	cout << (int)(log10(2) * p + 1);
	result[1] = 1;
	base[1] = 2;//�߾��ȸ���ֵ
	while (p != 0)//������ģ��
	{
		if (p % 2 == 1)result_1();
		p /= 2;
		result_2();
	}
	result[1] --;
	for (int i = 500; i >= 1; i --)//ע�������ʽ��50����һ�У���һ������
	{
		if (i % 50 == 0) {
			cout << '\n';
		}
		cout << result[i];
		
	}
	return 0;
}