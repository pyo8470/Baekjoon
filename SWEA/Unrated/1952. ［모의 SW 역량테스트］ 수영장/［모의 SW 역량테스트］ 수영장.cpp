#include <iostream>
#include <climits>
#include <vector>
using namespace std;
vector<int> month(13);
vector<int> dp(13);
int fee[4];

void print(vector<int> k) {
	for (int i = 1; i <= 12; i++) {
		cout << k[i] << ' ';
	}
	cout << '\n';
}
int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++) cin >> fee[i];
		for (int i = 1; i <= 12; i++) cin >> month[i];

		dp[0] = 0;  // 0월까지 비용은 0
		for (int m = 1; m <= 12; m++) {
			int day_cost = month[m] * fee[0];

			int monthly_cost = fee[1];

			dp[m] = min(dp[m - 1] + min(monthly_cost, day_cost), INT_MAX);

			if (m >= 3) {
				dp[m] = min(dp[m], dp[m - 3] + fee[2]);
			}
			dp[m] = min(dp[m], fee[3]);
		}
		cout << "#" << tc << " " <<dp[12] <<'\n';
	}
}