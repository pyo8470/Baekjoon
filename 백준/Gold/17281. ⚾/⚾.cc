#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
int N;
int maxOut;
// 타순에 해당하는 번호
// 입력으로 들어오는것 -> 등번호에 해당하는 성적
vector<vector<int>> play;

int calculation(vector<int>& order) {
	// 점수 계산

	int score = 0;
	int nextPlayer = 0;
	for (int inning = 0; inning < N; inning++) {
		int outCount = 0;
		// 1,2,3
		bool base[3] = { false, };


		while (outCount < 3) {
			int player = order[nextPlayer];
			int result = play[inning][player];

			if (result == 0) {
				outCount++;
			}
			else {
				if (result == 1) {
					if (base[2]) score++;
					base[2] = base[1];
					base[1] = base[0];
					base[0] = true;
				}
				else if (result == 2) {
					if (base[2]) score++;
					if (base[1]) score++;
					base[2] = base[0];
					base[1] = true;
					base[0] = false;
				}
				else if (result == 3) {
					
					for (int i = 0; i < 3; i++) {
						if (base[i]) score++;
						base[i] = false;
					}
					base[2] = true;
				}
				else if (result == 4) {
					for (int i = 0; i < 3; i++) {
						if (base[i]) score++;
						base[i] = false;
					}
					score++;

				}
			}
			nextPlayer = (nextPlayer + 1) % 9;
		}
	}
	return score;
}
int main() {
	// 야구
	cin >> N;
	maxOut = N * 2;
	play.assign(N, vector<int>(9));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> play[i][j];
		}
	}

	// 타순 돌리기
	int maxScore = 0;
	vector<int> order = { 1,2,3,4,5,6,7,8 };
	do {
		vector<int> batting(9);
		for (int i = 0, j = 0; i < 9; i++) {
			// 4번타자 -> 등번호 1번
			if (i == 3) batting[i] = 0;
			else batting[i] = order[j++];
		}
		maxScore = max(maxScore, calculation(batting));
	} while (next_permutation(order.begin(), order.end()));
	cout << maxScore;
}

