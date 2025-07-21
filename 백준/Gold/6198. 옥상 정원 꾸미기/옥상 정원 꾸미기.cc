#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	// 높이, 번호

	int height;
	vector<int> tower;
	for (int i = 0; i < n; i++) {
		cin >> height;
		tower.push_back(height);
	}
	stack<int> st;
	long long result = 0;
	for (int i = 0; i < n; i++) {
		height = tower[i];

		while (!st.empty() && st.top() <= height) {
			st.pop();
			result += st.size();
		}

		st.push(height);
	}
	while (!st.empty()) {
		st.pop();
		result += st.size();
	}
	cout << result;
}
