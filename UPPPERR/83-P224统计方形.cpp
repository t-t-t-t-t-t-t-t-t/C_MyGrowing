#include<iostream>
using namespace std;
long long sqr = 0,rec=0;
int main()
{
	long long m, n;
	cin >> m >> n;
	for (long long i = 0; i < m; i++)
	{
		for (long long j = 0; j < n; j++)
		{
			if (i == j) { sqr += (m - i) * (n - j); }
			else{ rec += (m - i) * (n - j); }
		}
	}
	cout << sqr << ' ' << rec;
	return 0;
}