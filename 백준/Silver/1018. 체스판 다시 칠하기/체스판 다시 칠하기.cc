#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
	int N,M; cin >> N >> M;

	vector<string> board(N);
	for (int i = 0; i < N; i++) cin >> board[i];

	/*
	이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
			// 행렬을 더했을 때 짝수라면 같은 색, 홀수라면 다른색이어야한다

	*/
	int result = INT_MAX;
	for (int y = 0; y <= N - 8; y++) {
		for (int x = 0; x <= M - 8; x++) {
			// 흰색 시작
			int whiteCount = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if ((i + j) % 2 == 0) {
						if (board[y + i][x + j] == 'B') whiteCount++;
					}
					else {
						if (board[y + i][x + j] == 'W') whiteCount++;
					}
				}
			}
			int blackCount = 0;
			// 검은색 시작
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if ((i + j) % 2 == 0) {
						if (board[y + i][x + j] == 'W') blackCount++;
					}
					else {
						if (board[y + i][x + j] == 'B') blackCount++;
					}
				}
			}
			result = min(min(blackCount, whiteCount), result);
		}
	}
	cout << result;
}