#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

#define MAX 50
using namespace std;

int N,M;

int board[MAX][MAX];
struct cord {
	int x, y;
};

vector<cord> cand;
int answer = 2e9;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct State {
	int x, y, COUNT;
};
int blank = 0;


int bfs(vector<cord> &virus) {
	deque<State> dq;
	bool visited[MAX][MAX] = { false, };

	for (cord &v : virus) {
		dq.push_back({ v.x,v.y,0 });
		visited[v.y][v.x] = true;
	}

	int ret = 0;
	int filled = 0;
	while (!dq.empty()) {
		State cur = dq.front(); dq.pop_front();

		int x =  cur.x, y = cur.y, COUNT = cur.COUNT;
		
		filled++;
		ret = COUNT;
		visited[y][x] = true;
		if (ret >= answer) return answer;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (board[ny][nx] == 1 || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			dq.push_back({ nx,ny,COUNT + 1 });
		}

	}
	return (filled == blank) ? ret : 2e9;
}

void combination(const int &idx, const int &depth,vector<cord> &virus) {

	if (depth == M) {
		answer = min(bfs(virus), answer);
		return;
	}
	for (int i = idx; i < cand.size(); i++) {
		virus.push_back(cand[i]);
		combination(i + 1, depth + 1,virus);
		virus.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) cand.push_back({ j,i });
			if (board[i][j] != 1) blank++;
		}
	}

	vector<cord> virus;
	combination(0, 0,virus);


	answer == 2e9 ? cout << -1 : cout << answer;
}