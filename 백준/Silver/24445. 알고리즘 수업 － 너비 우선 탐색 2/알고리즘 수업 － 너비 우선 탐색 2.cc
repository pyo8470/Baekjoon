#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_LEN 100000
using namespace std;

int N, M, R;
vector<vector<int>> adj;
bool visited[MAX_LEN + 1] = { false, };
int result[MAX_LEN + 1] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> R;
	adj.assign(N+1, {});

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end(),greater<int>());
	}

	queue<int> q;
	q.push(R);
	
	int rank = 1;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		visited[cur] = true;
		result[cur] = rank++;
		for (int& next : adj[cur]) {
			if (visited[next]) continue;

			q.push(next); visited[next] = true;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}

