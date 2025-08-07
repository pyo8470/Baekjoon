#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1001];


int F;
int find(int x) {
	if (parent[x] == x) return x; // 부모
	return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	 
	if (a != b) {
		parent[a] = b;
		return false;
	}
	return true;
}

struct edges
{
	int s;
	int e;
	int w;
};
vector<edges> vec; 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N; cin >> N;
	for (int i = 1; i < N; i++) {
		parent[i] = i;
	}
	
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		if (s == e) continue;
		vec.push_back({ s,e,w });
	}

	sort(vec.begin(), vec.end(), [](edges a, edges b) {
		return a.w < b.w;
		});

	int result = 0;
	for (int i = 0; i < vec.size(); i++) {
		int s = vec[i].s;
		int e = vec[i].e;
		int w = vec[i].w;
		if (!merge(s, e)) {
			result += w;
		}
	}
	cout << result;
}