#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



int N;
int answer = 0;
vector<int> queen;
bool check(int col, int row) {
	
	for (int i = 0; i < N; i++) {
		int Queen_row = queen[i];
		// 같은 col은 안된다.
		if (Queen_row >= 0){
			// 가로
			if (row == Queen_row) return false;
			// 세로
			if (col == i) return false;
			// 대각선
			if (abs(row - Queen_row) == abs(col - i)) return false;
		}
	}

	return true;
}
void N_Queen(int col) {
	if (col== N) {
		answer++; return;
	}

	for (int row = 0; row < N; row++) {
		// 퀸이 depth행 i번째 열에 위치한다.
		if (!check(col, row)) continue;
        // 배치
		queen[col] = row;
		N_Queen(col+ 1);
        // 배치 물림
		queen[col] = -1;
	}
}
int main() {
	cin >> N;
	queen.resize(N, -1);

	N_Queen(0);
	cout << answer;
}