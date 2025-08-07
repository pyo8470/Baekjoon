#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[500001];

int find(int x) {
	if (parent[x] == x) return parent[x];
	return parent[x] = find(parent[x]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[a] = b; return false;
	}
	else {
		return true; // 이미 부모가 같은 경우
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = i;

	int result = 0;
	int MAX = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (merge(a, b)) {
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
}