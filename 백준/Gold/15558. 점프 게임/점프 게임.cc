#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int N, K;
vector<string> MAP(2);
vector<vector<bool>> visited;

bool isValid(int index) {
	return index >= 0 && index < N;
}

// 다음 칸이 시간에 따라 사라지지 않았는지 체크
struct Pair {
	int x, y, t;
};

int bfs() {
	deque<Pair> q = { {0,0,0} };
	visited[0][0] = true;

	while (!q.empty()) {
		Pair cur = q.front(); q.pop_front();

		int dx[3] = { -1,1,K };
		int dy[3] = { cur.y,cur.y,(cur.y + 1) % 2 };

		for (int i = 0; i < 3; i++) {
			int nx, ny;
			nx = cur.x + dx[i];
			ny = dy[i];

			if (nx >= N) return 1;
			if (cur.t >= nx) continue;
			if (MAP[ny][nx] != '1') continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push_back({ nx,ny,cur.t + 1 });

		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	string input;
	cin >> input; MAP[0] = input;
	cin >> input; MAP[1] = input;
	visited.assign(2, vector<bool>(N, false));

	cout << bfs();
}
