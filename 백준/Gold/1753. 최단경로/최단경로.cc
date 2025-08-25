#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define MAXV 20001
using namespace std;

int V, E;
int dijk[MAXV];
vector<vector<pair<int,int>>> adj;
bool visited[MAXV] = { false, };


void dijkstra(int start) {
	dijk[start] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push(make_pair(0,start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = pq.top().first;

		pq.pop();

		if (dijk[current] < distance) continue;
		for (int i = 0; i < adj[current].size(); i++) {

			int next = adj[current][i].first;
			int nextDistance = distance + adj[current][i].second;

			if (nextDistance >= dijk[next]) continue;
			dijk[next] = nextDistance;
			pq.push({ nextDistance, next });
		}
	}
}

int main() {
	cin >> V >> E;
	int K; cin >> K;
	for (int i = 0; i < MAXV; i++) {
		dijk[i] = 2e9; // 이렇게 반복문으로 초기화
	}
	adj.assign(V + 1, {});
	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back({ e,w });
	}
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dijk[i] == 2e9) cout << "INF" << "\n";
		else cout << dijk[i] << "\n";
	}
}