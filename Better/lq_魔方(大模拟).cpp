#include<iostream>
#include<string>
using namespace std;
string x[9] = { " ","��","��","��","��","��","��","��","��" };
string y[9] = { " ","��","��","��","��","��","��","��","��" };
string z[9] = { " ","��","��","��","��","��","��","��","��" };
int main()
{
	string s; string s1 = "", s2 = "", s3 = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'x')
		{
			s1 = y[1];
			s2 = y[3];
			y[1] = z[3];
			y[3] = z[4];
			z[3] = y[8];
			z[4] = y[6];
			y[6] = z[5];
			y[8] = z[6];
			z[5] = s2;
			z[6] = s1;
			s3 = x[1];
			x[1] = x[3];
			x[3] = x[4];
			x[4] = x[2];
			x[2] = s3;
		}
		if (s[i] == 'y')
		{
			s1 = x[2]; s2 = x[4];
			x[2] = z[6];
			x[4] = z[8];
			z[6] = x[7];
			z[8] = x[5];
			x[5] = z[4];
			x[7] = z[2];
			z[4] = s2;
			z[2] = s1;
			s3 = y[1];
			y[1] = y[3];
			y[3] = y[4];
			y[4] = y[2];
			y[2] = s3;
		}
		if (s[i] == 'z')
		{
			s1 = x[1];
			s2 = x[2];
			x[1] = y[1];
			x[2] = y[2];
			y[1] = x[5];
			y[2] = x[6];
			x[5] = y[5];
			x[6] = y[6];
			y[5] = s1;
			y[6] = s2;
			s3 = z[1];
			z[1] = z[3];
			z[3] = z[4];
			z[4] = z[2];
			z[2] = s3;
		}
	}
	cout << x[2] << y[1] << z[4];
	return 0;
}