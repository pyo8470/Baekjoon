#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int T;
int N, K;
int D[1001];
int target;

unordered_map<int, vector<int>> adjList;
unordered_map<int, int> DP;
unordered_set<int> visit;

void input() {

	adjList.clear();
	DP.clear();

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> D[i];
	}

	int x, y;
	for (int i = 0; i < K; ++i) {
		cin >> x >> y;
		adjList[y].push_back(x);
	}

	cin >> target;
}

int build(int cur_node) {

	if (DP.count(cur_node) > 0) return DP[cur_node];



	DP[cur_node] = 0;

	for (int child_node : adjList[cur_node]) {
		if (visit.count(child_node) > 0) continue;

		int ret = build(child_node);
		DP[cur_node] = max(DP[cur_node], ret);
	}

	DP[cur_node] += D[cur_node];
	return DP[cur_node];
}

int main() {

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		input();

		visit.insert(target);
		int answer = build(target);
		visit.erase(target);

		cout << answer << '\n';
	}

	return 0;
}