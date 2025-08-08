#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
using namespace std;

int N, M;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };
int ans;
vector<vector<int>> field;
vector<vector<bool>> visited;
bool isVaild(const int& x, const int& y) {
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	return true;
}

int bfs(const int& x, const int& y) {

	deque<pair<int, int>> dq;
	dq.push_back({ x,y });
	visited[y][x] = true;

	while (!dq.empty()) {
		int cx = dq.front().first, cy = dq.front().second;
		dq.pop_front();

		visited[cy][cx] = true;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!isVaild(nx, ny))continue;
			if (visited[ny][nx])continue;
			if (field[ny][nx] != 1) continue;

			dq.push_back({ nx,ny });
			visited[ny][nx] = true;
		}
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int K; cin >> M >> N >> K;
		field.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<bool>(M, false));
		ans = 0;
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && field[i][j] == 1) {
					ans += bfs(j, i);
				}
			}
		}
		cout << ans << '\n';
	}
}