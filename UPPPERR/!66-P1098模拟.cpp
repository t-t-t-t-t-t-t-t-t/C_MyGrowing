#include<iostream>
#include<string>
using namespace std;
int p1, p2, p3;

int main()
{
	string s;
	cin >> p1 >> p2 >> p3 >> s;
	int t = s.length();
	int i = 0;
	while (t--)
	{
		if (s[i] == '-')
		{
			if (s[i + 1] <= '9' && s[i - 1] >= '0')//0-9
			{
				if ((int)(s[i + 1] - s[i - 1]) > 1)//相邻大于1，
				{
					if (p1 == 3)
					{
						for (int j = (int)s[i - 1] + 1; j < (int)s[i + 1]; j++)
						{
							for (int k = 0; k < p2; k++)
							{
								cout << '*';
							}
						}
						i++;
						continue;
					}
					else {
						if (p3 == 2)
						{
							for (int j = (int)s[i + 1] - 1; j > (int)s[i - 1]; j--)
							{
								for (int k = 0; k < p2; k++)
								{
									cout << char(j);
								}
							}
						}
						else {
							for (int j = (int)s[i - 1] + 1; j < (int)s[i + 1]; j++)
							{
								for (int k = 0; k < p2; k++)
								{
									cout << char(j);
								}
							}
						}
						i++;
						continue;
					}
				}
				if ((int)(s[i + 1] - s[i - 1]) < 1)//相邻大于<1保留‘-’
				{
					cout << '-';
					i++;
					continue;
				}
				if ((int)(s[i + 1] - s[i - 1]) == 1)//相邻大于==1删除‘-’
				{
					i++;
					continue;
				}
			}
			else if (s[i - 1] >= 'a' && s[i + 1] <= 'z')//a-z
			{
				if ((int)(s[i + 1] - s[i - 1]) > 1)//相邻大于2，
				{
					if (p1 == 1)
					{
						if (p3 == 2)
						{
							for (int j = (int)s[i + 1] - 1; j > (int)s[i - 1]; j--)
							{
								for (int k = 0; k < p2; k++)
								{
									cout << char(j);
								}
							}
						}
						else {
							for (int j = (int)s[i - 1] + 1; j < (int)s[i + 1]; j++)
							{
								for (int k = 0; k < p2; k++)
								{
									cout << char(j);
								}
							}
						}
						i++;
						continue;
					}
					else if (p1 == 2)
					{
						if (p3 == 2)
						{
							for (int j = (int)s[i + 1] - 1; j > (int)s[i - 1]; j--)
							{
								for (int k = 0; k < p2; k++)
								{
									cout << char(j - 32);
								}
							}
						}
						else {
							for (int j = (int)s[i - 1] + 1; j < (int)s[i + 1]; j++)
							{
								for (int k = 0; k < p2; k++)
								{
									cout << char(j - 32);
								}
							}
						}
						i++;
						continue;
					}
					if (p1 == 3)
					{
						for (int j = (int)s[i - 1] + 1; j < (int)s[i + 1]; j++)
						{
							for (int k = 0; k < p2; k++)
							{
								cout << '*';
							}
						}
						i++;
						continue;
					}
				}
				if ((int)(s[i + 1] - s[i - 1]) < 1)//相邻大于<1保留‘-’
				{
					cout << '-';
					i++;
					continue;
				}
				if ((int)(s[i + 1] - s[i - 1]) == 1)//相邻大于==1删除‘-’
				{
					i++;
					continue;
				}
			}
			else
			{
				cout << s[i];
				i++;
				continue;
			}
		}
		cout << s[i];
		i++;
	}
	return 0;
}