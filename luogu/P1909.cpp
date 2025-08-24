//https://www.luogu.com.cn/problem/P1909
#include<iostream>
using namespace std;
int findMin(int* arr){
	int min = arr[0];
	for (int i = 1; i < 3; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}
int main() {
	int n;
	int** arr = new int* [3];
	int* coast = new int[3];
	cin >> n;
	for (int i = 0; i < 3; i++) {
		arr[i] = new int[2];
		coast[i] = 0;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		int num = 0;
		while (num < n) {
			coast[i] += arr[i][1];
			num += arr[i][0];
		}
	}
	cout << findMin(coast) << endl;

	for (int i = 0; i < 3; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}