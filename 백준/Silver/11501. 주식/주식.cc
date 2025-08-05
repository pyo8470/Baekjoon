#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> price;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N; price.resize(N, 0);
		for (int i = 0; i < N; i++) cin >> price[i];

		long long answer = 0;
		int MAX = price[N-1];
		for (int i = N - 2; i >= 0; i--) {
			int current = price[i];

			(current < MAX) ? answer += MAX - current : MAX = current;
		}
		cout << answer << '\n';
	}
}