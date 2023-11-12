
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
//参考（mad）写了好久才会，我好废。
// 
//			void _MergeSortR(int* a, int left, int right, int* tmp)
//			{
//				//如果递归到小区间只有一个值(left==right)或者不存在(left>right)，则返回
//				if (left >= right)
//				{
//					return;
//				}
//			
//				//递归把需要排序的大区间逐步二分成小区间，直到区间只有
//				//一个值或者区间不存在的时候再开始归并且回归
//				int mid = (left + right) / 2;
//				_MergeSortR(a, left, mid, tmp);
//				_MergeSortR(a, mid + 1, right, tmp);
//			
//				//来到这的时候说明区间只有一个值或者区间不存在了，开始归并
//				int begin1 = left;
//				int end1 = mid;
//				int begin2 = mid + 1;
//				int end2 = right;
//			
//				//两个小数组归并时把数据归并到开辟的临时数组tmp中，从left位置开始放，
//				//方便归并完数组的数据之后把tmp数据拷贝回到原数组中
//				int i = left;
//			
//				//当两个小数组都还有数据就继续归并，直到某一个小数组没有数据了就停止
//				while (begin1 <= end1 && begin2 <= end2)
//				{
//					//哪个数据小就把它归并到tmp对应的位置上去(升序)
//					if (a[begin1] <= a[begin2])
//					{
//						tmp[i++] = a[begin1++];
//					}
//					else
//					{
//						tmp[i++] = a[begin2++];
//					}
//				}
//				//来到这的时候一定有一个小数组已经归并完了，但是是左边那个还是右边那个
//				//是不知道的，那么我们不妨写下两个循环，如果是右边走完了，那就进入第一个
//				//循环，把剩下的数据逐一放到tmp数组中去，否则就进入第一个循环
//				while (begin1 <= end1)
//				{
//					tmp[i++] = a[begin1++];
//				}
//				while (begin2 <= end2)
//				{
//					tmp[i++] = a[begin2++];
//				}
//			
//				//最后把这归并到tmp中对应位置的数据拷贝回原数组中，注意要
//				//小心地控制边界，tmp是从left位置开始的，所以是tmp+left
//				//同理，拷贝数据回原数组也是要放到a+left的位置上去的，元素个数
//				//是right-left+1个，因为这个是左闭右闭区间，最后需要+1才是元素个数
//				//例如，[0,9]的下标是有9-0+1个元素的
//				memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//			}
//			
//			void MergeSortR(int* a, int n)
//			{
//				assert(a);
//				//开辟一个临时数组用于存放归并时的数据
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
