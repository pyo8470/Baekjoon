#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
// 타순에 해당하는 번호
// 입력으로 들어오는것 -> 등번호에 해당하는 성적
int N;
// 1번선수는 4번타자 고정이기 때문에 뺀다.

vector<vector<int>> playing;
// 타순에 따른 배팅
int playBall(vector<int> &lineup) { // 라인업
	int score = 0;
	int nextPlayer = 0;
	for (int inning = 0; inning < N; inning++) {
		int outCount = 0;
		// 베이스 1 2 3루
		// 
		bool base[3] = { false, };
		// 3아웃 되기 전까지 무한
		while (outCount < 3) {
			int player = lineup[nextPlayer]; // 선수의 번호
			int result = playing[inning][player];
			if (result == 0) {
				outCount++;
			}

			else if (result == 1) {
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
			nextPlayer = (nextPlayer + 1) % 9;
		}
	}
	return score;
}

int main() {
	// 야구
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> order = { 1,2,3,4,5,6,7,8 };
	playing.assign(N,vector<int>(9));
	for (int i = 0; i < N; i++) {
		for(int j=0; j<9; j++){
			cin >> playing[i][j];
		}
	}

	int maxScore = 0;
	// 모든 조합에 대해서 루프 돌리기
	do {
		vector<int> lineup(9);
		int ord = 0;
		for (int i = 0;i < 9; i++) {
			if (i == 3) lineup[i] = 0;
			else lineup[i] = order[ord++];
		}

		maxScore = max(playBall(lineup), maxScore);
	} while (next_permutation(order.begin(), order.end()));

	cout << maxScore;
}

