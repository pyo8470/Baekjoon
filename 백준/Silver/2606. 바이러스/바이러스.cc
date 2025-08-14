#include<iostream>
#include<vector>
using namespace std;

int N, E;
vector<vector<int>> matrix;
vector<bool> visited;
int answer = 0;
void dfs(int node) {
	visited[node] = 1;
	answer++;
	for (int next : matrix[node]) {
		if (visited[next]) continue;
		visited[next] = true;
		dfs(next);
	}
}
int main() {
	cin >> N;
	matrix.assign(N + 1,vector<int>());
	visited.assign(N + 1, false);
	cin >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}

	dfs(1);
	cout << answer - 1;
}