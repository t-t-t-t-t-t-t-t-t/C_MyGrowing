#include<iostream>
#include<string>
using namespace std;

int main() {
	string s; cin >> s;
	long long n; cin >> n;
	//ȷ��len?  ��Ҫ�� n,   len�Ĵ�СΪ   len/2< n <=len ,����lenΪ m.length()�ı���
	long long len = s.length();
	while (len < n) 	len <<= 1;
	while (n > s.length()) {
		// n���ַ����ĺ�벿��
		// �ص�Ϊ,���ַ�����Ϊ������ , �����һ��(len/2+1��һ��),�����ಿ��
		// 1. nΪlen/2+1λ(��벿�ֵĵ�һλ) ,n��Ϊn-1;
		// 2. n��(��벿�ֵ����ಿ��)���ಿ�� ��ôn��Ϊ n-len/2 - 1;
		len >>= 1;
		if (n > len)//n���ַ����ĺ��ε����,
		{
			if (n == len + 1) {
				n = len;
			}
			else {
				n -= len + 1;
			}
		}
		else {//n���ַ�����ǰ���,ֻ��len/2����,��Ϊ��n������,������������
			continue;
		}
		
	};
	cout << s[n - 1];
	return 0;
}