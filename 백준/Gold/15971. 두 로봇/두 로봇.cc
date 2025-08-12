#include <iostream>
#include <vector>
using namespace std;

int N, A, B;
vector<vector<pair<int, int>>> matrix;
vector<bool> visit;
int MIN = 2e9;

void dfs(const int& node, const int& sum, int max_w) {
	if (node == B) {
		//cout << w << " " << max_w;
		MIN = min(MIN,(sum - max_w));
		return;
	}

	for (pair<int,int> n : matrix[node]) {
		int next = n.first;
		int next_w = n.second;
		if (visit[next]) continue;
		visit[next] = true;
		dfs(next, sum + next_w, max(max_w,next_w));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B;
	matrix.assign(N + 1, {});
	visit.assign(N + 1, false);
	for (int i = 0; i < N - 1; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		matrix[s].push_back({ e, w });
		matrix[e].push_back({ s, w });
	}

	// A에서 B로가는 경로에서 가장 큰 가중치를 하나 빼면 된다.
	visit[A] = true;
	dfs(A, 0, 0);

	cout << MIN;
}