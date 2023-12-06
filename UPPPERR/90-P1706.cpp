#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
long long a[100000];
int main()
{
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	do {
		for (int i = 0; i < n; i++)
		{
			cout << setw(5) << a[i];
		}
		cout << '\n';
	} while (next_permutation(a, a + n));
	return 0;
}
