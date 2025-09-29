#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int V, E;
struct Edge {
	int to, wei;
};
vector<vector<Edge>> adj;

struct State {
	int dist, node;
	bool operator<(const State &other) const {
		return dist > other.dist; // 최소 힙
	}
};

vector<int> dijkstra(int start) {
	vector<int> dist(V + 1, INF);
	priority_queue<State> pq;
	dist[start] = 0;
	pq.push( { 0, start });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.dist > dist[cur.node])
			continue;
		for (auto nxt : adj[cur.node]) {
			int nd = cur.dist + nxt.wei;
			if (nd < dist[nxt.to]) {
				dist[nxt.to] = nd;
				pq.push( { nd, nxt.to });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	adj.assign(V + 1, { });
	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back( { e, w });
	}

	int ans = INF;
	for (int i = 1; i <= V; i++) {
		vector<int> dist = dijkstra(i); // i → *
		for (int v = 1; v <= V; v++) {
			if (v == i)
				continue;
			if (dist[v] == INF)
				continue;

			// v에서 다시 i로 오는 간선이 있어야 사이클 완성
			for (auto e : adj[v]) {
				if (e.to == i) {
					ans = min(ans, dist[v] + e.wei);
				}
			}
		}
	}

	if (ans == INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}
