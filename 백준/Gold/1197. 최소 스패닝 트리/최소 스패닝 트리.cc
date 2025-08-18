#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define DIR 4
using namespace std;
typedef pair<int, int> pii;

int V, E;
vector<bool> visited;
vector<vector<pii>> edges;
int kruskal() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,1 });
	
	int answer = 0;
	while (!pq.empty()) {
		pii current = pq.top(); pq.pop();
		
		int w = current.first, node = current.second;
		if (visited[node]) continue;
		visited[node] = true;
		/*count++;
		cout << s << " " << w << '\n';*/
		answer += w;
		for (pii next : edges[node]) {
			int nv = next.second;
			int nw = next.first;
			pq.push({nw,nv });
		}
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	edges.assign(V + 1, {});
	visited.assign(V + 1, false);
	
	for (int i = 0; i < E; i++) {
		int s, e, w; cin >> s >> e >> w;
		edges[s].push_back({ w,e });
		edges[e].push_back({ w,s });
	}
	cout << kruskal();
}
