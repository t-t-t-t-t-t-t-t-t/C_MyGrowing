
#include<iostream>
using namespace std;

int b[1000];int a[1000];

void mergesort(int a[], int l, int r)
{
	if (l >= r) { return; }
	int mid = (l + r) / 2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	int j = l, k = mid + 1, cnt = l;
	while (j <= mid && k <= r)
	{
		if (a[j] <= a[k]) { b[cnt++] = a[j++]; }
		else { b[cnt++] = a[k++]; }
	}
	while (j <= mid) { b[cnt++] = a[j++]; }
	while (k <= r) { b[cnt++] = a[k++]; }
	for (int i = l; i <=r; i++)
	{
		a[i] = b[i];
	}
}
int main()
{
	 int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	mergesort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
//�ο���mad��д�˺þòŻᣬ�Һ÷ϡ�
// 
//			void _MergeSortR(int* a, int left, int right, int* tmp)
//			{
//				//����ݹ鵽С����ֻ��һ��ֵ(left==right)���߲�����(left>right)���򷵻�
//				if (left >= right)
//				{
//					return;
//				}
//			
//				//�ݹ����Ҫ����Ĵ������𲽶��ֳ�С���䣬ֱ������ֻ��
//				//һ��ֵ�������䲻���ڵ�ʱ���ٿ�ʼ�鲢�һع�
//				int mid = (left + right) / 2;
//				_MergeSortR(a, left, mid, tmp);
//				_MergeSortR(a, mid + 1, right, tmp);
//			
//				//�������ʱ��˵������ֻ��һ��ֵ�������䲻�����ˣ���ʼ�鲢
//				int begin1 = left;
//				int end1 = mid;
//				int begin2 = mid + 1;
//				int end2 = right;
//			
//				//����С����鲢ʱ�����ݹ鲢�����ٵ���ʱ����tmp�У���leftλ�ÿ�ʼ�ţ�
//				//����鲢�����������֮���tmp���ݿ����ص�ԭ������
//				int i = left;
//			
//				//������С���鶼�������ݾͼ����鲢��ֱ��ĳһ��С����û�������˾�ֹͣ
//				while (begin1 <= end1 && begin2 <= end2)
//				{
//					//�ĸ�����С�Ͱ����鲢��tmp��Ӧ��λ����ȥ(����)
//					if (a[begin1] <= a[begin2])
//					{
//						tmp[i++] = a[begin1++];
//					}
//					else
//					{
//						tmp[i++] = a[begin2++];
//					}
//				}
//				//�������ʱ��һ����һ��С�����Ѿ��鲢���ˣ�����������Ǹ������ұ��Ǹ�
//				//�ǲ�֪���ģ���ô���ǲ���д������ѭ����������ұ������ˣ��Ǿͽ����һ��
//				//ѭ������ʣ�µ�������һ�ŵ�tmp������ȥ������ͽ����һ��ѭ��
//				while (begin1 <= end1)
//				{
//					tmp[i++] = a[begin1++];
//				}
//				while (begin2 <= end2)
//				{
//					tmp[i++] = a[begin2++];
//				}
//			
//				//������鲢��tmp�ж�Ӧλ�õ����ݿ�����ԭ�����У�ע��Ҫ
//				//С�ĵؿ��Ʊ߽磬tmp�Ǵ�leftλ�ÿ�ʼ�ģ�������tmp+left
//				//ͬ���������ݻ�ԭ����Ҳ��Ҫ�ŵ�a+left��λ����ȥ�ģ�Ԫ�ظ���
//				//��right-left+1������Ϊ���������ұ����䣬�����Ҫ+1����Ԫ�ظ���
//				//���磬[0,9]���±�����9-0+1��Ԫ�ص�
//				memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//			}
//			
//			void MergeSortR(int* a, int n)
//			{
//				assert(a);
//				//����һ����ʱ�������ڴ�Ź鲢ʱ������
//				int* tmp = (int*)malloc(sizeof(int) * n);
//				if (tmp == NULL)
//				{
//					perror("");
//					return;
//				}
//			
//				_MergeSortR(a, 0, n - 1, tmp);
//			
//				free(tmp);
//				tmp = NULL;
//			}
