#include <iostream>
#include <vector>
using namespace std;
int parent[1000001];
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;
	parent[u] = v;
	
}
int main() {
	int n, m;
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		// 연결
		if (command == 0) {
			merge(a, b);
		}
		else {
			if (a == b) cout << "YES" << '\n';
			else if (find(a) == find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}