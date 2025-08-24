//https://www.luogu.com.cn/problem/P1909
#include<iostream>
using namespace std;
struct HB{
	int price;
	int num;
};
int main() {
	int n;
	// 32λ���ֵ
	int ans = (1 << 31) - 1;
	cin >> n;
	HB* hb = new HB[3];
	for (int i = 0; i < 3; i++) {
		cin >> hb[i].num >> hb[i].price;
		// Ǧ����һ��һ�����ģ�������Ҫ����ٰ�
		float needBuy = (n*1.0 / hb[i].num);
		// ��������ȡ��
		int neddBuy_int = needBuy == int(needBuy) ? int(needBuy) : int(needBuy) + 1;
		// ȡ��Сֵ
		ans = min(ans, neddBuy_int * hb[i].price);
	}
	cout << ans;
	delete[] hb;
	return 0;
}