#include<iostream>
using namespace std;
const int MAXN = 210;
int n, na, nb, a[MAXN], b[MAXN], cnta, cntb;
int score[5][5] = { {0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0} }; 
int main()
{
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++) cin >> a[i];
    for (int i = 0; i < nb; i++) cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        cnta += score[a[i % na]][b[i % nb]]; //a
        cntb += score[b[i % nb]][a[i % na]];//b
    }
    cout << cnta << " " << cntb << endl;
    return 0;
}