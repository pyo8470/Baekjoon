#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <tuple>
using namespace std;

int N, M;
vector<vector<char>> board;
vector<vector<bool>> visited;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> fire;
pair<int, int> jihoon;
bool escape(int x, int y) {
	return (x == 0 || x == M - 1 || y == 0 || y == N - 1);
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}
void Solution() {
	deque <tuple<int, int>> fire_q;
	deque <tuple<int, int, int>> jihoon_q;

	for (auto [cx, cy] : fire) {
		fire_q.push_back({ cx,cy });
	}
	jihoon_q.push_back({ jihoon.first,jihoon.second ,0 });
	int result = 0;
	while (!jihoon_q.empty()) {
		// 불 먼저
		int fire_size = fire_q.size();
		while (fire_size--) {
			auto [fx, fy] = fire_q.front();
			fire_q.pop_front();

			for (int i = 0; i < 4; i++) {
				int nfx, nfy;
				nfx = fx + dx[i]; nfy = fy + dy[i];
				if (nfx < 0 || nfx >= M || nfy < 0 || nfy >= N) continue;
				if (board[nfy][nfx] == '#' || board[nfy][nfx] == 'F') continue;
				board[nfy][nfx] = 'F';
				fire_q.push_back({ nfx,nfy });
			}
		}
		int jihoon_size = jihoon_q.size();
		while (jihoon_size--) {
			auto [x, y, count] = jihoon_q.front();
			visited[y][x] = true;
			jihoon_q.pop_front();
			if (escape(x, y)) {
				cout << count + 1; return;
			}
			for (int i = 0; i < 4; i++) {
				int nx, ny;
				nx = x + dx[i]; ny = y + dy[i];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
				if (visited[ny][nx] || board[ny][nx] != '.') continue;
				board[ny][nx] = 'J';
				jihoon_q.push_back({ nx,ny,count + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	cout << "IMPOSSIBLE";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	board.resize(N, vector<char>(M));
	visited.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == 'J') {
				jihoon = { x,y };
			}
			if (board[y][x] == 'F') {
				fire.push_back({ x,y });
			}
		}
	}

	Solution();
}