#include <iostream>
#include <queue>
#include <string>

using namespace std;


vector<int> arr;
vector<bool> visited;
int N;
int check_perm_cycle(int node) {
	if (visited[node] == true) return 1;
	
	visited[node] = true;
	return check_perm_cycle(arr[node - 1]);
}
int check_perm_cycle_rev(int node) {
	if (visited[node] == true) return 1;

	visited[node] = true;
	//cout << N - 1 - arr[node - 1] << '\n';
	return check_perm_cycle_rev(arr[N-node]);
}

int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);
	cin >> N; arr.assign(N, 0);
	for (int i = 0; i < N; i++) { cin >> arr[i]; }

	cout << N - 2 << " ";
	int cycle_asd = 0;
	int cycle_rev = 0;
	visited.assign(N + 1, false);
	for (int node : arr) {
		if (!visited[node]) cycle_asd += check_perm_cycle(node);
	}
	visited.assign(N + 1, false);
	for (int node : arr) {
		if (!visited[node]) cycle_rev += check_perm_cycle_rev(node);
	}
	cout << min(N - cycle_asd, N - cycle_rev);
}