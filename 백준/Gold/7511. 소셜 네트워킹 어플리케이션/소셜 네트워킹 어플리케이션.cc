#include<iostream>

using namespace std;
int parent[1000000];
int N, K, M;

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) parent[a] = b;
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Scenario " << t << ":\n";
		
		cin >> N;
		for (int i = 0; i < N; i++) parent[i] = i;
		cin >> K;
		
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			merge(a, b);
		}

		cin >> M;
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			if (find(a) == find(b)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << '\n';
	}
}