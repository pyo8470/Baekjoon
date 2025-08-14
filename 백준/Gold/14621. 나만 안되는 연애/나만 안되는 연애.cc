#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, M;


struct inform {
	int s, e, w;
};
vector<inform> adj;
vector<char> univ_sex;
vector<int> parent;
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	parent[b] = a;
}
int kruskal() {
	
	int answer = 0;
	sort(adj.begin(), adj.end(), [](inform a, inform b) {
		return a.w < b.w;
		});
	
	int count = 1;
	for (const inform& cur : adj) {
		int s = cur.s, e = cur.e, w = cur.w;

		// 사이클 검사
		if (find(s) == find(e)) continue;
		// 동성 검사
		if (univ_sex[s] == univ_sex[e]) continue;
		merge(s, e);
		answer += w;
		count++;
	}
	return count == N ? answer : -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	adj.resize(N);
	univ_sex.resize(N+1);
	parent.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> univ_sex[i + 1];
		parent[i + 1] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		int s, e, w; cin >> s >> e >> w;
		adj.push_back({ s, e, w });
	}

	cout << kruskal();
}