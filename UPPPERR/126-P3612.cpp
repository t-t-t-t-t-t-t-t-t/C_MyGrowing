#include<iostream>
#include<string>
using namespace std;

int main() {
	string s; cin >> s;
	long long n; cin >> n;
	//确定len?  主要看 n,   len的大小为   len/2< n <=len ,而且len为 m.length()的倍数
	long long len = s.length();
	while (len < n) 	len <<= 1;
	while (n > s.length()) {
		// n在字符串的后半部分
		// 重点为,把字符串分为两部分 , 最后那一个(len/2+1那一个),和其余部分
		// 1. n为len/2+1位(后半部分的第一位) ,n变为n-1;
		// 2. n在(后半部分的其余部分)其余部分 那么n变为 n-len/2 - 1;
		len >>= 1;
		if (n > len)//n在字符串的后半段的情况,
		{
			if (n == len + 1) {
				n = len;
			}
			else {
				n -= len + 1;
			}
		}
		else {//n在字符串的前半段,只需len/2即可,因为对n操作后,会出现这种情况
			continue;
		}
		
	};
	cout << s[n - 1];
	return 0;
}