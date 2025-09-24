#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_N 8
#define MAX_M 8

int N, M;
int MAP[MAX_N][MAX_M];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct CCTV {
	int x, y;
	int type, dir;
};

vector<CCTV> CT_vec;
int answer = 0;
int volume;
int length;
void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] <= 5 && MAP[i][j] >= 1) CT_vec.push_back({ j,i,MAP[i][j],0 });
			else if (MAP[i][j] == 0) answer++;
		}
	}
	volume = answer;
	length = CT_vec.size();
}
int findDead() {

	int TEMP[MAX_N][MAX_M];
	memcpy(TEMP, MAP, sizeof(MAP));
	int sum = 0;
	for (CCTV& cur : CT_vec) {
		int type = cur.type;
		int dir = cur.dir;

		int x = cur.x, y = cur.y;
		if (type == 1) {
			int len = 1;
			while (true) {
				int nx = x + dx[dir] * len;
				int ny = y + dy[dir] * len;

				if (nx < 0 || ny < 0 || nx >= M || ny >= N) break; // 범위 밖
				if (TEMP[ny][nx] == 6) break; // 빈공간이 아님



				len++;
				if (TEMP[ny][nx] != 0) continue; // 이미 탐색한 부분

				TEMP[ny][nx] = -1;
				sum++;

			}
		}
		else if (type == 2) {
			
			for (int i = 0; i < 2; i++) {
				int len = 1;
				while (true) {
					int nx = x + dx[(dir + i * 2) % 4] * len;
					int ny = y + dy[(dir + i * 2) % 4] * len;

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) break; // 범위 밖
					if (TEMP[ny][nx] == 6) break; // 빈공간이 아님


					len++;
					if (TEMP[ny][nx] != 0) continue; // 이미 탐색한 부분

					TEMP[ny][nx] = -1;
					sum++;

				}
			}
		}
		else if (type == 3) {

			for (int i = 0; i < 2; i++) {
				int len = 1;
				while (true) {
					int nx = x + dx[(dir + i) % 4] * len;
					int ny = y + dy[(dir + i) % 4] * len;

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) break; // 범위 밖
					if (TEMP[ny][nx] == 6) break; // 빈공간이 아님



					len++;
					if (TEMP[ny][nx] != 0) continue; // 이미 탐색한 부분

					TEMP[ny][nx] = -1;
					sum++;

				}
			}
		}
		else if (type == 4) {

			for (int i = 0; i < 3; i++) {
				int len = 1;
				while (true) {
					int nx = x + dx[(dir + i) % 4] * len;
					int ny = y + dy[(dir + i) % 4] * len;

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) break; // 범위 밖
					if (TEMP[ny][nx] == 6) break; // 빈공간이 아님



					len++;
					if (TEMP[ny][nx] != 0) continue; // 이미 탐색한 부분
					TEMP[ny][nx] = -1;
					sum++;

				}
			}
		}
		else if (type == 5) {

			for (int i = 0; i < 4; i++) {
				int len = 1;
				while (true) {
					int nx = x + dx[(dir + i) % 4] * len;
					int ny = y + dy[(dir + i) % 4] * len;

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) break; // 범위 밖
					if (TEMP[ny][nx] == 6) break; // 빈공간이 아님


					len++;
					if (TEMP[ny][nx] != 0) continue; // 이미 탐색한 부분
					TEMP[ny][nx] = -1;
					sum++;

				}
			}
		}
	}

	/*cout << "0칸개수 ->" << volume << '\n';
	cout << "사각지대 -> " << sum << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(2) <<TEMP[i][j] << " ";
		}cout << '\n';
	}cout << '\n';*/
	
	return sum;
}
void backtracking(const int& depth) {
	if (depth == length) {
		// 탐색
		answer = min(answer, volume - findDead());
		return;
	}



	int prev = CT_vec[depth].dir;
	int type = CT_vec[depth].type;
	if (type == 2) {
		for (int d = 0; d < 2; d++) {
			CT_vec[depth].dir = (CT_vec[depth].dir + d) % 2;
			backtracking(depth + 1);
		}
	}
	else if (type == 1 || type == 3 || type == 4) {
		for (int d = 0; d < 4; d++) {
			CT_vec[depth].dir = (CT_vec[depth].dir + d) % 4;
			backtracking(depth + 1);
		}
	}
	else {
		backtracking(depth + 1);
	}

	CT_vec[depth].dir = prev;


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	backtracking(0);
	cout << answer;
}
