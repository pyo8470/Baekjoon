#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <tuple>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int Solution() {
	int x = 0, y = 0;

	deque<tuple<int, int,int>> q= { {x,y,1} };
	
	while (!q.empty()) {
		auto [cx, cy,count] = q.front();
		q.pop_front();
		visited[cy][cx] = true;
		// 탈출 조건
		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir], ny = cy + dy[dir];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || board[ny][nx] != 1) continue;

			if (ny == N - 1 && nx == M - 1) {
				return count + 1;
				break;
			}

			q.push_back({ nx,ny,count+1});
			visited[ny][nx] = true;

			/*for (int i = 0; i < q.size(); i++) {
				cout << get<0>(q[i]) << ", " << get<1>(q[i]) << ", " << get<2>(q[i]) << '\n';
			}*/
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	board.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false));
	//cout << N << M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = (int)(input[j] - '0');
		}
	}

	cout << Solution();
}