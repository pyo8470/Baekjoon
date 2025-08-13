#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>;
using namespace std;
typedef pair<int, int> pii;
int N, K, M;
vector<vector<int>> nodes;
vector<vector<int>> hypers;
vector<bool> visited_n;
vector<bool> visited_h;
int bfs() {
	queue<pii> node_q;
	//queue<int> hyper_q;

	node_q.push({ 1 , 1});
	/*for(int hyper: nodes[1]) {
		hyper_q.push(hyper);
	}*/

	while (!node_q.empty()) {
		pii cur = node_q.front(); node_q.pop();
		int cur_node = cur.first;
		int cur_cost = cur.second;
		visited_n[cur_node] = true;

		//cout << cur_node << " " << cur_cost << '\n';
		if (cur_node == N) {
			return cur_cost;
		}
		for (int hyper : nodes[cur_node]) {
			if (visited_h[hyper]) continue;
			for (int next : hypers[hyper]) {
				if (visited_n[next]) continue;
				visited_n[next] = true;
				node_q.push({ next,cur_cost + 1 });

			}
			visited_h[hyper] = true;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K >> M;
	nodes.assign(N + 1, vector<int>());
	hypers.assign(M + 1, vector<int>());
	visited_n.assign(N + 1, false);
	visited_h.assign(M + 1, false);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= K; j++) {
			int node; cin >> node;
			nodes[node].push_back(i);
			hypers[i].push_back(node);
		}
	}
	
	cout << bfs();
}