#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
vector<int> parent;

string milks;
int N, M;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	
	cin >> milks;
	parent.resize(N + 1); for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		if (find(a) == find(b) || milks[a-1] != milks[b-1]) continue;
		merge(a, b);
		
		/*for (int p : parent) {
			cout << p << ' ';
		}
		cout << '\n';*/
	}
	string result = "";
	for (int i = 0; i < M; i++) {
		int a, b; char target;
		cin >> a >> b >> target;

		if (find(a) == find(b)) { // 같은 우류
			result += (milks[a-1] == target) ? '1' : '0';
		}
		else { // 두 그룹이 다른 우유
			result += '1';
		}
	}
	cout << result;
}
