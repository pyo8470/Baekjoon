#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;
int parent[200002];
int u_size[200002];


int F;
map<string, int> MAP;
int find(int x) {
	if (parent[x] == x) return x; // 부모
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[a] = b;
		u_size[b] += u_size[a];
	}
}
void print() {
	for (int i = 0; i < MAP.size(); i++) {
		cout << parent[i] << ' ';
	} cout << '\n';
	for (int i = 0; i < MAP.size(); i++) {
		cout << u_size[i] << ' ';
	} cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> F;
		//이름 index
		MAP.clear();
		int index = 0;

		for (int i = 0; i < 2*F; i++) {
			parent[i] = i;
			u_size[i] = 1;
		}

		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			if (MAP.find(a) == MAP.end()) {
				MAP.insert({ a, index });
				index++;
			}
			if (MAP.find(b) == MAP.end()) {
				MAP.insert({ b, index });
				index++;
			}

			merge(MAP[a], MAP[b]);
			//print();
			cout << u_size[find(MAP[a])] << '\n';
		}
	}
}