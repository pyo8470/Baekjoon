#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		vector<int> arr(N + 1, 0);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		vector<bool> visited(N + 1, false);

		vector<vector<int>> cycles;
		for (int i = 1; i <= N; i++) {
			if (visited[i])
				continue;

			int start = arr[i];
			vector<int> temp;

			while (1) {
				temp.push_back(start);
				visited[start] = true;
				int next = arr[start];
				start = next;
				if (start == arr[i])
					break;
			}

			cycles.push_back(temp);
		}
		cout << cycles.size() << '\n';
	}

	return 0;
}
