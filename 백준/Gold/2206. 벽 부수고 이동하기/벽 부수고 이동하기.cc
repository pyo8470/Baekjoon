#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M;
vector<vector<int>> MAP;
vector<vector<vector<bool>>> visited;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct State
{
	int x, y, count;
	bool broken;
};

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	MAP.assign(N, vector<int>(M));
	visited.assign(N, vector<vector<bool>>(M, vector<bool>(2, false)));
	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = (input[j] - '0');
		}
	}
}

int bfs() {
	deque<State> dq = { {0,0,0,false} };
	int result = 2e9;

	while (!dq.empty()) {
		State cur = dq.front(); dq.pop_front();

		int x, y, count; bool broken;
		x = cur.x, y = cur.y, count = cur.count, broken = cur.broken;

		//cout << x << " " << y << '\n';
		if (x == M - 1 && y == N - 1) {
			result = min(count+1, result);
			continue;
		}
		if (count >= result) continue;
		visited[y][x][broken] = true;

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx][broken]) continue;
			if (broken && MAP[ny][nx] == 1) continue;
			if (MAP[ny][nx] == 1 && !broken) {
				dq.push_back({ nx,ny,count + 1, !broken });
			}
			else {
				dq.push_back({ nx,ny,count + 1,broken });
			}
			visited[ny][nx][broken] = true;
		}
	}
	return result == 2e9 ? -1 : result;
}
int main() {
	init();

	cout << bfs();
}
