#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> Board;
vector<vector<bool>> visited;
vector<vector<int>> dp;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


void init() {
	cin >> N >> M;
	Board.assign(N, "");
	visited.assign(N, vector<bool>(M, false));
	dp.assign(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		cin >> Board[i];
	}
}
int dfs(vector<vector<bool>>& visited, const int& x,
	const int& y) {
	if (x < 0 || x >= M || y < 0 || y >= N || Board[y][x] == 'H')
		return 0;

	int& ret = dp[y][x];
	//cout << y << " | " << x << '\n';

	if (visited[y][x]) {
		//cout << "cycle\n";
		ret = 2e9;
		dp[y][x] = 2e9;
		return ret;
	}

	if (ret != -1) return ret;

	

	visited[y][x] = true;
	ret = 0;
	int count = Board[y][x] - '0';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * count;
		int ny = y + dy[i] * count;
		

		ret = max(ret,dfs(visited, nx, ny) + 1);
	}

	visited[y][x] = false;


	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	int ans = dfs(visited, 0, 0);
	(ans >= 2e9) ? cout << -1 : cout << ans;
}
