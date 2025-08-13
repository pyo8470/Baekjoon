#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>;
using namespace std;

typedef pair<int, int> pii;
int N, M, K, P;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;
void bfs(const int& start) {
	queue<pii> q;
	q.push({ start,0 });

	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		int node = cur.first;
		int cost = cur.second;
		if (cost == K) {
			result.push_back(node);
		}
		visited[node] = true;
		for (int next : adj[node]) {
			if (visited[next]) continue;
			if (cost + 1 > K) continue;

			q.push({ next,cost + 1 });
			visited[next] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K >> P;
	adj.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);
	for (int i = 0; i < M; i++) {
		int s, e; cin >> s >> e;
		adj[s].push_back(e);
	}
	
	visited[P] = true;
	bfs(P);

	sort(result.begin(), result.end());
	if (result.empty()) {
		cout << -1 << '\n';
	}
	for (int node : result) {
		cout << node << '\n';
	}
}