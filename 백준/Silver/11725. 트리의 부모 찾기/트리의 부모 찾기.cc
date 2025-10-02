#include <iostream>
#include <algorithm>
#include <vector>

#define ROOT 1
using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
void init() {
	cin >> N; adj.assign(N + 1, {});
	visited.assign(N + 1, false);
	parent.assign(N + 1, 0);
	for (int i = 0; i < N - 1; i++) {
		int s, e; cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
}

void dfs(const int& root) {
	visited[root] = true;
	for (const int& child : adj[root]) {
		if (visited[child]) continue;
		parent[child] = root;
		dfs(child);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	dfs(ROOT);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}
