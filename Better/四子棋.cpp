#include<iostream>
using namespace std;
void print(int** R6) {
	system("cls");
	for (int R1 = 0; R1 <= 5; R1++) {
		for (int R2 = 0; R2 <= 5; R2++) {
			if (*(*(R6 + R1) + R2) == 0) {
				cout << "- ";
			}
			else if (*(*(R6 + R1) + R2) == 1) {
				cout << "O ";
			}
			else {
				cout << "X ";
			}
		}
		cout << '\n';
	}
}
int isOver(int** R6) {
	int sum = 0;
	for (int R1 = 5; R1 >= 0; R1--) {
		for (int R2 = 2; R2 >= 0; R2--) {
			sum = 0;
			for (int R3 = 3; R3 >= 0; R3--) {
				sum += *(*(R6 + R1) + R3 + R2);// 横
			}
			if (sum == 4) {
				return 1;
			}
			else if (sum == -4) {
				return -1;
			}
		}
	}
	for (int R1 = 2; R1 >= 0; R1--) {
		for (int R2 = 5; R2 >= 0; R2--) {
			sum = 0;
			for (int R3 = 3; R3 >= 0; R3--) {// 纵
				sum += *(*(R6 + R3 + R1) + R2);
			}
			if (sum == 4) {
				return 1;
			}
			else if (sum == -4) {
				return -1;
			}
		}
	}
	for (int R1 = 2; R1 >= 0; R1--) {
		for (int R2 = 2; R2 >= 0; R2--) {
			sum = 0;
			for (int R3 = 3; R3 >= 0; R3--) {
				sum += *(*(R6 + R1 + R3) + R3 + R2);// 右下
			}
			if (sum == 4) {
				return 1;
			}
			else if (sum == -4) {
				return -1;
			}
		}
	}
	for (int R1 = 2; R1 >= 0; R1--) {
		for (int R2 = 5; R2 >= 3; R2--) {
			for (int R3 = 3; R3 >= 0; R3--) {
				sum += *(*(R6 + R1 + R3) + R2 - R3);// 左下
			}
			if (sum == 4) {
				return 1;
			}
			else if (sum == -4) {
				return -1;
			}
		}
	}
	sum = 0;
	for (int R1 = 5; R1 >= 0; R1--) {
		for (int R2 = 5; R2 >= 0; R2--) {
			if (*(*(R6 + R1) + R2)) {
				sum++;
			}
		}
	}
	if (R6 - 36 == 0) {
		return 2;// 平局
	}
	return 0;
}
void input(int** R6, int player) {
	int R0;
	while (1) {
		cout << "Player" << (player == 1 ? "A: " : "B: ");
		cin >> R0;
		R0--;
		for (int R1 = 5; R1 >= 0; R1--) {//从下往上历遍
			if (*(*(R6 + R1) + R0) != 0) {

			}
			else {// 遇到0
				*(*(R6 + R1) + R0) = player;
				print(R6);
				return;
			}
		}
		// 没有空位重新输ru
		print(R6);
		cout << "Invalid Value\n";
	}
}
int main(void) {
	int** Arr = new int* [6];
	for (int R1 = 5; R1 >= 0; R1--) {
		Arr[R1] = new int[6];
	}
	for (int R1 = 5; R1 >= 0; R1--) {
		for (int R2 = 5; R2 >= 0; R2--) {
			Arr[R1][R2] = 0;
		}
	}
	print(Arr);
	while (1) {
		input(Arr, 1);
		int cnt = isOver(Arr);
		if (cnt == -1) {
			cout << "A Win\n";
			return 0;
		}
		else if (cnt == 2) {
			cout << "same\n";
		}
		input(Arr, -1);
		int cnt = isOver(Arr);
		if (cnt ==-1) {
			cout << "B Win\n";
			return 0;
		}
		else if (cnt == 2) {
			cout << "same\n";
		}
	}
	return 0;
}