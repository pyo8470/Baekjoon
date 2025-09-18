#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int N, M;
vector<string> MAP;
int result = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct State
{
	int x, y, d;
};
int bfs(const int& sX, const int &sY) {
	queue<State> q;
	vector<vector<bool>> visited(N, vector<bool>(M,false));
	q.push({ sX,sY,0 });

	int ret = 0;
	while (!q.empty()) {
		State cur = q.front(); q.pop();
		int x = cur.x, y = cur.y, d = cur.d;
		visited[y][x] = true;
		ret = d;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (visited[ny][nx] || MAP[ny][nx] != 'L') continue;

			q.push({ nx,ny,d + 1});
			visited[ny][nx] = true;
		}
	}
	return ret;
	
}
void solve() {
	cin >> N >> M;
	MAP.assign(N, "");
	for (int i = 0; i < N; i++) cin >> MAP[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 'W') continue;
			result = max(bfs(j, i),result);
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();
	cout << result;
}