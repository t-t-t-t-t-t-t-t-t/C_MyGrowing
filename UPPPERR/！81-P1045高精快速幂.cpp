#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int base[1001], p, result[1001], sav[1001];//乘法要开两倍长度
void result_1()
{
	memset(sav, 0, sizeof(sav));
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= 500; j++)

		{
			sav[i + j - 1] += result[i] *base[j];//先计算每一位上的值（不进位）sav 中间变量；暂存；
		}
	}
	for (int i = 1; i <= 500; i++)
	{
		sav[i + 1] += sav[i] / 10;//单独处理进位问题，不容易出错
		sav[i] %= 10;
	}
	memcpy(result, sav, sizeof(result));//cstring库里的赋值函数，把sav的值赋给result
}
void result_2()//只是在result_1的基础上进行了细微的修改
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
	memcpy(base, sav, sizeof(base));//sav赋给base；底数的更新
}
int main()
{
	cin >> p;
	cout << (int)(log10(2) * p + 1);
	result[1] = 1;
	base[1] = 2;//高精度赋初值
	while (p != 0)//快速幂模板
	{
		if (p % 2 == 1)result_1();
		p /= 2;
		result_2();
	}
	result[1] --;
	for (int i = 500; i >= 1; i --)//注意输出格式，50个换一行，第一个不用
	{
		if (i % 50 == 0) {
			cout << '\n';
		}
		cout << result[i];
		
	}
	return 0;
}