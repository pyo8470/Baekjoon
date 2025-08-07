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

	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			if (find(cities[i]) != find(cities[j])) {
				cout << "NO"; return 0;
			}
		}
	}
	cout << "YES";
}