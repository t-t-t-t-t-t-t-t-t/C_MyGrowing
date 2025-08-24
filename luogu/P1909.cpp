//https://www.luogu.com.cn/problem/P1909
#include<iostream>
using namespace std;
struct HB{
	int price;
	int num;
};
int main() {
	int n;
	// 32位最大值
	int ans = (1 << 31) - 1;
	cin >> n;
	HB* hb = new HB[3];
	for (int i = 0; i < 3; i++) {
		cin >> hb[i].num >> hb[i].price;
		// 铅笔是一包一包卖的，计算需要买多少包
		float needBuy = (n*1.0 / hb[i].num);
		// 进行向上取整
		int neddBuy_int = needBuy == int(needBuy) ? int(needBuy) : int(needBuy) + 1;
		// 取最小值
		ans = min(ans, neddBuy_int * hb[i].price);
	}
	cout << ans;
	delete[] hb;
	return 0;
}