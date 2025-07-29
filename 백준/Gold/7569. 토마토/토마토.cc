#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <tuple>
using namespace std;

int N, M ,H;
vector<vector<vector<int>>> board;
vector<vector<vector<bool>>> visited;
vector<tuple<int, int, int >> tomato;
int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

int Solution() {
	
	int day = 0;
	deque<tuple<int, int, int,int>> q;
	for (auto [x, y, z] : tomato) {
		q.push_back({ x,y,z,day });
		visited[z][y][x] = true;
	}
	
	while (!q.empty()) {
		auto [cx, cy, cz, count] = q.front();
		q.pop_front();
		day = max(count, day);
		visited[cz][cy][cx] = true;
		for (int dir = 0; dir < 6; dir++) {
			int nx = cx + dx[dir], ny = cy + dy[dir], nz= cz + dz[dir];

			if (nz <0 || nz >= H || nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[nz][ny][nx] || board[nz][ny][nx] != 0) continue;

			q.push_back({ nx,ny,nz, count + 1});
			visited[nz][ny][nx] = true;
			board[nz][ny][nx] = 1;
			
		}
		//print();
	}
	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				if (board[z][y][x] == 0) return -1;
			}
		}
	}

	return day;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	board.resize(H, vector<vector<int>>(N, vector<int>(M)));
	visited.resize(H, vector<vector<bool>>(N, vector<bool>(M)));
	for(int z = 0; z <H; z++){
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> board[z][y][x];
				if (board[z][y][x] == 1) tomato.push_back({ x,y,z });
			}
		}
	}

	int result = 0;
	result = Solution();
	cout << result;
}