#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int MAP[1000][1000];
bool visit[1000][1000][2];

void input() {
	cin >> N >> M;
	for (int x = 0; x < N; ++x) {
		string input;
		cin >> input;
		for (int y = 0; y < M; ++y) {
			MAP[x][y] = input[y] - '0';
		}
	}

}

typedef struct {
	int x;
	int y;
	bool chance;
	int dist;
}Node;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS() {


	queue<Node> q;
	q.push({ 0, 0, true, 1 });


	visit[0][0][0] = true;

	while (!q.empty()) {
		Node e = q.front();
		q.pop();

		int c_x = e.x;
		int c_y = e.y;
		bool chance = e.chance;
		int c_dist = e.dist;

		if (c_x == N - 1 && c_y == M - 1) {
			return c_dist;
		}

		for (int d = 0; d < 4; ++d) {
			int n_x = c_x + dx[d];
			int n_y = c_y + dy[d];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;

			//다음이 벽
			if (MAP[n_x][n_y] == 1) {
				if (visit[n_x][n_y][chance]) continue;
				if (not chance) continue;

				q.push({ n_x, n_y, false, c_dist + 1 });
				visit[n_x][n_y][1] = true;
				
			}
			// 다음이 그냥 통로
			else {
				if (visit[n_x][n_y][chance]) continue;

				q.push({ n_x, n_y, chance, c_dist + 1 });
				visit[n_x][n_y][chance] = true;
			}
		}
	}


	return -1;

}

int main() {

	input();

	cout << BFS() << endl;

	return 0;
}

