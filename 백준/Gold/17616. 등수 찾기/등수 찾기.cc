#include <iostream>
#include <vector>
using namespace std;

int N, M, X;
vector<vector<int>> better;
vector<vector<int>> worse;
vector<bool> visit;
int lowest;
int highest;

int dfs(int node,vector<vector<int>> &graph) {
	int count = 1;
	for (int next : graph[node]) {
		if (visit[next]) continue;
		visit[next] = true;
		count += dfs(next, graph);
	}

	return count;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> N >> M >> X;
	better.assign(N + 1, vector<int>());
	worse.assign(N + 1, vector<int>());
	for (int i = 0; i < M; i++) {
		int s, e; cin >> s >> e;
		worse[s].push_back(e);
		better[e].push_back(s);
	}
	lowest = N + 1;
	highest = 0;
	
	
	visit.assign(N + 1, false);
	lowest -= dfs(X, worse);
	visit.assign(N + 1, false);
	highest += dfs(X, better);
	cout << highest << " " << lowest;
}
