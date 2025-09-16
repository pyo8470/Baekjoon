#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_LEN 1001
using namespace std;
typedef pair<int, int> pii;

int V, E;
int parent[10001];
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int A = find(a);
	int B = find(b);

	if (A == B) return;
	parent[A] = B;
}

struct Edge {
	int s, e, w;
};
vector<Edge> adj;

int kruskal() {
	int ret = 0;
	for (Edge& cur : adj) {
		int u = cur.s, v = cur.e, w = cur.w;
		if (find(u) == find(v)) continue;
		merge(u, v);
		ret += w;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 0; i < E; i++) {
		int s, e, w; cin >> s >> e >> w;
		adj.push_back({ s,e,w });
	}


	sort(adj.begin(), adj.end(), [](const Edge& a, const Edge& b) {
		return a.w < b.w;
		});

	
	cout << kruskal();
}
