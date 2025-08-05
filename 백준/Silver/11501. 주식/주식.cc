#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> price;
int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N; price.resize(N, 0);
		for (int i = 0; i < N; i++) cin >> price[i];

		long long answer = 0;
		int MAX = price[N-1];
		for (int i = N - 2; i >= 0; i--) {
			int current = price[i];
			//cout << current << " " << MAX << '\n';
			if (current < MAX) {
				answer += MAX - current;
			}
			else {
				MAX = current;
			}
		}
		cout << answer << '\n';
	}
}