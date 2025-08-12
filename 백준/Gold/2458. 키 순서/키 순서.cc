#include <iostream>
#include <vector>
using namespace std;

int N, M, X;
vector<vector<int>> better;
vector<vector<int>> worse;
vector<bool> visit;
vector<int> result;


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


	cin >> N >> M;
	better.assign(N + 1, vector<int>());
	worse.assign(N + 1, vector<int>());
	for (int i = 0; i < M; i++) {
		int s, e; cin >> s >> e;
		worse[s].push_back(e);
		better[e].push_back(s);
	}
	result.assign(N + 1, 0);
	
	for (int i = 1; i <= N; i++) {
		visit.assign(N + 1, false);
		result[i] += dfs(i, worse);
		visit.assign(N + 1, false);
		result[i] += dfs(i, better);
	}

	int answer = 0;
	
	for (int i : result) {
		if (i > N) answer++;
	}

	cout << answer;
}
