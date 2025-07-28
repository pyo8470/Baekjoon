#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	int N; cin >> N;
	
	vector<pair<int, int>> cord(N);

	for (int i = 0; i < N; i++) {
		cin >> cord[i].first;
		cin >> cord[i].second;
	}

	sort(cord.begin(), cord.end(), [](pair<int, int> a, pair<int, int> b) {
		auto tup_a = tuple(a.second, a.first);
		auto tup_b = tuple(b.second, b.first);
		return tup_a < tup_b;
	});

	for (int i = 0; i < N; i++) {
		cout << cord[i].first << " " << cord[i].second << '\n';
	}
}
