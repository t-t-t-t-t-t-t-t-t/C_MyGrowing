#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
		sort(a.begin(), a.end());
		cout << lower_bound(a.begin(), a.end(), x) - a.begin() << " ";//��������һ�����������ȥ���ҵ��ĵ�һ�������Լ������ĵ���������λ��+1��-1����Ϊǰ���м���С���Լ���
		return 0;
	}
}
//lower_bound :{ a.begin(), a.end() }�����ڲ��� x ��
//�����ص�һ������x�����ĵ����������û���򷵻� ������ĵ�����
//һ�����sort��ʹ�� ����ô ��Ȼ˵���ص��� ������ĵ����� ������ sort֮���Ҳ������Լ������ô�Լ���������
//��˷��صĵ�����Ҳ�����Լ��ĵ�����
//�ܽ᣺lower_bound���ҵ�һ�����Լ��������λ�ã�����sort������Ϊ a.begin(), a.end(),x �Լ�Ҳ�������� )��û���򷵻��Լ���λ�ã�

