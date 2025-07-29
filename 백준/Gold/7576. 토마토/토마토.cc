#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <tuple>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pair<int, int>> tomato;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void print() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cout << board[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int Solution() {
	
	int day = 0;
	deque<tuple<int, int, int>> q;
	for (auto [x, y] : tomato) {
		q.push_back({ x,y,day });
		visited[y][x] = true;
	}
	
	while (!q.empty()) {
		auto [cx, cy, count] = q.front();
		q.pop_front();
		day = max(count, day);
		visited[cy][cx] = true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir], ny = cy + dy[dir];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || board[ny][nx] == 1 || board[ny][nx] == -1) continue;

			q.push_back({ nx,ny, count + 1});
			visited[ny][nx] = true;
			board[ny][nx] = 1;
			
		}
		//print();
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] == 0) return -1;
		}
	}

	return day;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	board.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
			if (board[y][x] == 1) tomato.push_back({ x,y });
		}
	}

	int result = 0;
	result = Solution();
	cout << result;
}