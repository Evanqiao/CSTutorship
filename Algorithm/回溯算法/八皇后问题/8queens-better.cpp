#include <iostream>
using namespace std;

#define N 8

int matrix[N + 1] = {0};

bool isSafe(const int &row, const int &col) {
	for (int i = 1; i <= row - 1; ++i) {
		int j = matrix[i];
		if (  j == col || abs(i - row) == abs(j - col) )
			return false;
	}
	return true;
}

void print(void) {
	for (int i = 1; i <= N; i++) {
        cout << matrix[i] << " ";
	}
	cout << endl;
}

void solve(const int &row) {
	//	进入本函数时，在N*N的棋盘前row-1行已放置了互不攻击的row-1个棋子
	//	现从第row行起继续为后续棋子选择合适位置

	if (row > N)	//	输出当前的合法布局
		print();
	else {
		for (int j = 1; j <= N; ++j) {
			matrix[row] = j;
			if (isSafe(row, j))
				solve(row + 1);
			matrix[row] = 0;
		}
	}
}

int main(void) {
	solve(1);
	return 0;
}