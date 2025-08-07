#include <iostream>
#include <vector>
using namespace std;

int parent[201];
int matrix[201][201];
int find(int x) {
	if (parent[x] == x) return x; // 부모
	return parent[x] = find(parent[x]);
}
void union_set(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) parent[a] = b;
}
int main() {
	int N; cin >> N;
	int M; cin >> M;

	for (int i = 1; i < N; i++) parent[i] = i;

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				union_set(i, j);
			}
		}
	}

	vector<int> cities;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		cities.push_back(num);
	}

	// 모든도시의 루트가 같은지 비교하면 됨.
	int root = find(cities[0]);

	for (int i = 1; i < M; i++) {
		if (find(cities[i]) != root) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}