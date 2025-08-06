#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



int N;
int answer = 0;
bool visited_row[15];      // 세로
bool visited_diag1[30];    // ↘ 대각선 (col - row + N - 1)
bool visited_diag2[30];    // ↗ 대각선 (row+col)

void N_Queen(int col) {
	if (col== N) {
		answer++; return;
	}

	for (int row = 0; row < N; row++) {
		// 퀸이 depth행 i번째 열에 위치한다.
		if (visited_row[row]) continue;
		if (visited_diag1[row - col + N - 1]) continue;
		if (visited_diag2[row+col]) continue;

		visited_row[row] = true;
		visited_diag1[row - col + N - 1] = true;
		visited_diag2[row+col] = true;
		N_Queen(col + 1);

		visited_row[row] = false;
		visited_diag1[row - col + N - 1] = false;
		visited_diag2[row+col] = false;
	}
}
int main() {
	cin >> N;
	N_Queen(0);
	cout << answer;
}