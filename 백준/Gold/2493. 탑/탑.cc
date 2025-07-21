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
	vector<int> result(n, 0);

	stack<pair<int, int>> st;

	int height;
	for (int i = 0; i < n; i++) {
		cin >> height;

		while (!st.empty() && st.top().first < height) {
			// 새로운 수신탑 발견(더 높은)
			// 이전의 수신탑들은 필요없다.
			st.pop();
		}

		if (!st.empty()) {
			result[i] = st.top().second;
		}

		st.push({ height,i + 1 });
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}
